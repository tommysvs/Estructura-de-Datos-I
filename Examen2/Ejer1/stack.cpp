#include <iostream>

template<typename T>
void Stack<T>::push(T data) {
    if(isFull())
        throw 1;
    else
        arr[++_top] = data;
}

template<typename T>
T Stack<T>::pop() {
    if(isEmpty()) 
        throw 1;
    else
        return arr[_top--];
}

template<typename T>
T Stack<T>::top() {
    return arr[_top];
}

template<typename T>
bool Stack<T>::isFull() {
    return _top == size - 1;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return _top < 0;
}