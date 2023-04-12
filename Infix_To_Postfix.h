#ifndef INFIX_TO_POSTFIX_H_
#define INFIX_TO_POSTFIX_H_
//#include "Syntax_Error.h"
#include <string>
#ifdef USEKW
#include "stack.h"
#else
#include <stack>
#include <iostream>
#endif

using namespace std;

class Infix_To_Postfix {
    public:
        // converts function from infix to postfix
        string convert(const string& expression);
        // checks if expression parenthesis are balanced
        bool isBalanced(const string& expression);
    private:
        // processes the operators and parenthesis for convert function
        void process_operator(char op);
        // checks if character is an operator
        bool is_operator(char ch) const {
            return OPERATORS.find(ch) != string::npos;
        }
        // checks the precedence of operators to decide whether to push to stack
        int precedence(char op) const {
            return PRECEDENCE[OPERATORS.find(op)];
        }
        // string of characters that we consider operators
        static const string OPERATORS;
        // keeps track of the order of prededence of the operators
        static const int PRECEDENCE[];
        #ifdef USEKW
        // define data type for operator_stack
        KW::stack<char> operator_stack;
        #else
        stack<char> operator_stack;
        #endif
        string postfix;
};

#endif
