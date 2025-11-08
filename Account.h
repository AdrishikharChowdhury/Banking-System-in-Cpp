#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

using namespace std;

class Account
{
public:
    Account(string name, string password, double balance);
    void displayAcc();
    void creditBalance(double newBalance);
    void debitBalance(double debitAmt);
    void showBalance();
    string getAccNo() const;
    // For accessing balance externally if needed
    double getBalance() const;
    static Account *searchAccount(const std::string &accNo, std::vector<Account> &accounts);
    void getAllAccounts();

private:
    string generateAccNumber();
    bool checkLogin(string accPassword);
    string name = "";
    string accNo = "";
    string password = "";
    double balance = 0.0;
};

#endif
