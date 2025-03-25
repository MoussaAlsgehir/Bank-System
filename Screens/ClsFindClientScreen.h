#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "ClsInputValdate.h"
#include "ClsBankClient.h"
class ClsFindClientScreen : protected ClsScreen
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
  static void showFindClient()
  {

    if (!checkAccessRights(ClsUsers::enPermissions::enpFindClient))
    {
      return;
    }
    printHeader("\tFind Client Screen.");

    cout << "Please Enter Account number :";
    string accountNumber = "";
    accountNumber = ClsInputValdate::readString();
    while (!ClsBankClient::isClientExist(accountNumber))
    {
      cout << "Account not Found Please enter another one:";
      accountNumber = ClsInputValdate::readString();
    }
    ClsBankClient cbc = ClsBankClient::find(accountNumber);

    if (!cbc.isEmpty())
    {
      cout << "Client Found :-)\n";
      _PrintClient(cbc);
    }
    else
    {
      cout << "Client Not Found :-(\n";
    }
  }
};