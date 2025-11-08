#include <iostream>
#include <string>
#include <limits>
#include "Account.h"

using namespace std;

int main()
{
    string name, password;
    double balance, amount;
    bool isOn = true;
    int choice;

    cout << "Enter Account Holder's Name: ";
    getline(cin, name);
    cout << "Enter Account Holder's password: ";
    getline(cin, password);
    cout << "Enter Account Holder's Balance: ";
    cin >> balance;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account person(name, password, balance);

    do
    {
        cout << "\nBank Menu\n1. Deposit\n2. Withdraw\n3. Show Balance\n4. Display Account Info\n5. Exit\nEnter your choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            cout << "Enter the deposit amount: ";
            cin >> amount;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            person.creditBalance(amount);
            cout << "Your balance is " << person.getBalance() << endl;
            break;
        case 2:
            cout << "Enter the debit amount: ";
            cin >> amount;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            person.debitBalance(amount);
            cout << "Your balance is " << person.getBalance() << endl;
            break;
        case 3:
            person.showBalance();
            break;
        case 4:
            person.displayAcc();
            break;
        case 5:
            isOn = false;
            cout << "Thank you for choosing our banking system. I hope you had a good experience" << endl;
            break;
        default:
            cout << "Wrong choice try again :(" << endl;
        }
    } while (isOn);
    return 0;
}
