#include "Infix_To_Postfix.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Infix_To_Postfix infix_to_postfix;
    cout <<
        "Enter expressions to be converted, or press Return when done\n";
    string expression;
    // gather a line of input from the user using getline
    while (getline(cin, expression)) {
        // handle exception of no input
        if (expression == "") break;
        // call member function .isBalanced, which returns a bool
        try {
            if(infix_to_postfix.isBalanced(expression))
                cout << "Parentheses are balanced\n";
            else
                cout << "Expression is invalid\n";
            // convert expression from infix to postfix and output to user
            string result = infix_to_postfix.convert(expression);
            cout << "== " << result << endl;
            break;
        } catch (char* ex) {
            cout << "Syntax Error: " << endl;
        }
        cout << "Enter next expression: ";
    }
}
