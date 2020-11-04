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
int Array<TElem>::find(TElem element) const {
    for (int i = 0; i < size_; i++) {
        if (arr[i] == element)
            return i;
    }

    return -1;
}

template<typename TElem>
int Array<TElem>::findMinIndex(int pos) const {
    int min = pos;
    for (int i = pos + 1; i < size_; i++) {
        if (arr[i] < arr[min])
            min = i;
    }

    return min;
}

template<typename TElem>
int Array<TElem>::findMaxIndex(int pos) const {
    int max = pos;
    for(int i = pos + 1; i < size_; i++) {
        if(arr[i] > arr[max])
            max = i;
    }

    return max;
}

// Selection sort
template<typename TElem>
void Array<TElem>::sort() {
    for (int i = 0; i < size_; i++) {
        int idx = findMinIndex(i);
        TElem temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}

// Insertion sort
template<typename TElem>
void Array<TElem>::insertionSort() {
    int j;

    for(int i = 0; i < size_; i++) {
        j = i;

        while(j > 0 && arr[j - 1] > arr[j]) {
            TElem temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;

            j--;
        }
    }
}

template<typename TElem>
void Array<TElem>::print() const {
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

template<typename TElem>
void Array<TElem>::copyFrom(const Array& other) {
    size_ = other.size_;
    arr = new TElem[size_];

    for(int i = 0; i < size_; i++)
        arr[i] = other.arr[i];
}
