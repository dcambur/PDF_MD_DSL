#include "iostream"
#include <string>

using namespace std;

struct Token {
    int tok_eof = -1;

    int tok_function = -2;
    int tok_render = -3;

    int tok_if = -4;
    int tok_else = -5;
    int tok_do = -6;
    int tok_return = -7;
    int tok_for = -8;
    int tok_while = -9;

    int tok_identifier = -10;
    int tok_number_int = -11;

    int tok_string_open = -12;
    int tok_string_close = -13;

    int tok_int_open = -14;
    int tok_int_close = -15;

    int tok_float_open = -16;
    int tok_float_close = -17;

    int tok_array_open = -18;
    int tok_array_close = -19;

    int tok_bool_open = -20;
    int tok_bool_close = -21;
    
    int tok_char_open = -22;
    int tok_char_close = -23;

    int tok_left_par = -24;
    int tok_right_par = -25;

    int tok_plus = -26;
    int tok_minus = -27;
    int tok_multiply = -28;
    int tok_divide = -29;

    int tok_greater = -30;
    int tok_less = -31;

    int tok_greater_or = -32;
    int tok_less_or = -33;

    int tok_equal = -34;
    int tok_not_equal = -35;

    int tok_assign = -36;

    // ***************

    int tok_and = -37;
    int tok_or = -38;
    int tok_not = -39;
    int tok_true = -40;
    int tok_false = -41;
    int tok_left_brace = -42;
    int tok_right_brace = -43;
    int tok_left_bracket = -44;
    int tok_right_bracket = -45;
    int tok_dot = -46;
    int tok_comma = -47;
    int tok_increment = -48;
    int tok_decrement = -49;
    int tok_derivate = -50;
    int tok_number_float = -51;
    int tok_char = -52;
    int tok_string = -53;
    int tok_comment = -54;

    int tok_else_if = -55;
    int tok_bool = -56;

};

// global constant TOKENS
static Token TOKENS;

