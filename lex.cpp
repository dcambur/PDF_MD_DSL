#include "iostream"
#include <string>
#include "string.h"
#include "lexer.h"
  
using namespace std;
  
// driver code
int main()
{
    char str[100];

    gets_s(str);

    while (true){

        cout << "Token: " << GetToken(str) << "\n";
        
        gets_s(str);

    }
    
    return 0;
}