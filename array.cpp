#include <iostream>
#include "array.h"

template<typename TElem>
Array<TElem>::Array(const std::initializer_list<TElem>& init) : size_ (init.size()) {
    arr = new TElem[size_];

    int index = 0;
    
    for (auto elem : init)
        arr[index++] = elem;
}

template<typename TElem>
Array<TElem>::Array(int size) : size_ (size) {
    arr = new TElem[size_];

    for (int i = 0; i < size; i++)
        arr[i] = 0;
}

template<typename TElem>
Array<TElem>& Array<TElem>::operator=(const Array<TElem>& rhs) {
    delete [] arr;

    size_ = rhs.size_;
    arr = new TElem[size_];

    for (int i = 0; i < size_; i++)
        arr[i] = rhs.arr[i];

    return *this;
}

template<typename TElem>
int Array<TElem>::find(TElem element) {
    for (int i = 0; i < size_; i++) {
        if (arr[i] == element)
            return i;
    }

    return -1;
}

template<typename TElem>
int Array<TElem>::findMinIndex(int pos) {
    int min = pos;
    for (int i = pos + 1; i < size_; i++) {
        if (arr[i] < arr[min])
            min = i;
    }

    return min;
}

// Selection Sort
template<typename TElem>
void Array<TElem>::sort() {
    for (int i = 0; i < size_; i++) {
        int idx = findMinIndex(i);
        TElem temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}

template<typename TElem>
void Array<TElem>::print() {
    std::cout << "[ ";
    bool first = true;

    for (int i = 0; i < size_; i++) {
        if (first) 
            first = false;
        else 
            std::cout << ", ";

        std::cout << arr[i];
    }

    std::cout << " ]";
}