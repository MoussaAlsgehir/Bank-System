#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "ClsBankClient.h"
#include "ClsScreen.h"
class ClsTotalBalanceScreen : protected ClsScreen
{
private:
 static  void _PrintTotalBalnce(vector<ClsBankClient> cbc)
  {

    for (ClsBankClient &cbc1 : cbc)
      cout << setw(10) << left << " " << "|" << setw(25) << left << cbc1.getAccountNumber() << "| " << setw(25) << left << cbc1.fullName() << "| " << setw(25) << left << cbc1.getAccountBalance() << "   |\n";
  }

public:
  static void showTotalBalanceScreen()
  {

    vector<ClsBankClient> _vClients = ClsBankClient::getListClient();
    string title = "\t\tTotal Balance.";
    string subTitle = "\t\t(" + to_string(_vClients.size()) + ") Clients.";
    printHeader(title, subTitle);
    cout << setw(10) << left << " " << "------------------------------------------------------------------------------------\n";

    cout << setw(10) << left << " " << "|" << setw(25) << left << " Account Number " << "| " << setw(25) << left << "Client Name " << "| " << setw(25) << left << "Balance " << "   |\n";

    cout << setw(10) << left << " " << "------------------------------------------------------------------------------------\n";
    _PrintTotalBalnce(_vClients);
    cout << setw(10) << left << " " << "------------------------------------------------------------------------------------\n";
    double balance = ClsBankClient::getTotalBalance(_vClients);
    cout << setw(10) << left << " " << "\t\t\t\tTotal Balance=" << balance << endl;
    cout << setw(10) << left << " " << "\t\t\t\t(" << ClsInputValdate::TextNumber(balance) << ")" << endl;
  }
};