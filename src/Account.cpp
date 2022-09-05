#include "Account.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}

bool Account::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

void Account::print(std::ostream& out) const {
    std::cout.precision(2);
    std::cout << std::fixed;
    out << "[Account: " << name << ": " << balance << "]";
    // out << " Account display" << std::endl;
};

// std::ostream &operator<<(std::ostream &os, const Account &account) {
//     os << "[Account: " << account.name << ": " << account.balance << "]";
//     return os;
// }
