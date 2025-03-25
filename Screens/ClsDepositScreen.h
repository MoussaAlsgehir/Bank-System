#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "ClsInputValdate.h"
#include "ClsBankClient.h"
class ClsDepositScreen : protected ClsScreen
{

private:
  static void _PrintClient(ClsBankClient cbc)
  {
    cout << "\nClient Card:";
    cout << "\n------------------";
    cout << "\nFirstName    :" << cbc.getFirstName();
    cout << "\nLastName     :" << cbc.getLastName();
    cout << "\nFull Name    :" << cbc.fullName();
    cout << "\nEmail        :" << cbc.getEmail();
    cout << "\nPhone        :" << cbc.getPhone();
    cout << "\nAccountNumber:" << cbc.getAccountNumber();
    cout << "\nPassword     :" << cbc.getPinCode();
    cout << "\nBalance      :" << cbc.getAccountBalance();
    cout << "\n------------------\n";
  }
  static string _ReadAccountNumber()
  {
    return ClsInputValdate::readString();
  }

public:
  static void showDepositScreen()
  {

    printHeader("\t\tDeposit Screen.");
    cout << "Enter Account number ?";
    string accountNumber = _ReadAccountNumber();
    while (!ClsBankClient::isClientExist(accountNumber))
    {
      cout << "Account not Found Please enter another one:";
      accountNumber = _ReadAccountNumber();
    }

    ClsBankClient cbc = ClsBankClient::find(accountNumber);
    _PrintClient(cbc);

    double amount = 0.0;
    cout<<"Enter amount you want to add balance : ";
    amount = ClsInputValdate::readDoubleNumber("Wrong Input !!\n");
    cout << "\nAre you sure want do to deposit ?y/n?";
    char answer = 'n';
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
      cbc.deposit(amount);
      cout << "\nsaccessflly deposit :-)";
      cout << "\n now Balance is : " << cbc.getAccountBalance() << endl;
    }
    else
    {
      cout << "deposit conceled!!"<<endl;
    }
  }
};