#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[]) {
    LinkedList l1;

    l1.print();
    cout << endl;

    for(int i = 1; i <= 10; i++) 
        l1.pushBack(i * 10);

    l1.print();
    cout << endl;

    for(int i = 10; i >= 1; i--) {
        l1.pushFront(i * 10);

        l1.print();
        cout << endl;
    }

    l1.print();
    std::cout << '\n';

    l1.findMin();
    l1.findMax();

    return 0;
}