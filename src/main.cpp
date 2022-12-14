// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include <memory>

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    // vector<Account *> accounts;
    std::vector<std::unique_ptr<Account>> accounts;
    // accounts.push_back(new Checking_Account());


    // unique_ptr's cannot be copied. Therefore, we use move semantics to avoid attempting to copy the pointer to vector.
    // now the vector owns ownership of the pointer.
    std::unique_ptr<Account> base_abstract_interface = std::make_unique<Checking_Account>();
    accounts.push_back(std::move(base_abstract_interface));
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 
    std::vector<std::unique_ptr<Account>> sav_accounts;
    sav_accounts.push_back(std::make_unique<Savings_Account>());
    sav_accounts.push_back(std::make_unique<Savings_Account>("Superman"));
    sav_accounts.push_back(std::make_unique<Savings_Account>("Batman", 2000));
    sav_accounts.push_back(std::make_unique<Savings_Account>("Wonderwoman", 5000, 5.0));

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);
   
   // Checking
   
    std::vector<std::unique_ptr<Account>> check_accounts;
    check_accounts.push_back(std::make_unique<Checking_Account>());
    check_accounts.push_back(std::make_unique<Checking_Account>("Kirk"));
    check_accounts.push_back(std::make_unique<Checking_Account>("Spock", 2000));
    check_accounts.push_back(std::make_unique<Checking_Account>("Bones", 5000));

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust
  
    std::vector<std::unique_ptr<Account>> trust_accounts;
    trust_accounts.push_back(std::make_unique<Trust_Account>());
    trust_accounts.push_back(std::make_unique<Trust_Account>("Athos", 10000, 5.0));
    trust_accounts.push_back(std::make_unique<Trust_Account>("Porthos", 20000, 4.0));
    trust_accounts.push_back(std::make_unique<Trust_Account>("Aramis", 30000));

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);
    

    
    return 0;
}

