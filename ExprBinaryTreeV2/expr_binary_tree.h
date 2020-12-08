#ifndef _EXPR_BINARY_TREE_H
#define _EXPR_BINARY_TREE_H

#include <string>
#include <memory>

enum NodeKind {
    Add, Sub, Mul, Div, Number
};

class Expr;
using ExprPtr = std::shared_ptr<Expr>;

class Expr {
    public:
        virtual std::string toString() const = 0;
        virtual NodeKind kind() const = 0;
        virtual ~Expr() {}

    protected:
        Expr() = default;
};

class BinaryExpr : public Expr {
    protected:
        BinaryExpr(const ExprPtr& expr1, const ExprPtr& expr2) : left(expr1), right(expr2) {}

    public:
        ExprPtr left;
        ExprPtr right;
};

class AddExpr : public BinaryExpr {
    public:
        AddExpr(const ExprPtr& expr1, const ExprPtr& expr2) : BinaryExpr(expr1, expr2) {}

        NodeKind kind() const override {
            return NodeKind::Add;
        }

        std::string toString() const override {
            return left->toString() + "+" + right->toString();
        }
};

class SubExpr : public BinaryExpr {
    public:
        SubExpr(const ExprPtr& expr1, const ExprPtr& expr2) : BinaryExpr(expr1, expr2) {}

        NodeKind kind() const override {
            return NodeKind::Sub;
        }

        std::string toString() const override {
            return left->toString() + "-" + right->toString();
        }
};

class MulExpr : public BinaryExpr {
    public:
        MulExpr(const ExprPtr& expr1, const ExprPtr& expr2) : BinaryExpr(expr1, expr2) {}

        NodeKind kind() const override {
            return NodeKind::Mul;
        }

        std::string toString() const override {
            return left->toString() + "*" + right->toString();
        }
};

class DivExpr : public BinaryExpr {
    public:
        DivExpr(const ExprPtr& expr1, const ExprPtr& expr2) : BinaryExpr(expr1, expr2) {}

        NodeKind kind() const override {
            return NodeKind::Div;
        }

        std::string toString() const override {
            return left->toString() + "/" + right->toString();
        }
};

class NumberExpr : public Expr {
    public: 
        NumberExpr(int value) : value(value) {}

        NodeKind kind() const override {
            return NodeKind::Number;
        }

        std::string toString() const override {
            return std::to_string(value);
        }

        int value;
};

#endif