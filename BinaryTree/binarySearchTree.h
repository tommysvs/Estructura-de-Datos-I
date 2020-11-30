#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

template <typename TElem>
class BinarySearchTree {
    public:
        class Node {
            public:
                Node(TElem data) : data(data), left(nullptr), right(nullptr) {}

                void print();
                void inorder() const;
                void preorder() const;
                void postorder() const;

                TElem data;
                Node *left;
                Node *right;
        };

        BinarySearchTree() : root(nullptr) {}
        ~BinarySearchTree() {}

        void add(Node *n);
        
        void insert(TElem data);
        Node *find(TElem data);
        void print();

        void inorder() const {
            root->inorder();
            std::cout << '\n';
        }

        void preorder() const {
            root->preorder();
            std::cout << '\n';
        }

        void postorder() const {
            root->postorder();
            std::cout << '\n';
        }
        
    private:
        Node *root;
};

#include "binarySearchTree.cpp"

#endif