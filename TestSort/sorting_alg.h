#ifndef _SORTING_ALG_H
#define _SORTING_ALG_H

#include <vector>
#include <algorithm>

void quickSort(std::vector<unsigned>& numbers);
void selectionSort(std::vector<unsigned>& numbers);
void insertionSort(std::vector<unsigned>& numbers);
void bubbleSort(std::vector<unsigned>& numbers);
void cppSort(std::vector<unsigned>& numbers);

void inline cppSort(std::vector<unsigned>& numbers) {
    std::sort(numbers.begin(), numbers.end());
}

#endif