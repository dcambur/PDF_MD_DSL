#include "iostream"
#include <string>

using namespace std;


struct Token {
    int tok_eof = -1;

    int tok_function = -2;
    int tok_render = -3;

    int tok_identifier = -4;
    int tok_number = -5;

    int tok_string_open = -6;
    int tok_string_close = -7;

    int tok_int_open = -8;
    int tok_int_close = -9;


    int tok_left_par = -10;
    int tok_right_par = -11;

    int tok_plus = -12;
    int tok_minus = -13;
    int tok_multiply = -14;
    int tok_divide = -15;

    int tok_greater = -16;
    int tok_less = -17;

    int tok_greater_or = -18;
    int tok_less_or = -19;

    int tok_equal = -20;
    int tok_not_equal = -21;

    int tok_assign = -22;

};

// global constants
static std::string IDENTIFIER_STR; // Filled in if tok_identifier
static double NUM_VAL; // Filled in if tok_number
static Token TOKENS;
