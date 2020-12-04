#include <iostream>
#include "expr_binary_tree.h"

int main() {
    auto *n1 = new ExprBinaryTree::Node(45);
    auto *n2 = new ExprBinaryTree::Node(73);
    auto *n3 = new ExprBinaryTree::Node(100);
    auto sum = new ExprBinaryTree::Node(Operator::Add, n1, n2);
    auto mul = new ExprBinaryTree::Node(Operator::Mult, sum, n3);

    ExprBinaryTree expr;
    expr.setRoot(mul);

    std::cout << expr.toString() << '\n';
}