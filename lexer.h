#include "iostream"
#include <string>
#include "tokens.h"

using namespace std;

// проверка на ключевые слова
// типы данных, слова для структур данных, значения типа boolean, математические знаки, скобки
// **********************************************************************************************

int identifyDatatype (char str[]){

    if (strcmp(str, "<string>") == 0) 
    {
        return TOKENS.tok_string_open;
    } 
    else if (strcmp(str, "</string>") == 0)
    {
        return TOKENS.tok_string_close;
    } 
    else if (strcmp(str, "<int>") == 0) 
    {
        return TOKENS.tok_int_open;
    } 
    else if (strcmp(str, "</int>") == 0)
    {
        return TOKENS.tok_int_close;
    }
    else if (strcmp(str, "<char>") == 0) 
    {
        return TOKENS.tok_char_open;
    } 
    else if (strcmp(str, "</char>") == 0)
    {
        return TOKENS.tok_char_close;
    }
    else if (strcmp(str, "<bool>") == 0) 
    {
        return TOKENS.tok_bool_open;
    } 
    else if (strcmp(str, "</bool>") == 0)
    {
        return TOKENS.tok_bool_close;
    }
    else if (strcmp(str, "<float>") == 0) 
    {
        return TOKENS.tok_float_open;
    } 
    else if (strcmp(str, "</float>") == 0)
    {
        return TOKENS.tok_float_close;
    }
    else if (strcmp(str, "<array>") == 0) 
    {
        return TOKENS.tok_array_open;
    } 
    else if (strcmp(str, "</array>") == 0)
    {
        return TOKENS.tok_array_close;
    }

    return 0;
}

int identifyKeyWord(char str[]){

    if (strcmp(str, "if") == 0)
    {
        return TOKENS.tok_if;
    }
    else if (strcmp(str, "else") == 0)
    {
        return TOKENS.tok_else;
    }
    else if (strcmp(str, "for") == 0)
    {
        return TOKENS.tok_for;
    }
    else if (strcmp(str, "do") == 0)
    {
        return TOKENS.tok_do;
    }
    else if (strcmp(str, "return") == 0)
    {
        return TOKENS.tok_return;
    }
    else if (strcmp(str, "while") == 0)
    {
        return TOKENS.tok_while;
    }
    else if (strcmp(str, "and") == 0)
    {
        return TOKENS.tok_and;
    }
    else if (strcmp(str, "or") == 0)
    {
        return TOKENS.tok_or;
    }
    else if (strcmp(str, "not") == 0)
    {
        return TOKENS.tok_not;
    }
    else if (strcmp(str, "true") == 0)
    {
        return TOKENS.tok_true;
    }
    else if (strcmp(str, "false") == 0)
    {
        return TOKENS.tok_false;
    }

    return 0;
}

int identifySign(char str[]){
    if (strcmp(str, "<") == 0)
    {
        return TOKENS.tok_less;
    }
    else if (strcmp(str, "<=") == 0)
    {
        return TOKENS.tok_less_or;
    }
    else if (strcmp(str, ">") == 0)
    {
        return TOKENS.tok_greater;
    }
    else if (strcmp(str, ">=") == 0)
    {
        return TOKENS.tok_greater_or;
    }
    else if (strcmp(str, "=") == 0)
    {
        return TOKENS.tok_assign;
    }
    else if (strcmp(str, "==") == 0)
    {
        return TOKENS.tok_equal;
    }
    else if (strcmp(str, "!=") == 0)
    {
        return TOKENS.tok_not_equal;
    }
    else if (strcmp(str, "+") == 0)
    {
        return TOKENS.tok_plus;
    }
    else if (strcmp(str, "++") == 0)
    {
        return TOKENS.tok_increment;
    }
    else if (strcmp(str, "-") == 0)
    {
        return TOKENS.tok_minus;
    }
    else if (strcmp(str, "--") == 0)
    {
        return TOKENS.tok_decrement;
    }
    else if (strcmp(str, "->") == 0)
    {
        return TOKENS.tok_derivate;
    }
    else if (strcmp(str, "*") == 0)
    {
        return TOKENS.tok_multiply;
    }
    else if (strcmp(str, "/") == 0)
    {
        return TOKENS.tok_divide;
    }
    else if (strcmp(str, "(") == 0)
    {
        return TOKENS.tok_left_par;
    }
    else if (strcmp(str, ")") == 0)
    {
        return TOKENS.tok_right_par;
    }
    else if (strcmp(str, "{") == 0)
    {
        return TOKENS.tok_left_brace;
    }
    else if (strcmp(str, "}") == 0)
    {
        return TOKENS.tok_right_brace;
    }
    else if (strcmp(str, "[") == 0)
    {
        return TOKENS.tok_left_bracket;
    }
    else if (strcmp(str, "]") == 0)
    {
        return TOKENS.tok_right_bracket;
    }
    else if (strcmp(str, ".") == 0)
    {
        return TOKENS.tok_dot;
    }
    else if (strcmp(str, ",") == 0)
    {
        return TOKENS.tok_comma;
    }

    return 0;
}

