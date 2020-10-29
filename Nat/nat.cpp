#include "Nat.h"

using namespace std;

Nat Nat::operator+(const Nat& rhs) {
    return Nat(i + rhs.i);
}

Nat Nat::operator-(const Nat& rhs) {
    return Nat(i - rhs.i);
}

ostream& operator<<(ostream& out, const Nat& nat) {
    out << nat.i;
     
    return out;
}