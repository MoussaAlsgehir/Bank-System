#pragma once
#include "ClsScreen.h"
#include <iostream>
#include <vector>
#include "ClsUsers.h"

class ClsUpdateUserScreen : protected ClsScreen
{

  static void _ReadUserInfo(ClsUsers &user)
  {
    cout << "\nEnter First Name :";
    user.setFirstName(ClsInputValdate::readString());
    cout << "\nEnter Last Name :";
    user.setLastName(ClsInputValdate::readString());
    cout << "\nEnter  Email:";
    user.setEmail(ClsInputValdate::readString());
    cout << "\nEnter  Phone:";
    user.setPhone(ClsInputValdate::readString());
    cout << "\nEnter  Password:";
    user.setPassword(ClsInputValdate::readString());
    user.setPermissions(_ReadPermissions());
  }
  static int _ReadPermissions()
  {
    cout << "do you want to full access to user ? y/n?";
    char answer;
    cin >> answer;
    int permissions = 0;
    if (answer == 'y' || answer == 'Y')
      return ClsUsers::enPermissions::eAll;

    cout << "\nEnter Persmissions User :\n";
    cout << "access to show Clients Info? y/n :";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
      permissions += ClsUsers::enPermissions::enpShowClients;

    cout << "access to Add Clients Info? y/n :";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
      permissions += ClsUsers::enPermissions::enpAddClient;

    cout << "access to Delete Clients Info? y/n :";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
      permissions += ClsUsers::enPermissions::enpDeleteClient;

    cout << "access to Updete Clients Info? y/n :";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
      permissions += ClsUsers::enPermissions::enpUpdateClinet;

    cout << "access to Find Clients Info? y/n :";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
      permissions += ClsUsers::enPermissions::enpFindClient;

    cout << "access to Treansactions ? y/n :";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
      permissions += ClsUsers::enPermissions::enpTreansactions;

    cout << "access to Login Register  ? y/n :";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
      permissions += ClsUsers::enPermissions::enpLoginRegister;

    cout << "access to Mange Users  ? y/n :";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
      permissions += ClsUsers::enPermissions::enpMangeUser;

    return permissions;
  }
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
  static void showUpdateScreen()
  {

    printHeader("\t Update User Screen.");
    cout<<"\nEnter User Name :";
    string userName = ClsInputValdate::readString();
    while (!ClsUsers::isUserExist(userName))
    {
      cout << "\n user Name [ " << userName << " ]is not Exist before Please enter userName new:";
      userName = ClsInputValdate::readString();
    }
    ClsUsers user = ClsUsers::find(userName);
    _PrintUserIndo(user);
    cout << "\n Are you sure from Update User " << userName << "? y/n";
    char answer;
    cin >> answer;
    if (answer ==  'y' || answer == 'Y')
    {
      cout << "User Info :";
      _ReadUserInfo(user);

      ClsUsers::enSaveResult saveResult;
      saveResult = user.save();
      switch (saveResult)
      {

      case ClsUsers::enSaveResult::svSucceeded:
      {
        cout << "\nSuccess Opertion Update User :-)";
        _PrintUserIndo(user);
        break;
      }
      case ClsUsers::enSaveResult::svFaildAccountNuberExists:
      {
        cout << "\nthis user is update before";

        break;
      }
      case ClsUsers::enSaveResult::svFaildEmptyObject:
      {
        cout << "\nError in Opertion Update user  :-(";
        break;
      }
    }
      }
  }
};