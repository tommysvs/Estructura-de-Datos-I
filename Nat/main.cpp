#include <iostream>
#include "Nat.h"

using namespace std;

int main() {
    Nat n1(8), n2(9);
    Nat n3, n4;

    n3 = n1 + n2;
    n4 = n2 - n1;

    cout << "n3: " << n3 << endl;
    cout << "n4: " << n4 << endl;

    return 0;
}