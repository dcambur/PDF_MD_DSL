#include "iostream"
#include <string>
#include "string.h"
#include "lexer.h"
#include <fstream>
#include <cstring>
  
using namespace std;
  
// driver code
int main()
{
    ifstream MyReadFile("test.txt");
    ofstream tokens;
    tokens.open("tokens.txt");
    string text;

    while (getline(MyReadFile, text)) {
        char str[100];
        strcpy(str, text.c_str());
        tokens<<text<<" -> "<< GetToken(str) << "\n";
    }

    tokens.close();
    return 0;
}