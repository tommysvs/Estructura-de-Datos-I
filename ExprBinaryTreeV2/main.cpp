#include <iostream>
#include "expr_binary_tree.h"
#include "postfix_gen.h"

int main() {
    ExprPtr n1 = std::make_shared<NumberExpr>(45);
    ExprPtr n2 = std::make_shared<NumberExpr>(73);
    ExprPtr n3 = std::make_shared<NumberExpr>(80);
    ExprPtr n4 = std::make_shared<NumberExpr>(13);
    ExprPtr sum = std::make_shared<AddExpr>(n1, n2);
    ExprPtr sub = std::make_shared<SubExpr>(n3, n4);
    ExprPtr root = std::make_shared<MulExpr>(sum, sub);

    std::cout << root->toString() << '\n';

    PostfixGen pgen;

    std::cout << "Postfix Expression: " << pgen.toPostfix(root.get()) << "\n";
}

//Smart pointers: shared_ptr, unique_ptr, weak_ptr