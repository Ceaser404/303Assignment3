#include "Infix_To_Postfix.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Infix_To_Postfix infix_to_postfix;
    cout <<
        "Enter expressions to be converted, or press Return when done\n";
    string expression;
    while (getline(cin, expression)) {
        if (expression == "") break;
        try {
            if(infix_to_postfix.isBalanced(expression))
                cout << "Parentheses are balanced\n";
            else
                cout << "Expression is invalid\n";
            string result = infix_to_postfix.convert(expression);
            cout << "== " << result << endl;
        } catch (char* ex) {
            cout << "Syntax Error: " << endl;
        }
        cout << "Enter next expression: ";
    }
}