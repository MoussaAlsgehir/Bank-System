#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "ClsScreen.h"
#include "ClsUsers.h"
class ClsListUserScreen : protected ClsScreen
{
private:
  static void _printAllUsers(vector<ClsUsers> users)
  {
    for (ClsUsers &user : users)
      cout << "|" << setw(15) << left << user.getUserName() << "| " << setw(15) << left << user.fullName() << "| " << setw(15) << left << user.getEmail() << "| " << setw(15) << left << user.getPhone() << "|" << setw(15) << left << user.getPassword() << "|" << setw(10) << left << user.getPermissions() << "\n";
  }

public:
  static void ShowListUserScreen()
  {
    vector<ClsUsers> _vUsers = ClsUsers::getListUser();
    string title = "\t List User Screen";
    string subTitle = "     ( " + to_string(_vUsers.size()) + " ) User(s).";
    printHeader(title, subTitle);
    cout << "----------------------------------------------------------------------------------------------------------------\n";
    cout << "|" << setw(15) << left << " UserName " << "| " << setw(15) << left << "Full name " << "| " << setw(15) << left << "Email" << "| " << setw(15) << left << "phone " << "|" << setw(15) << left << "Password " << "|" << setw(10) << left << "Permisssions " << "\n";
    cout << "----------------------------------------------------------------------------------------------------------------\n";
    if (_vUsers.size() == 0)
    {
      cout << "\t\tNo found Users.";
    }
    else
      _printAllUsers(_vUsers);
    cout << "----------------------------------------------------------------------------------------------------------------\n";
  }
};