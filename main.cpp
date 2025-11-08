#include <iostream>
#include <string>
#include <limits>
#include "Account.h"
#include <vector>

using namespace std;

int main()
{
    string name, password, accNo;
    double balance, amount;
    bool isOn = true, flag = false;
    int choice, n;
    vector<Account> accounts;
    Account *person=nullptr;
    cout << "Enter no. of accounts you want to create: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Account Holder's Name: ";
        getline(cin, name);
        cout << "Enter Account Holder's password: ";
        getline(cin, password);
        cout << "Enter Account Holder's Balance: ";
        cin >> balance;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Account person(name, password, balance);
        cout << "Account for " << name << " has been created" << endl;
        accounts.push_back(person);
    }
    do
    {
        cout << "\nBank Menu\n1. Deposit\n2. Withdraw\n3. Show Balance\n4. Display Account Info\n5. Display All accounts\n6. Exit\nEnter your choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            cout << "Enter your account number: ";
            getline(cin, accNo);
            person = Account::searchAccount(accNo, accounts);
            if (person != nullptr)
            {
                cout << "Enter the deposit amount: ";
                cin >> amount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                person->creditBalance(amount);
                cout << "Your balance is " << person->getBalance() << endl;
            }
            else
            {
                cout << "Account not found" << endl;
            }
            break;
        case 2:
            cout << "Enter your account number: ";
            getline(cin, accNo);
            person = Account::searchAccount(accNo, accounts);
            if (person != nullptr)
            {
                cout << "Enter the debit amount: ";
                cin >> amount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                person->debitBalance(amount);
                cout << "Your balance is " << person->getBalance() << endl;
            }
            else
            {
                cout << "Account not found" << endl;
            }
            break;
        case 3:
            cout << "Enter your account number: ";
            getline(cin, accNo);
            person = Account::searchAccount(accNo, accounts);
            if (person != nullptr)
            {
                person->showBalance();
            }
            else
            {
                cout << "Account not found" << endl;
            }
            break;
        case 4:
            cout << "Enter your account number: ";
            getline(cin, accNo);
            person = Account::searchAccount(accNo, accounts);
            if (person != nullptr)
            {
                person->displayAcc();
            }
            else
            {
                cout << "Account not found" << endl;
            }
            break;
        case 5:
            cout << "The accounts registered are:" << endl;
            for (Account account : accounts)
            {
                account.getAllAccounts();
            }
            break;
        case 6:
            isOn = false;
            cout << "Thank you for choosing our banking system. I hope you had a good experience" << endl;
            break;
        default:
            cout << "Wrong choice try again :(" << endl;
        }
    } while (isOn);
    return 0;
}
