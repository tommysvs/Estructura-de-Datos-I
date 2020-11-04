#include <iostream>
#include "Nat.h"

Nat Nat::operator+(const Nat& rhs) {
    return Nat(i + rhs.i);
}

Nat Nat::operator-(const Nat& rhs) {
    return Nat(i - rhs.i);
}

std::ostream& operator<<(std::ostream& out, const Nat& nat) {
    out << nat.value();
     
    return out;
}