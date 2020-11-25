#include <iostream>
#include <sstream>
#include "linked_list.h"

template <typename TElem>
LinkedList<TElem>::LinkedList(const std::initializer_list<TElem>& init) : head(nullptr), tail(nullptr), size_(0) {
    for (auto d : init) {
        if (head == nullptr)
            pushFront(d);
        else 
            pushBack(d);
    }
}

template <typename TElem>
LinkedList<TElem>::~LinkedList() {
    Node *next = nullptr;
    Node *temp = head;
        
    while(next) {
        temp = next;
        next = next->next;
        delete temp;
    }
}

template<typename TElem>
long LinkedList<TElem>::size() const {
    Node *n = head;
    long sz = 0;

    while (n != nullptr) {
        sz++;
        n = n->next;
    }

    return sz;
}

template<typename TElem>
void LinkedList<TElem>::pushBack(TElem data) {
    Node *newn = new Node(data);

    if (head == nullptr)
        head = tail = newn;
    else {
        tail->next = newn;
        tail = newn;
    }
}

template<typename TElem>
void LinkedList<TElem>::pushFront(TElem data) {
    Node *newn = new Node(data);

    if (head == nullptr)
        head = tail = newn;
    else {
        newn->next = head;
        head = newn;
    }
}

template<typename TElem>
bool LinkedList<TElem>::operator==(const LinkedList& other) const {
    return other.size_ == size_;
}

template<typename TElem>
void LinkedList<TElem>::insertionSort() {
    Node *current = head;
    Node *next;
    TElem temp;

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