#ifndef _STACK_H
#define _STACK_H

template<typename T>
class Stack {
    int _top;
    int size;  
    T *arr;

    public:
        Stack(T _size) {
            arr = new T[_size];
            _top = -1;
        }

        void push(T data);
        T pop();
        T top();
        bool isFull();
        bool isEmpty();
};

#include "stack.cpp"

#endif
