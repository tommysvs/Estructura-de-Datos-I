#include <iostream>
#include <string>
#include "hash.h"

int main() {
    int a[] = {15, 11, 27, 8, 12}; 
    int n = sizeof(a)/sizeof(a[0]); 

    Hash h(7);  
    
    for (int i = 0; i < n; i++)  
        h.insertItem(a[i]);
    
    h.displayHash(); 
}