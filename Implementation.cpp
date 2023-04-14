#include "Infix_To_Postfix.h"
#include <sstream>
#include <cctype>
#include <iostream>

using namespace std;

// the string OPERATORS includes all operators handled
const string Infix_To_Postfix::OPERATORS = "+-*/%()[]{}";
// the array PRECEDENCE[] inludes the precedence associated with the operators
const int Infix_To_Postfix::PRECEDENCE[] = { 1, 1, 2, 2, 2, 3, 4, 5, 6, 7, 8 };

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
            //cout << "push" << endl;
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
        if (precedence(operator_stack.top()) < 3) {
            postfix += operator_stack.top();
            postfix += " ";
            operator_stack.pop();                
        } else {
            operator_stack.pop();
        }       
    }
    
    return postfix;
}

void Infix_To_Postfix::process_operator(char op) {
    // if operator stack is empty then simply push the operator to the stack
    if (operator_stack.empty()) {
        //cout << "push " << op << " to operator_stack1" << endl;
        operator_stack.push(op);
        return;
    } 
    // if new operator is higher precedence and not parenthesis
    if (precedence(op) > precedence(operator_stack.top()) && precedence(op) < 3) {
        // push the current operator onto the operator stack
        operator_stack.push(op);
        
    // if new operator is higher precedence and parenthesis
    } else if (precedence(op) > precedence(operator_stack.top()) && precedence(op) > 2){
        // if operator is opening parenthesis
        if (precedence(op)%2 == 1) {
            operator_stack.push(op);
            return;
        // handles if closing parenthesis
        } else {
            do {
            // appends and pops operator within parenthesis
            if (precedence(operator_stack.top()) < 3) {
                postfix += operator_stack.top();
                postfix += " ";
                operator_stack.pop(); 
            // removes opening parenthesis
            } else 
                operator_stack.pop();
            }
            // continue running until another closing parenthesis 
            while (operator_stack.top()%2 == 0 || operator_stack.top() < 3);
        }
    // if current operator has lower or equal precedence than top of stack
    } else {
        // if top of stack is a parenthesis
        if ((precedence(op) < precedence(operator_stack.top())) && precedence(operator_stack.top()) > 2) {
            operator_stack.push(op);
            return;
        // if precedence is equal or top of stack is not parenthesis
        } else {
            if (precedence(operator_stack.top()) < 3) {
                postfix += operator_stack.top();
                operator_stack.pop();     
                operator_stack.push(op);
                postfix += " ";
            } else {
                operator_stack.pop();
                operator_stack.push(op);
            }            
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
    stack.pop();
    if (!stack.empty())
        return false;
    return true;
}




