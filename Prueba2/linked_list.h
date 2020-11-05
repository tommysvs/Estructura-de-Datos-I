#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <initializer_list>

template <typename TList>
class LinkedList {
public:
    class Node {
    public:
        Node(TList val) : data(val), next(nullptr) {}
        
        TList data;
        Node *next;
    };

    LinkedList() : head(nullptr), tail(nullptr) {}

    LinkedList(const std::initializer_list<TList>& init);
    LinkedList(const LinkedList& other);

    ~LinkedList();

    std::string toString() const;
    int size() const;
    void pushBack(TList data);
    void pushFront(TList data);

    bool isSorted() const;
    void sort();
    
    template <typename T>
    friend std::ostream& operator << (std::ostream& out, const LinkedList<T>& lst);

private:
    Node *head;
    Node *tail;
};

#include "linked_list.cpp"

#endif