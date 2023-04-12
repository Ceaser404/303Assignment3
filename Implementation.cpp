#include "Infix_To_Postfix.h"
#include <sstream>
#include <cctype>
#include <iostream>

using namespace std;

const string Infix_To_Postfix::OPERATORS = "+-*/";
const int Infix_To_Postfix::PRECEDENCE[] = { 1, 1, 2, 2 };

string Infix_To_Postfix::convert(const string& expression) {
    postfix = "";
    while (!operator_stack.empty())
        operator_stack.pop();
    istringstream infix_tokens(expression);
    string next_token;
    while(infix_tokens >> next_token) {
        if (isalnum(next_token[0])) {
            cout << "push" << endl;
            postfix += next_token;
            postfix += " ";
        } else if (is_operator(next_token[0])) {
            cout << "is operator" << endl;
            process_operator(next_token[0]);
        } else {
            //throw "Unexpected Character Encountered";
        }
    } // End while
    // Pop any remaining operators and append them to postfix
    cout << "Time to append operators" << endl;
    while (!operator_stack.empty()) {
        char op = operator_stack.top();
        operator_stack.pop();
        postfix += op;
        postfix += " ";
        //operator_stack.pop();
    }
    return postfix;
}

void Infix_To_Postfix::process_operator(char op) {
    cout << "I am being used!!!!!!!!!" << endl;
    if (operator_stack.empty() || (op == '(')) {
        if (op == ')')
            throw "Unmatched close parenthesis";
        cout << "push " << op << " to operator_stack1" << endl;
        operator_stack.push(op);
    } else {
        if (precedence(op) > precedence(operator_stack.top())) {
            
            char oporig = operator_stack.top();
            operator_stack.pop();
            postfix += oporig;
            postfix += " ";
            
            cout << "push " << op << " to operator_stack2" << endl;
            operator_stack.push(op);
        } else {
        // Pop all stacked operators with equal
        // or higher precedence than op.
            while (!operator_stack.empty() && (operator_stack.top() != '(') && (precedence(op) <= precedence(operator_stack.top()))) {
                postfix += operator_stack.top();
                postfix += " ";
                operator_stack.pop();
            }
            if (op == ')') {
                if (!operator_stack.empty() && (operator_stack.top() == '(')) {
                    operator_stack.pop();
                } else {
                    throw "Unmatched close parentheses";
                }
            }
            operator_stack.push(op);
        }
    }
}

bool Infix_To_Postfix::isBalanced(const string& expression) {
    stack <char> stack;
    
    for(int i = 0; i < expression.length(); i++) {
        string parenth = "({[";
        for (int j = 0; j < parenth.length(); j++) {
            if (expression[i] == parenth[j]) {
                stack.push(expression[i]);
                
                break;                
            }
        }
        
        if (!stack.empty()) { 
            char c = stack.top();
        
            switch(expression[i]){
                case ')':
                    stack.pop();
                    if(c != '(')
                        return false;
                    break;
                case '}':
                    stack.pop();
                    if(c != '{')
                        return false;
                        
                    break; 
                case ']':
                    stack.pop();
                    if(c != '[')
                        return false;
                    break;
                    
                default:
                    break;
            }
        }
        
        
    }
    return stack.empty();
}








