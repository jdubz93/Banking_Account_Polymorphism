#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {
}

bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    // balance += amount;
    return Account::deposit(amount);
}

void Checking_Account::print(std::ostream& out) const {
    std::cout.precision(2);
    std::cout << std::fixed;
    out << "[Checking_Account: " << name << ": " << balance  << "]";
};

