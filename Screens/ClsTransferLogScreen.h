#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsBankClient.h"
class ClsTransferLogScreen : protected ClsScreen
{

private:
  static void _PrintInfo(vector<ClsBankClient::infoRecord> temp)
  {
    for (ClsBankClient::infoRecord &i : temp)
    {
      cout << setw(10) << left << " " << "|" << setw(20) << left << i.date << "| " << setw(20) << left <<i.s_Client << "| " << setw(20) << left <<i.d_Client << "| " << setw(20) << left << i.amount << "|" << setw(20) << left << i.s_AmountClients << "|" << setw(20) << left <<i.d_AmountClients << "|" << setw(20) << left << i.userOpertor<< "   |\n";
    }
  }

public:
  static void showTrasferLogScreen()
  {
    printHeader("\tTransfer Log Screen>");
    vector<ClsBankClient::infoRecord> infoTransfer=ClsBankClient::getInfoOpertionsTransfer() ;
    cout << setw(10) << left << " " << "---------------------=-----------------------------------------------------------------------------------------------------------------------------------\n";
    cout <<setw(10)<<left<<" "<< "|" << setw(20) << left << " Date/Time " << "| " << setw(20) << left << "S_Account " << "| " << setw(20) << left << "D_Account" << "| " << setw(20) << left << "Amount " << "|" << setw(20) << left << "S_Amout " << "|" << setw(20) << left << "D_Amount" << "|" << setw(20) << left << "UserOpertion " << "   |\n";
    cout << setw(10) << left << " " << "---------------------=-----------------------------------------------------------------------------------------------------------------------------------\n";
    if (infoTransfer.size() == 0)
    {
      cout << "\ndo not Opertion Transfer before.\n";
    }
    else
    {
      _PrintInfo(infoTransfer);
    }
    cout << setw(10) << left << " " << "---------------------=-----------------------------------------------------------------------------------------------------------------------------------\n";
  }
};