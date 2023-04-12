#include "Infix_To_Postfix.h"
#include <sstream>
#include <cctype>
#include <iostream>

using namespace std;

// the string OPERATORS includes all operators handled
const string Infix_To_Postfix::OPERATORS = "+-*/%()[]{}";
// the array PRECEDENCE[] inludes the precedence associated with the operators
const int Infix_To_Postfix::PRECEDENCE[] = { 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5 };

//
string Infix_To_Postfix::convert(const string& expression) {
    postfix = "";
    while (!operator_stack.empty())
        operator_stack.pop();
    istringstream infix_tokens(expression);
    string next_token;
    // while loop iterates through the expression
    while(infix_tokens >> next_token) {
        // isalnum checks if element is a number or upper or lower case letter
        if (isalnum(next_token[0])) {
            // push number/letter to the postfix output variable
            cout << "push" << endl;
            postfix += next_token;
            postfix += " ";
        // if not a number or letter, check element with is_operator function
        } else if (is_operator(next_token[0])) {
            // if it is an operator, process the operator with function
            process_operator(next_token[0]);
        // if not a number, letter, or operator, throw error
        } 
    } // End while
    // Pop any remaining operators and append them to postfix
    cout << "Time to append operators" << endl;
    while (!operator_stack.empty()) {
        char op = operator_stack.top();
        operator_stack.pop();
        postfix += op;
        postfix += " ";
    }
    
    return postfix;
}

void Infix_To_Postfix::process_operator(char op) {
    // if operator stack is empty then simply push the operator to the stack
    if (operator_stack.empty() && precedence(op) < 3) {
        cout << "push " << op << " to operator_stack1" << endl;
        operator_stack.push(op);
        return;
    } 
    if (operator_stack.empty()) {
        return;
    } else {
        // if new operator is higher precedence...
        if (precedence(op) > precedence(operator_stack.top())) {
            // push the top of operator stack to postfix
            char oporig = operator_stack.top();
            operator_stack.pop();
            postfix += oporig;
            postfix += " ";
            // push the current operator onto the operator stack
            cout << "push " << op << " to operator_stack2" << endl;
            if (precedence(op) < 3)
                operator_stack.push(op);
        // if new operator is same or lower precedence
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
            if (precedence(op) < 3)
                operator_stack.push(op);
        }
    }
}

// member function to check whether parenthesis are balanced
bool Infix_To_Postfix::isBalanced(const string& expression) {
    // create an empty stack
    stack <char> stack;
    // for case where expression begins with closing parenthesis
    stack.push('a');
    // iterate through the expression
    for(int i = 0; i < expression.length(); i++) {
        string parenth = "({[";
        // for each expression element, loop through parenth to check if it is a 
        // type of parenthesis
        for (int j = 0; j < parenth.length(); j++) {
            if (expression[i] == parenth[j]) {
                // push the parenthesis to the stack
                stack.push(expression[i]);
                // move to next expression element
                break;                
            }
        }
        
        // if the stack is not empty, and expression element is not an opening
        // parenthesis, check if element is a closing parenthesis
        if (!stack.empty()) { 
            char c = stack.top();
           
            switch(expression[i]){
                // checks if expression element is closing parenthesis
                case ')':
                    stack.pop();
                    // if so, previous parenthesis must be a closing parenthesis
                    if(c != '(')
                        // if not, the expression is not balanced
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
    return true;
}






