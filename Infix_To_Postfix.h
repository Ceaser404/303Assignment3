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
        string convert(const string& expression);
        bool isBalanced(const string& expression);
    private:
        void process_operator(char op);
        
        bool is_operator(char ch) const {
            cout << "operators" << endl;
            return OPERATORS.find(ch) != string::npos;
        }
        
        int precedence(char op) const {
            return PRECEDENCE[OPERATORS.find(op)];
        }
        
        static const string OPERATORS;
        static const int PRECEDENCE[];
        #ifdef USEKW
        KW::stack<char> operator_stack;
        #else
        stack<char> operator_stack;
        #endif
        string postfix;
};

#endif