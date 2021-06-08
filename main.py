from tokens import Tokens
from fpdf import FPDF

tokens = Tokens()


def parse(file_input):
    parse_status = 0
    # mapping is done via next structure [ [content1, [normal_tag1...normal_tagN], [single_tag1...single_tagN]]...]
    # arrays are fully sorted on parsing.
    text_to_function_map = []

    if not file_input:
        return -1, []

    with open(file_input, "r") as file_read:
        render_mode = True
        error_return = tokens.error, "", []
        parse_data = []
        render_string = ""

        file_name = ""

        while render_mode:
            char = file_read.read(1)

            # comment
            if char == "#":
                file_read.readline()
                continue

            # space
            if char == " ":
                continue

            # escape
            if char == "\n":
                continue

            if not char:
                break
            render_string += char

            # search mode

            if render_string == "render":
                char = file_read.read(1)

                # check on opening
                while True:
                    if char == "(":
                        break

                    elif char == " " or char == "\n":
                        char = file_read.read(1)
                        continue

                    else:
                        return error_return

                char = file_read.read(1)
                while True:
                    if char == ";":
                        char = file_read.read(1)
                        break

                    elif char == " " or char == "\n":
                        char = file_read.read(1)
                        continue

                    elif not char:
                        return error_return

                    else:
                        file_name += char
                        char = file_read.read(1)

                search_mode = True

                searcher = ""
                # stack is needed to check the balance between closures and openings
                function_stack = []
                # this one is for single tag methods
                single_stack = []

                # used to parse complex functions
                template_stack = []

                # searching is quite simple,
                # first we search for a function,
                # after we try to copy it into string fully
                # the copied part mapped with function elements start/end placement
                # do it for all possible placements
                # after this, mapped functions/text will be processed with pdf
                # if our text is bare(without any function), then the text will be processed by default pdf standards

                while search_mode:
                    function_search = ""
                    text_search = ""
                    closing_check = False

                    # this part handles block of tags + text
                    if char == "<":
                        """ part one, read  opening/closing function 
                        and check its existence """
                        while True:
                            # closing check
                            if char == "/":
                                if closing_check:
                                    break
                                else:
                                    closing_check = True

                                function_search = ""
                                while True:
                                    char = file_read.read(1)

                                    # no open functions in stack even if closing is met, means error
                                    if not function_stack:
                                        return error_return

                                    if not char:
                                        return error_return

                                    if function_search == function_stack[-1]:
                                        if template_stack:
                                            if function_search in template_stack[-1].keys():
                                                template_stack.pop()

                                        function_stack.pop()
                                        stack_popped = True

                                        break

                                    function_search += char

                                if stack_popped:
                                    break

                            if function_search in tokens.method_tokens:
                                function_stack.append(function_search)

                            # Logic is next
                            # we will shove complex tag into function stack for tag balance check
                            # after this we will read and parse complex function in its entirety
                            # parsed data will be sent later on to analyze complex functions while converting to pdf
                            elif function_search in tokens.complex_tokens:
                                function_stack.append(function_search)
                                while True:
                                    char = file_read.read(1)

                                    if not char:
                                        return error_return

                                    if char == ">":
                                        break

                                    function_search += char

                                # parsing complex functions
                                # it will be parsed into array of {tag: [[attrib_name, attrib_value]...]}
                                function_divided = function_search.split(" ")
                                if function_divided[0] in tokens.complex_tokens:
                                    template = {function_divided[0]: []}
                                    for ele in function_divided[1:]:
                                        template[function_divided[0]].append(ele.split("="))
                                    template_stack.append(template)

                            elif function_search in tokens.single_method_tokens:
                                if not text_to_function_map:
                                    text_to_function_map.append([[], [], [function_search]])
                                else:
                                    text_to_function_map[-1][2].append(function_search)
                                break

                            """Part 2. Check on next function/simple text"""
                            if char == ">":
                                char = file_read.read(1)
                                if char == "<":
                                    function_search = ""
                                    continue
                                else:
                                    # text check
                                    if char == '"':
                                        while True:
                                            char = file_read.read(1)

                                            if char == '"':
                                                char = file_read.read(1)
                                                break

                                            text_search += char

                                            if not char:
                                                return error_return

                                        text_to_function_map.append([text_search, function_stack.copy(),
                                                                     single_stack.copy(), template_stack.copy()])

                                        text_search = ""

                                    function_search = ""
                                    if char == "\n":
                                        continue

                                    if char == " ":
                                        continue

                            if not char:
                                return error_return

                            char = file_read.read(1)
                            if char != "<" and char != ">":
                                function_search += char
                            else:
                                function_search = ""

                            if char == "\n":
                                break

                            if char == " ":
                                continue

                    # this part is for handling other case, no tags, text only blocks
                    elif char == '"':
                        while True:
                            char = file_read.read(1)
                            if char == '"':
                                text_to_function_map.append([searcher, function_stack.copy(),
                                                             single_stack.copy(), template_stack.copy()])
                                searcher = ""
                                break

                            searcher += char

                            if not char:
                                return error_return

                    # block handling stops at render closure.
                    elif char == ")":
                        parse_data.append([parse_status, file_name, text_to_function_map])
                        render_string = ""
                        file_name = ""
                        text_to_function_map = []
                        break

                    # check on file end
                    if not char:
                        return error_return

                    char = file_read.read(1)

    return parse_data


