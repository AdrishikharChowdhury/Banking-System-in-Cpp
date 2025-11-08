#include "Account.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

Account::Account(string name, string password, double balance)
{
    this->name = name;
    this->password = password;
    this->balance = balance;
    this->accNo = generateAccNumber();
}

string Account::generateAccNumber()
{
    srand(time(0));
    string accNo = "";
    for (int i = 0; i < 10; i++)
    {
        int randomNum = 1 + (rand() % 10);
        accNo += to_string(randomNum);
    }
    return accNo;
}

bool Account::checkLogin(string accPassword)
{
    int chance = 4;
    string inputPassword;
    while (chance > 0)
    {
        cout << "Enter your password: ";
        getline(cin, inputPassword);
        if (inputPassword == accPassword)
            return true;
        else
        {
            chance--;
            if (chance > 0)
                cout << "Wrong Password. Try Again. You have " << chance << " chances left." << endl;
        }
    }
    return false;
}

void Account::displayAcc()
{
    if (checkLogin(this->password))
    {
        cout << "==============================" << endl;
        cout << "ACCOUNT [" << accNo << "]" << endl;
        cout << "==============================" << endl;
        cout << "Name: " << name << endl;
        cout << "Account No. " << accNo << endl;
        cout << "Balance: " << balance << endl;
        cout << "==============================" << endl;
    }
    else
    {
        cout << "Sorry the password is not correct & no chances left." << endl;
    }
}

void Account::creditBalance(double newBalance)
{
    if (checkLogin(this->password))
    {
        if (newBalance > 100000)
        {
            cout << "Credit Amount is too much" << endl;
            return;
        }
        else if (newBalance <= 0)
        {
            cout << "Invalid Amount" << endl;
            return;
        }
        balance += newBalance;
    }
    else
    {
        cout << "Sorry the password is not correct & no chances left." << endl;
    }
}

void Account::debitBalance(double debitAmt)
{
    if (checkLogin(this->password))
    {
        if (debitAmt > balance)
        {
            cout << "You can't debit greater than what you have" << endl;
            return;
        }
        else if (debitAmt <= 0)
        {
            cout << "Invalid Amount" << endl;
            return;
        }
        balance -= debitAmt;
    }
    else
    {
        cout << "Sorry the password is not correct & no chances left." << endl;
    }
}

void Account::showBalance()
{
    if (checkLogin(this->password))
    {
        cout << "Available Balance: " << balance << endl;
    }
    else
    {
        cout << "Sorry the password is not correct & no chances left." << endl;
    }
}

double Account::getBalance() const
{
    return balance;
}

string Account::getAccNo() const
{
    return this->accNo;
}

Account *Account::searchAccount(const std::string &accNo, std::vector<Account> &accounts)
{
    for (auto &account : accounts)
    {
        if (accNo == account.getAccNo())
        {
            return &account;
        }
    }
    return nullptr;
}

void Account::getAllAccounts()
{
    cout << "==============================" << endl;
    cout << "ACCOUNT [" << accNo << "]" << endl;
    cout << "==============================" << endl;
    cout << "Name: " << name << endl;
    cout << "Account No. " << accNo << endl;
    cout << "Balance: " << balance << endl;
    cout << "==============================" << endl;
}