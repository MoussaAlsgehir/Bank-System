#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "ClsInputValdate.h"
#include "ClsBankClient.h"
class ClsDeleteClientScreen : protected ClsScreen
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

public:
  static void showDeleteClient()
  {

    if (!checkAccessRights(ClsUsers::enPermissions::enpDeleteClient))
    {
      return;
    }
    printHeader("\tDelete Client Screen.");

    cout << "Please Enter Account number :";
    string accountNumber = "";
    accountNumber = ClsInputValdate::readString();
    while (!ClsBankClient::isClientExist(accountNumber))
    {
      cout << "Account not Found Please enter another one:";
      accountNumber = ClsInputValdate::readString();
    }
    ClsBankClient cbc = ClsBankClient::find(accountNumber);

    _PrintClient(cbc);
    cout << "\n Are you sure you want to deletethis client y/n?";
    char answer = 'n';
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {

      if (cbc.Delete())
      {
        cout << "\nsuccessfly Delete Account :-)\n";
        _PrintClient(cbc);
      }
      else
      {
        cout << "\nError do not Deleted Account !!!";
      }
    }
  }
};