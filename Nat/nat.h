#ifndef NAT_H
#define NAT_H

#include <iosfwd>

using namespace std;

class Nat {
    public:
        Nat() : i(0) {}
        Nat(unsigned x) : i(x) {}

        Nat operator+(const Nat& rhs);
        Nat operator-(const Nat& rhs);

        unsigned Nat::value() const {
            return i;
        }

        friend ostream& operator<<(ostream& out, const Nat& nat);
    
    private:
        unsigned i;
};

#endif