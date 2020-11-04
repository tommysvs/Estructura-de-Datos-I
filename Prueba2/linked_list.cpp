#include <iostream>
#include <sstream>
#include "linked_list.h"

template<typename TList>
int LinkedList<TList>::size() const
{
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
void LinkedList<TList>::pushBack(int data)
{
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
void LinkedList<TList>::pushFront(int data)
{
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
std::string LinkedList<TList>::toString() const
{
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
    return true;
}

template<typename TList>
void LinkedList<TList>::sort() {
    Node* node = head;
    Node* temp = nullptr;
    int temp_data;
    int size = size();

    while(node != nullptr) {
        temp = node;

        
    }
}