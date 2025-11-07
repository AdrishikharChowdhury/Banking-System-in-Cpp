#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

string accNumber()
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

bool checkLogin(string accPassword)
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

class Account
{
public:
    string name;
    string accNo;
    string password;
    double balance;

    Account(string name, string password, double balance)
    {
        this->name = name;
        this->password = password;
        this->balance = balance;
        this->accNo = accNumber();
    }

    void displayAcc()
    {
        bool isLogin = checkLogin(this->password);
        if (isLogin)
        {
            cout << "Name: " << name << endl;
            cout << "Account No. " << accNo << endl;
            cout << "Balance: " << balance << endl;
        }
        else
        {
            cout << "Sorry the password is not correct & no chances left." << endl;
            return;
        }
    }

    void creditBalance(double newBalance)
    {
        bool isLogin = checkLogin(this->password);
        if (isLogin)
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
            else
            {
                this->balance = this->balance + newBalance;
            }
        }
        else
        {
            cout << "Sorry the password is not correct & no chances left." << endl;
            return;
        }
    }

    void debitBalance(double debitAmt)
    {
        bool isLogin = checkLogin(this->password);
        if (isLogin)
        {
            if (debitAmt > this->balance)
            {
                cout << "You can't debit greater than what you have" << endl;
                return;
            }
            else if (debitAmt <= 0)
            {
                cout << "Invalid Amount" << endl;
                return;
            }
            else
            {
                this->balance = this->balance - debitAmt;
            }
        }
        else
        {
            cout << "Sorry the password is not correct & no chances left." << endl;
            return;
        }
    }
    void showBalance()
    {
        bool isLogin = checkLogin(this->password);
        if (isLogin)
        {
            cout << "Available Balance: " << this->balance << endl;
        }
        else
        {
            cout << "Sorry the password is not correct & no chances left." << endl;
            return;
        }
    }
};

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
    Account person(name, password, balance);
    do
    {
        cout << "Bank Menu" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Show Balance" << endl;
        cout << "4. Display Account Info" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
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
            cout<<"Your balance is "<<person.balance<<endl;
            break;
        case 2:
            cout << "Enter the debit amount: ";
            cin >> amount;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            person.debitBalance(amount);
            cout<<"Your balance is "<<person.balance<<endl;
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