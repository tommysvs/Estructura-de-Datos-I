#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <initializer_list>

template <typename TElem>
class Array {
public:
    Array(const std::initializer_list<TElem>& init);
    Array(int size);

    ~Array() { 
        delete [] arr; 
    }

    TElem& operator[](unsigned idx) { 
        return arr[idx]; 
    }

    Array& operator=(const Array& rhs);

    void print() const;
    int find(TElem element) const;
    int findMinIndex(int pos) const;
    int findMaxIndex(int pos) const;

    TElem findMinElement() const { 
        return arr[findMinIndex(0)]; 
    }

    TElem findMaxElement() const {
        return arr[findMaxIndex(0)];
    }
    
    void sort();
    void insertionSort();

    int size() const { 
        return size_; 
    }

private:
    void copyFrom(const Array& other);

private:
    int size_;
    TElem *arr;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
    arr.print();

    return out;
}

#include "array.cpp"

#endif
