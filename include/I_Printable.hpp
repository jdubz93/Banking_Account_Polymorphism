#ifndef _I_PRINTABLE_HPP_
#define _I_PRINTABLE_HPP_

#include <iostream>

class IPrintable {
    friend std::ostream& operator<<(std::ostream& out, const IPrintable& obj);
public:
    virtual void print(std::ostream& out) const = 0;
    virtual ~IPrintable() = default;
private:
};

#endif // _I_PRINTABLE_HPP_