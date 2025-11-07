#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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
        cout << "Name: " << name << endl;
        cout << "Account No. " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{

    string name, password;
    double balance;
    cout << "Enter Account Holder's Name: ";
    getline(cin, name);
    cout << "Enter Account Holder's password: ";
    getline(cin, password);
    cout << "Enter Account Holder's Balance: ";
    cin >> balance;
    Account person(name, password, balance);
    person.displayAcc();
    return 0;
}