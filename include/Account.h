// Simple Account 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>
#include "I_Printable.hpp"

class Account: public IPrintable {
private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = def_name, double balance = def_balance);
    // bool deposit(double amount);
    // bool withdraw(double amount);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual ~Account() = default;

    virtual void print(std::ostream& out) const override;
};
#endif