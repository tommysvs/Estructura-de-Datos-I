#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

template<typename TElem>
class BinarySearchTree {
public:
    class Node {
        public:
            Node(TElem data) : data(data), left(nullptr), right(nullptr) {}

            void print();
            void inorder() const;

            TElem data;
            Node *left;
            Node *right;
    };

    std::list<TElem> inorder() const {
        // if(left != nullptr)
        //     left->inorder();

        // std::cout << data << ' ';

        // if(right != nullptr)
        //     right->inorder();
    }

    void insert(TElem data) {
        if(root == nullptr) {
            root = new Node(data);
            return;
        }

        Node *n = root;
        do {
            if(n->data == data) {
                std::cout << "Found element: " << data << '\n';
                break;
            }

            if(data < n->data ) {
                if(n->left == nullptr) {
                    n->left = new Node(data);
                    break;
                }
                else
                    n = n->left;
            } else {
                if(n->right == nullptr) {
                    n->right = new Node(data);
                    break;
                }
                else
                    n = n->right;
            }
        } while(true);
    }

    private:
        Node *root;
};

#endif
