#include <iostream>
#include "I_Printable.hpp"

std::ostream& operator<<(std::ostream& out, const IPrintable& rhs) {
    rhs.print(out);
    return out;
};