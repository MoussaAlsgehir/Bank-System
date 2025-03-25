#pragma once
#include <iostream>
#include "ClsBankClient.h"
#include "ClsScreen.h"
class ClsListClients : protected ClsScreen
{
private:
 
static void _PrintInfoClinet(ClsBankClient cbc)
  {
    cout << "|" << setw(20) << left << cbc.getAccountNumber() << "| " << setw(20) << left << cbc.fullName() << "| " << setw(20) << left << cbc.getEmail() << "| " << setw(20) << left << cbc.getPinCode() << "|" << setw(20) << left << cbc.getAccountBalance() << "   |\n";
  }

public:
  static void showListClient()
  {

    if (!checkAccessRights(ClsUsers::enPermissions::enpShowClients))
    {
      return;
    }
    string title = "\t    Client List Screen";
    vector<ClsBankClient> _vCLients = ClsBankClient::getListClient();
    string subTitle = "\t\t(" + to_string(_vCLients.size()) + ") Clients";
    printHeader(title, subTitle);
    cout << "\t\t\t\t\tClient List (" << _vCLients.size() << ") Client(s)" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------\n";
    cout << "|" << setw(20) << left << " Account Number " << "| " << setw(20) << left << "Client Name " << "| " << setw(20) << left << "Email" << "| " << setw(20) << left << "PinCode " << "|" << setw(20) << left << "Balance " << "   |\n";
    cout << "----------------------------------------------------------------------------------------------------------------\n";
    if (_vCLients.size() == 0)
      cout << "\t\t\t\t\tno found Clinet :-(" << endl;
    else
      for (ClsBankClient &cbc : _vCLients)
        _PrintInfoClinet(cbc);
    cout << "----------------------------------------------------------------------------------------------------------------\n";
  }
};