def render(data_input):
    pdf = FPDF()
    pdf.add_page()
    for content, function_tags, single_functions, complex_functions in data_input[2]:
        # font configs
        font_size = 14
        font_family = 'courier'
        font_style = ""
        font_color = (0, 0, 0)

        page = 0

        align = "J"

        for conf in complex_functions:
            for tag, attribute_pairs in conf.items():
                if tag == "font":
                    for pair in attribute_pairs:
                        if pair[0] == "family":
                            if pair[1] in pdf.core_fonts.keys():
                                font_family = pair[1]

                        elif pair[0] == "size":
                            if pair[1].isdigit():
                                font_size = int(pair[1])

                        elif pair[0] == "color":

                            if pair[1] == "red":
                                font_color = (255, 0, 0)

                            elif pair[1] == "green":
                                font_color = (0, 255, 0)

                            elif pair[1] == "blue":
                                font_color = (0, 0, 255)

                            elif pair[1] == "black":
                                font_color = (0, 0, 0)

                            elif pair[1] == "white":
                                font_color = (255, 255, 255)

                        else:
                            print(f"ConvertError: {font_color} is not color!")
                if tag == "pagination":
                    for pair in attribute_pairs:
                        if pair[0] == "page" and pair[1].isdigit():
                            page = int(pair[1])

        for tag in function_tags:
            if tag == "bold":
                font_style = "B"
            if tag == "italic":
                font_style = "I"
            if tag == "underline":
                font_style = "U"

            if tag == "center":
                align = "C"
            if tag == "left":
                align = "L"
            if tag == "right":
                align = "R"
            if tag == "justify":
                align = "J"

            if tag == "sub":
                content = f"{'<sub>'}{content}\u2082"
            if tag == "sup":
                content = f"{content}\u2082"
        pdf.set_font(font_family, font_style, font_size)
        if font_color:
            pdf.set_text_color(font_color[0], font_color[1], font_color[2])

        if page != 0:
            pages_total = len(pdf.pages.keys())
            if pages_total < page:
                while pages_total < page:
                    pdf.add_page()
                    pages_total += 1
                pdf.page = pages_total
        pdf.multi_cell(0, pdf.font_size, content, 0, align=align)
        pdf.ln()

        for single_tag in single_functions:
            if single_tag == "br":
                pdf.ln()

            else:
                print(f"ConvertError: Tag {single_tag} is Wrong!")

    pdf.output(data_input[1])


data = parse("C:/Users/dcamb/PycharmProjects/python_dsl/test1")
state = False
for render_data in data:
    if render_data[0] != -1:
        render(render_data)

    else:
        print(f"\nProcess finished with status {render_data[0]}")
        state = True
        break

