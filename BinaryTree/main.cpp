#include <iostream>
#include "binary_tree.h"

int main() {
    BinarySearchTree<int> bti;

    bti.insert(67);
    bti.insert(35);
    bti.insert(73);
    bti.insert(23);
    bti.insert(87);
    bti.insert(17);
    bti.insert(35);
    bti.insert(73);
    bti.insert(38);
    bti.insert(45);

    bti.inorder();
    bti.preorder();
    bti.postorder();
}