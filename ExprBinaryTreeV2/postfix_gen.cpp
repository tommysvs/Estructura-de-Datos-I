#include <stdexcept>
#include "postfix_gen.h"

std::string PostfixGen::toPostfix(Expr *expr) {
    switch (expr->kind()) {
        case NodeKind::Add:
            return visit(reinterpret_cast<AddExpr *>(expr));
            break;
        case NodeKind::Sub:
            return visit(reinterpret_cast<SubExpr *>(expr));
            break;
        case NodeKind::Mul:
            return visit(reinterpret_cast<MulExpr *>(expr));
            break;
        case NodeKind::Div:
            return visit(reinterpret_cast<DivExpr *>(expr));
            break;
        case NodeKind::Number:
            return visit(reinterpret_cast<NumberExpr *>(expr));
            break;
        default:
            throw std::runtime_error("Invalid node");
    }
}

std::string PostfixGen::visit(AddExpr *expr) {
    std::string lp = toPostfix(expr->left.get());
    std::string rp = toPostfix(expr->right.get());

    return lp + " " + rp + " +";
}

std::string PostfixGen::visit(SubExpr *expr) {
    std::string lp = toPostfix(expr->left.get());
    std::string rp = toPostfix(expr->right.get());

    return lp + " " + rp + " -";
}

std::string PostfixGen::visit(MulExpr *expr) {
    std::string lp = toPostfix(expr->left.get());
    std::string rp = toPostfix(expr->right.get());

    return lp + " " + rp + " *";
}

std::string PostfixGen::visit(DivExpr *expr) {
    std::string lp = toPostfix(expr->left.get());
    std::string rp = toPostfix(expr->right.get());

    return lp + " " + rp + " /";
}

std::string PostfixGen::visit(NumberExpr *expr) {
    return std::to_string(expr->value);
}