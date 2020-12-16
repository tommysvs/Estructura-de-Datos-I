#ifndef _SORT_H
#define _SORT_H

#include <list>
#include <algorithm>
#include <iterator>

// Sort a list using selection sort
template<typename TElem>
void sortList(std::list<TElem>& lst) {
    lst.sort();
}

#endif