// ********************************************************************************************

// проверка на токены, имеющие пользовательское значение
// числа, "строки", 'символы'
// ********************************************************************************************

int dfa = 0;

// Проверяет, если текущий символ - цифра
bool Number(char c)
{
    for (int i = 0; i <= 9; i++){
        if (c == i+48){
            return true;
        }
    }

    return false;
}

// Проверяет, если текущий символ - буква a-z A-Z
bool Character(char c)
{
    for (int i = 0; i <= 26; i++){
        if (c == i+65){
            return true;
        }
    }

    for (int i = 0; i <= 26; i++){
        if (c == i+97){
            return true;
        }
    }

    return false;
}

// Проверяет, если текущий символ принадлежит ASCII таблице в диапазоне 32 - 126
bool ASCII(char c){
    for (int i = 0; i <= 94; i++){
        if (c == i+32){
            return true;
        }
    }

    return false;
}


// Функции состояний

void start(char c)
{
    if (c == '0'){
        dfa = 2;
    } else if (Number(c)){
        dfa = 1;
    } else if (c == '\''){
		dfa = 44;
	} else if (c == '\"'){
		dfa = 47;
	} else if (c == '#'){
		dfa = 49;
	} else if (Character(c)){
        dfa = 52;
    }

    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}
  

void state1(char c)
{
    if (Number(c)) {
        dfa = 1;
    } else if (c == '.'){
        dfa = 3;
    }
    
    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}
  

void state2(char c)
{
    if (c == '.') {
        dfa = 3;
    }
    
    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}
  

void state3(char c)
{
    if (Number(c)) {
        dfa = 4;
    }
    
    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}
  

void state4(char c)
{
    if (Number(c)) {
        dfa = 4;
    }
    
    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}

void state44(char c)
{
    if (ASCII(c)) {
        dfa = 45;
    }

    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}

void state45(char c)
{
    if (c == '\'') {
        dfa = 46;
    } 

    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}

void state47(char c)
{
    if (c == '\"') {
        dfa = 48;
    } else if (ASCII(c)) {
		dfa = 47;
	}

    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}

void state49(char c)
{
    if (ASCII(c)) {
        dfa = 50;
    }

    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}

void state50(char c) //добавлено состояние после первого дебага
{
    if (ASCII(c)) {
        dfa = 50;
    } 

    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}

void state52(char c)
{
    if (Number(c)) {
        dfa = 52;
    } else if (Character(c)){
        dfa = 52;
    }

    // -1 is used to check for any invalid symbol
    else {
        dfa = -1;
    }
}

int GetToken(char str[]){

    if (identifyDatatype(str) != 0){
        return identifyDatatype(str);
    } else if (identifyKeyWord(str) != 0){
        return identifyKeyWord(str);
    } else if (identifySign(str) != 0){
        return identifySign(str);
    } else {

        int i, len = strlen(str);

        for (i = 0; i < len; i++) {
        if (dfa == 0) // start symbol
            start(str[i]);
  
        else if (dfa == 1) // num
            state1(str[i]);
  
        else if (dfa == 2) // num
            state2(str[i]);
  
        else if (dfa == 3) // num
            state3(str[i]);
  
        else if (dfa == 4) // num
            state4(str[i]);

        else if (dfa == 44) // char
            state44(str[i]);

        else if (dfa == 45) // char
            state45(str[i]);

        else if (dfa == 47) // string
            state47(str[i]);

        else if (dfa == 49) // comments
            state49(str[i]);

        else if (dfa == 50) // comments
            state50(str[i]);

        else if (dfa == 52) // variable
            state52(str[i]);
        }

        switch (dfa)
        {
        case 1:
            dfa = 0;
            return TOKENS.tok_number_int;
            break;
        case 2:
            dfa = 0;
            return TOKENS.tok_number_int;
            break;
        case 4:
            dfa = 0;
            return TOKENS.tok_number_float;
            break;
        case 46:
            dfa = 0;
            return TOKENS.tok_char;
            break;
        case 48:
            dfa = 0;
            return TOKENS.tok_string;
            break;
        case 50:
            dfa = 0;
            return TOKENS.tok_comment;
            break;
        case 52:
            dfa = 0;
            return TOKENS.tok_identifier;
            break;
        default:
            dfa = 0;
            break;
        }

    }

    return 0;
}
