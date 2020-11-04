#include <sstream>
#include "array.h"

template<typename TElem>
Array<TElem>::Array(const std::initializer_list<TElem>& init)
: size_ (init.size())
{
    arr = new TElem[size_];

    int index = 0;
    for (auto elem : init)
    {
        arr[index++] = elem;
    }
}

template<typename TElem>
Array<TElem>::Array(int size)
: size_ (size)
{
    arr = new TElem[size_];

    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

template <typename TElem>
void Array<TElem>::copyFrom(const Array& other)
{
    size_ = other.size_;
    arr = new TElem[size_];

    for (int i = 0; i < size_; i++)
    {
        arr[i] = other.arr[i];
    }
}

template<typename TElem>
Array<TElem>& Array<TElem>::operator=(const Array<TElem>& rhs)
{
    delete [] arr;

    copyFrom(rhs);
    return *this;
}

template<typename TElem>
std::string Array<TElem>::toString() const
{
    std::ostringstream out;

    out << "[";
    bool first = true;

    for (int i = 0; i < size_; i++)
    {
        if (first) first = false;
        else out << ",";

        out << arr[i];
    }
    out << "]";

    return out.str();
}

template<typename TElem>
bool Array<TElem>::isSorted() const
{
    int j;

    for(int i = 0; i < size_; i++) {
        j = size_;

        if(arr[i] > arr[i + 1] && i + 1 < j)
            return false;
    }

    return true;
}

template<typename TElem>
void Array<TElem>::reverse()
{
    int j;
    TElem temp;

    for(int i = 0; i < size_/2; i++) {
        j = size_;
        temp = arr[i];
        arr[i] = arr[j - i - 1];
        arr[j - i - 1] = temp;
    }
}