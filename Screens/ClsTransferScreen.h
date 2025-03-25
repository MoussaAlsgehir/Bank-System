#pragma once
#include <iostream>
#include "fstream"
#include "ClsInputValdate.h"
#include "ClsDate.h"
#include "ClsScreen.h"
#include "Globle.h"
#include "ClsBankClient.h"
class CLsTransferScreen : protected ClsScreen
{

private:
  static void _PrintShortInfo(ClsBankClient cbc)
  {

    cout << "CLient Info:" << endl;
    cout << "--------------------" << endl;
    cout << "Full Name      :" << cbc.fullName() << endl;
    cout << "Account Number : " << cbc.getAccountNumber() << endl;
    cout << "Balance        :" << cbc.getAccountBalance() << endl;
    cout << "--------------------" << endl;
  }
  static string _TransferRecordLine(ClsBankClient cbc1, ClsBankClient cbc2, double amount, string sperator = "#//#")
  {
    return ClsDate::GetTimeAndDate() + sperator + cbc1.getAccountNumber() + sperator + cbc2.getAccountNumber() + sperator + to_string(amount) + sperator + to_string(cbc1.getAccountBalance()) + sperator + to_string(cbc2.getAccountBalance()) + sperator + userGloble.getUserName();
  }
  static void _SaveTransferInfoToFile(string line)
  {
    fstream saveInfo;
    saveInfo.open("TransferLog.txt", ios::app | ios::out);
    if (saveInfo.is_open())
    {
      saveInfo << line << endl;
    }
    saveInfo.close();
  }
  static bool _TransferBalance(ClsBankClient &cbc1, ClsBankClient &cbc2)
  {
    cout << "\nEnter Tranfer Amount :";
    double amountTrans = ClsInputValdate::readDoubleNumber("");
    while (amountTrans > cbc1.getAccountBalance())
    {
      cout << "\nAmount Exceeds the available Balance, Enter another Amount :";
      amountTrans = ClsInputValdate::readDoubleNumber("");
    }

    cout << "Are you sure you want to perforn this opertion?y/n:";
    char answer;
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
      cbc1.withdraw(amountTrans);
      cbc2.deposit(amountTrans);
      string line = _TransferRecordLine(cbc1, cbc2, amountTrans);
      _SaveTransferInfoToFile(line);
      return true;
    }

    return false;
  }

public:
  static void showTransferScreen()
  {
    printHeader("\t Transfer Screen.");
    cout << "\nplease Enter Account Number to Tranfer From :";
    string accountNumber1 = ClsInputValdate::readString();
    while (!ClsBankClient::isClientExist(accountNumber1))
    {
      cout << "Account Number Not Found ,Please Enter another one:";
      string accountNumber1 = ClsInputValdate::readString();
    }
    ClsBankClient cbc1 = ClsBankClient::find(accountNumber1);
    _PrintShortInfo(cbc1);
    cout << "\nplease Enter Account Number to Tranfer To :";

    string accountNumber2 = ClsInputValdate::readString();
    while (!ClsBankClient::isClientExist(accountNumber2))
    {
      cout << "Account Number Not Found ,Please Enter another one:";
      string accountNumber1 = ClsInputValdate::readString();
    }
    ClsBankClient cbc2 = ClsBankClient::find(accountNumber2);
    _PrintShortInfo(cbc2);
    if (_TransferBalance(cbc1, cbc2))
    {
      cout << "\nSuccessflly done Transfer :>) .\n";
      _PrintShortInfo(cbc1);
      _PrintShortInfo(cbc2);
    }
  }






};