#ifndef _HASH_H
#define _HASH_H

#include <iostream>
#include <list>

class Hash { 
    private:
        int BUCKET;
        std::list<int> *table; 
    public: 
        Hash(int b);

        void insertItem(int x); 
        void insertItem(std::string x);
        void deleteItem(int key); 

        int hashFunction(int x) { 
            return (x % BUCKET); 
        } 
    
        void displayHash(); 
}; 

#include "hash.cpp"
  
#endif