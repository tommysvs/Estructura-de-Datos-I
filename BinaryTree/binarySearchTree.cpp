template <typename TElem>
void BinarySearchTree<TElem>::Node::print() {
    std::cout << data;

    if(left != nullptr || right != nullptr) {
        std::cout << '{' << '\n';

        if(left != nullptr) {
            std::cout << "left: ";
            left->print();
        }

        if(right != nullptr) {
            std::cout << "right: ";
            right->print();
        }

        std::cout << '}';
    }

    std::cout << '\n';
}

template <typename TElem>
void BinarySearchTree<TElem>::Node::inorder() const {
    if(left != nullptr)
        left->inorder();

    std::cout << data << ' ';

    if(right != nullptr)
        right->inorder();
}

template <typename TElem>
void BinarySearchTree<TElem>::Node::preorder() const {
    std::cout << data << ' ';

    if(left != nullptr)
        left->inorder();

    if(right != nullptr)
        right->inorder();
}

template <typename TElem>
void BinarySearchTree<TElem>::Node::postorder() const {
    if(left != nullptr)
        left->inorder();

    if(right != nullptr)
        right->inorder();

    std::cout << data << ' ';
}

template <typename TElem>
void BinarySearchTree<TElem>::insert(TElem data) {
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
template <typename TElem>
typename BinarySearchTree<TElem>::Node *BinarySearchTree<TElem>::find(TElem data) {
    Node *n = root;
    do {
        if(n == nullptr || n->data == data)
            return n;

        if(data < n->data )
            n = n->left;
        else
            n = n->right;
    } while(true);
}

template <typename TElem>
void BinarySearchTree<TElem>::print() {
    if(root != nullptr)
        root->print();
}
        