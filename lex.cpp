// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.
#include "iostream"
#include <string>
#include "tokens.h"

using namespace std;

// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.

// skip all found whitespaces while iterating through chars
static int skipWhitespaces(int last_char) {
    while (isspace(last_char))
        last_char = getchar();
    return last_char;
}

// skip till not new line or end of file
static int skipLine(int last_char) {
    // Comment until end of line.
    do
        last_char = getchar();
    while (last_char != EOF && last_char != '\n' && last_char != '\r');

    return last_char;
}

// get word from input stream
static string getWord(int& last_char) {
    static string word;
    word = (char)last_char;
    while (isalnum((last_char = getchar())))
        word += (char)last_char;

    return word;
}

// get command status based on given command
static int getCommandStatus(const string& command) {
    if (command == "function")
        return TOKENS.tok_function;
    if (command == "render")
        return TOKENS.tok_render;

    return TOKENS.tok_identifier;

}

// get number from the input stream
static double getNumber(int last_char) {
    string num_str;
    do {
        num_str += (char)last_char;
        last_char = getchar();
    } while (isdigit(last_char) || last_char == '.');

    return strtod(num_str.c_str(), nullptr);
}

/// getToken() - returns the next token from standard input.
static int getToken() {
    static int last_char = ' ';

    // Skip any whitespace.
    last_char = skipWhitespaces(last_char);

    if (last_char == '>' && cin.peek() == '=')
        return TOKENS.tok_greater_or;
    if (last_char == '>')
        return TOKENS.tok_greater;

    if (last_char == '=' && cin.peek() == '=')
        return TOKENS.tok_equal;
    if (last_char == '=')
        return TOKENS.tok_assign;

    if (last_char == '!' && cin.peek() == '=')
        return TOKENS.tok_not_equal;

    if (last_char == '(')
        return TOKENS.tok_left_par;
    if (last_char == ')')
        return TOKENS.tok_right_par;

    if (last_char == '+')
        return TOKENS.tok_plus;
    if (last_char == '-')
        return TOKENS.tok_minus;
    if (last_char == '*')
        return TOKENS.tok_multiply;
    if (last_char == '/')
        return TOKENS.tok_divide;

    // check if input was defined as command
    if (isalpha(last_char)) { // identifier: [a-zA-Z][a-zA-Z0-9]*
        IDENTIFIER_STR = getWord(last_char);
        return getCommandStatus(IDENTIFIER_STR);
    }

    // check if input is defined as data type or logical operator
    if (last_char == '<') {
        // check if next value in stream is start of a data type opening
        if (isalpha(cin.peek())) {

            IDENTIFIER_STR = getWord(last_char);
            IDENTIFIER_STR += (char)last_char;
            if (IDENTIFIER_STR == "<string>") {
                return TOKENS.tok_string_open;
            }

            if (IDENTIFIER_STR == "<int>") {
                return TOKENS.tok_int_open;
            }
        }
        // check if next value in stream is a part of data type closing
        else {
            IDENTIFIER_STR = (char)last_char;
            last_char = getchar();
            if (last_char == '/') {
                IDENTIFIER_STR += getWord(last_char);
                IDENTIFIER_STR += (char)last_char;

                if (IDENTIFIER_STR == "</string>") {
                    return TOKENS.tok_string_close;
                }

                if (IDENTIFIER_STR == "</int>") {
                    return TOKENS.tok_int_close;
                }

            }

            // we can have only one other variant to compare , <=,
            if (last_char == '=') {
                return TOKENS.tok_less_or;
            }

            // Return token for < operator that  was already found
            return TOKENS.tok_less;
        }
    }
    // check if input is defined as number
    if (isdigit(last_char) || last_char == '.') { // Number: [0-9.]+
        NUM_VAL = getNumber(last_char);
        return TOKENS.tok_number;
    }

    // check if input is defined as comment and get next token if not EOF
    if (last_char == '#') {
        last_char = skipLine(last_char);

        if (last_char != EOF)
            return getToken();
    }

    // Check for end of file.  Don't eat the EOF.
    if (last_char == EOF)
        return TOKENS.tok_eof;

    // Otherwise, just return the character as its ascii value.
    int ThisChar = last_char;
    last_char = getchar();
    return ThisChar;
}

int main() {
    cout << "Enter lexeme: ";
    cout << getToken();
    return 0;
}