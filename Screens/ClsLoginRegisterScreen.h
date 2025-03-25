#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
// #include "ClsLoginScreen.h"
#include "ClsScreen.h"

#include"ClsUsers.h"
class ClsLoginRegisterScreen : protected ClsScreen
{

private:
  static void _PrintInfoRegister(vector<string> infoRegister)
  {
    vector<string> splitRecord;
    for (string &i : infoRegister)
    {
      splitRecord = ClsString::Split(i, "#//#");
      cout << setw(10) << left << " " << "|" << setw(25) << left << splitRecord[0] << "| " << setw(25) << left << splitRecord[1] << "| " << setw(25) << left << ClsUtil::DecryptText(splitRecord[2]) << "| " << setw(25) << left << splitRecord[3] << "   |\n";
      splitRecord.clear();
    }
  }
  static vector<string> _LoadLoginRegister()
  {
    fstream loadInfo;
    loadInfo.open("LoginRegister.txt", ios::in);
    vector<string> infoLogin;
    string line;
    if (loadInfo.is_open())
    {
      while (getline(loadInfo, line))
      {
        infoLogin.push_back(line);
      }
    }
    loadInfo.close();
    return infoLogin;
  }

public:
  static void showListLoginRegister()
  {

    if (!checkAccessRights(ClsUsers::enPermissions::enpLoginRegister))
    {
      return;
    }

    vector<string> info = _LoadLoginRegister();
    string title = "\tLogin Register Screen .";
    string subTitle = "\t(" + to_string(info.size()) + ") Opertion Login.";
    printHeader(title, subTitle);

    cout << setw(10) << left << " " << "---------------------------------------------------------------------------------------------------------------\n";

    cout << setw(10) << left << " " << "|" << setw(25) << left << "Date and time login" << "| " << setw(25) << left << "User Name " << "| " << setw(25) << left << "Password  " << "| " << setw(25) << left << "Permissions" << "   |\n";
    cout << setw(10) << left << " " << "---------------------------------------------------------------------------------------------------------------\n";
    _PrintInfoRegister(info);
    cout << setw(10) << left << " " << "---------------------------------------------------------------------------------------------------------------\n";
  }
};