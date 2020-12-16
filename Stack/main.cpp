#include <iostream>
#include <string>
#include "stack.h"

int main() {
    Stack<int> s;

    std::string in_exp, p_exp;

    //std::cout << "Enter infix expression: ";
    //std::cin >> in_exp;
    in_exp = "((3+4)*2)/7";

    p_exp = s.infixToPostfix(in_exp);
    std::cout << "\nPostfix expression: " << p_exp << std::endl;
    std::cout << "Postfix evaluation: " << s.evaluatePostfix("34+2*7/") << std::endl;
}