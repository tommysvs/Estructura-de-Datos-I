#include <iostream>
#include "linkedList.h"

using namespace std;

int LinkedList::size() const {
    if(head == nullptr)
        return 0;
    
    Node *n= head;
    int sz = 0;
    while(n != nullptr) {
        sz++;
        n = n->next;
    }

    return sz;
}

void LinkedList::pushBack(int data) {
    Node *newn = new Node(data);
    if(head == nullptr) {
        head = tail = newn;
    }else {
        tail->next = newn;
        tail = newn;
    }
}

void LinkedList::pushFront(int data) {
    Node *newn = new Node(data);
    if(head == nullptr) {
        head = tail = newn;
    }else {
        newn->next = head;
        head = newn;
    }
}

LinkedList::Node* LinkedList::find(int elem) {
    Node* node  = head;

    while(node != nullptr) {
        if(node->data == elem) {
            cout << "Element found" << endl;
            return node;
        }

        node = node->next;
    }

    cout << "Element not found" << endl;
    return nullptr;
}

LinkedList::Node* LinkedList::findMin() {
    Node* node = head;
    Node* min = head;

    while(node != nullptr) {
        if(node->data < min->data)
            min = node;

        node = node->next;
    }

    return min;
}

LinkedList::Node* LinkedList::findMax() {
    Node* node = head;
    Node* max = head;

    while(node != nullptr) {
        if(node->data > max->data)
            max = node;

        node = node->next;
    }

    return max;
}

void LinkedList::print() const
{
    std::cout << "[ ";
    bool first = true;

    Node *n = head;
    while (n != nullptr)
    {
        if (first) first = false;
        else std::cout << ", ";

        std::cout << n->data;
        n = n->next;
    }
    std::cout << " ]";
}