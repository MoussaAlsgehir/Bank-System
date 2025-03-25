#pragma once
#include <iostream>
#include "ClsInputValdate.h"
#include "ClsScreen.h"
#include <vector>
#include "ClsUsers.h"

class ClsDeleteUserScreen : protected ClsScreen
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
  static void showDeleteUserScreen()
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
    _PrintUserIndo(user);

    cout << "Are you sure ,you want to delete User?y/n :";
    char answer;
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
      if (user.Delete())
      {
        cout << "\nSuccessflly Deleted User.";
        _PrintUserIndo(user);
      }
      else
      {
        cout << "Error do not Deleted User :<)";
      }
    }
    }
};