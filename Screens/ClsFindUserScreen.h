#pragma once
#include <iostream>
#include "ClsInputValdate.h"
#include "ClsScreen.h"
#include <vector>
#include "ClsUsers.h"

class ClsFindUserScreen : protected ClsScreen
{

private:
  static void _PrintUserIndo(ClsUsers user)
  {
    cout << "\nUser Card:";
    cout << "\n------------------";
    cout << "\nFirstName    :" << user.getFirstName();
    cout << "\nLastName     :" << user.getLastName();
    cout << "\nFull Name    :" << user.fullName();
    cout << "\nEmail        :" << user.getEmail();
    cout << "\nPhone        :" << user.getPhone();
    cout << "\nUser Name    :" << user.getUserName();
    cout << "\nPassword     :" << user.getPassword();
    cout << "\nPermissions  :" << user.getPermissions();
    cout << "\n------------------\n";
  }

public:
  static void showFindUserScreen()
  {

    printHeader("\tDelete User Screen.");
    cout << "Please ,Enter Username:";
    string userName = ClsInputValdate::readString();
    while (!ClsUsers::isUserExist(userName))
    {
      cout << "\nUser not Found ,Please enter another one:";
      userName = ClsInputValdate::readString();
    }
    ClsUsers user = ClsUsers::find(userName);
    if (user.isEmpty())
    {
      cout << "\nuser not Found :<(";
    }
    else
    {
      cout << "\nuser Found :>)";
    }
    _PrintUserIndo(user);
  }
};