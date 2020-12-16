#ifndef _STACK_H
#define _STACK_H

#define MAX 1000

template <typename T>
class Stack {
    public:
        T arr[MAX];
        int _top;    

    public:
        Stack() {
           _top = -1;
        }

        void push(T data);
        T pop();
        T top();
        bool isEmpty();

        T prec(char c);
        bool isOperator(char c);
        std::string infixToPostfix(std::string exp);
        T evaluatePostfix(std::string exp);
};

#include "stack.cpp"

#endif