#include <iostream>
#include "stack.h"

int main() {
    Stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;

    Stack<const char*> s2;
    
    s2.push("first");
    s2.push("second");
    s2.push("third");

    std::cout << s2.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}