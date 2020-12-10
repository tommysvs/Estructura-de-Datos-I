#ifndef _STACK_H
#define _STACK_H

template <typename T>
class Stack {
    private:
        T *arr;
        int size;
        int top;    

    public:
        Stack();

        void push(T data);
        T pop();
        bool isFull();
        bool isEmpty();
};

#include "stack.cpp"

#endif