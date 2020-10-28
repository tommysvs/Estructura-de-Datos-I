#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[]) {
    LinkedList l1;

    l1.print();
    cout << endl;

    for(int i = 1; 1 <= 10; i++) 
        l1.pushBack(i * 10);

    l1.print();
    cout << endl;

    for(int i = 10; 1 >= 1; i--) {
        l1.pushFront(i * 10);

        l1.print();
        cout << endl;
    }

    l1.print();
    std::cout << '\n';

    return 0;
}