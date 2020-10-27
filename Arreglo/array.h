#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <initializer_list>

template <typename TElem>
class Array {
public:
    Array(const std::initializer_list<TElem>& init);
    Array(int size);

    ~Array()
    { delete [] arr; }

    TElem& operator[](unsigned idx)
    { return arr[idx]; }

    Array& operator=(const Array& rhs);

    void print();
    int find(TElem element);
    int findMinIndex(int pos);

    TElem findMinElement()
    { return arr[findMinIndex(0)]; }
    
    void sort();

    int size()
    { return size_; }

private:
    int size_;
    TElem *arr;
};

#include "array.cpp"

#endif
