#include <iostream>
#include "stack.h"

template<typename T>
Stack<T>::Stack() {
    size = 5;
    arr = new T[size];
    top = -1;
}

template<typename T>
void Stack<T>::push(T data) {
    arr[++top] = data;
}

template<typename T>
T Stack<T>::pop() {
    return arr[top--];
}

template<typename T>
bool Stack<T>::isFull() {
    return top == size - 1;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return top == -1;
}