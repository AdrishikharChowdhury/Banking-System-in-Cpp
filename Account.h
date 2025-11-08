#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account
{
public:
    Account(string name, string password, double balance);
    void displayAcc();
    void creditBalance(double newBalance);
    void debitBalance(double debitAmt);
    void showBalance();

    // For accessing balance externally if needed
    double getBalance() const;

private:
    string generateAccNumber();
    bool checkLogin(string accPassword);

    string name;
    string accNo;
    string password;
    double balance;
};

#endif
