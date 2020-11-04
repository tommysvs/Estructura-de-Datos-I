#ifndef NAT_H
#define NAT_H

#include <iosfwd>

class Nat {
    public:
        Nat() : i(0) {}
        Nat(unsigned x) : i(x) {}

        Nat operator+(const Nat& rhs);
        Nat operator-(const Nat& rhs);

        unsigned value() const {
            return i;
        }

        friend std::ostream& operator<<(std::ostream& out, const Nat& nat);
    
    private:
        unsigned i;
};

#endif