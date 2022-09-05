#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"

class Checking_Account: public Account {
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);    
    // bool withdraw(double);
    // Inherits the Account::deposit method


    // virtual bool withdraw(double amount) override {
    //     amount += per_check_fee;
    //     return Account::withdraw(amount);
    // };
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(std::ostream& out) const override;

    virtual ~Checking_Account() = default;

    // virtual bool deposit(double amount) override {
        
    // };
};

#endif // _CHECKING_ACCOUNT_H_
