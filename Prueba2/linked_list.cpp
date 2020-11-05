#include <iostream>
#include <sstream>
#include "linked_list.h"

template <typename TList>
LinkedList<TList>::LinkedList(const std::initializer_list<TList>& init) : head(nullptr), tail(nullptr) {
    for (auto d : init) {
        if (head == nullptr)
            pushFront(d);
        else 
            pushBack(d);
    }
}

template <typename TList>
LinkedList<TList>::~LinkedList() {
    Node *next = nullptr;
    Node *temp = head;
        
    while(next) {
        temp = next;
        next = next->next;
        delete temp;
    }
}

template<typename TList>
int LinkedList<TList>::size() const {
    Node *n = head;
    int sz = 0;
    while (n != nullptr)
    {
        sz++;
        n = n->next;
    }

    return sz;
}

template<typename TList>
void LinkedList<TList>::pushBack(TList data) {
    Node *newn = new Node(data);
    if (head == nullptr)
    {
        head = tail = newn;
    }
    else
    {
        tail->next = newn;
        tail = newn;
    }
}

template<typename TList>
void LinkedList<TList>::pushFront(TList data) {
    Node *newn = new Node(data);
    if (head == nullptr)
    {
        head = tail = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
}

template<typename TList>
std::string LinkedList<TList>::toString() const {
    std::ostringstream out;
    
    out << "[";
    bool first = true;

    Node *n = head;
    while (n != nullptr)
    {
        if (first) first = false;
        else out << ",";

        out << n->data;
        n = n->next;
    }
    out << "]";
    
    return out.str();
}

template<typename TList>
bool LinkedList<TList>::isSorted() const {
    Node *current = head;
    TList d = current->data;

    while (current) {
        if(d > current->data)
            return false;

        current = current->next;
    }

    return true;
}

template<typename TList>
void LinkedList<TList>::sort() {
    Node *current = head;
    Node *next;
    TList temp;

    while (current && current->next) {
        next = current->next;

        while (next) {
            if (current->data > next->data)
                std::swap(next->data, current->data);

            next = next->next;
        }

        current = current->next;
    }
}