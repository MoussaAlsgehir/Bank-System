#pragma once
#include <iostream>
#include <iomanip>
#include "ClsInputValdate.h"
#include "ClsScreen.h"
#include "ClsListUserScreen.h"
#include "ClsAddNewUser.h"
#include "ClsDeleteUserScreen.h"
#include "ClsUpdateUserScreen.h"
#include "ClsFindUserScreen.h"
class CLsMangeUsersScreen : protected ClsScreen
{

private:
  enum enMangeUsersOptions
  {
    enListUsers = 1,
    enAddUser = 2,
    enDleteUser = 3,
    enUpdateUser = 4,
    enFindUser = 5,
    enMainMenu = 6
  };
  static void _GoBacktoMangeUsersMenu()
  {
    cout << "\nPress any key go to back to Mange Users Menu.\n";
    system("pause>0");
    CLsMangeUsersScreen::showScreenMangeUser();
  }
  static short _ReadMangeUsersOption()
  {
    cout << setw(35) << left << " " << "Choose what do you want to do ? [1->6]?";
    return ClsInputValdate::readShortNumberBetween(1, 6, "Enter number between 1 to 8 : ");
  }

  static void _ShowListUsersScreen()
  {
    // cout<<"welcome to List Users\n";
    ClsListUserScreen::ShowListUserScreen();
  }
  static void _ShowAddUserScreen()
  {
    // cout << "welcome to Add User \n";
    ClsAddNewUserScreen::showAddNewUserScreen();
  }
  static void _ShowDeleteUserScreen()
  {
    //!   cout << "welcome to Delete User\n";
    ClsDeleteUserScreen::showDeleteUserScreen();
  }
  static void _ShowUpdateUserScreen()
  {
    // cout << "welcome to Update User";
    ClsUpdateUserScreen::showUpdateScreen();
  }
  static void _ShowFindUserScreen()
  {
    // cout << "welcome to Find user";
    ClsFindUserScreen::showFindUserScreen();
  
  }
  static void _PerformMangeUsersMenuOption(enMangeUsersOptions option)
  {
    switch (option)
    {
    case enMangeUsersOptions::enListUsers:
    {
      system("cls");
      _ShowListUsersScreen();
      _GoBacktoMangeUsersMenu();
      break;
    }
    case enMangeUsersOptions::enAddUser:
    {
      system("cls");
      _ShowAddUserScreen();
      _GoBacktoMangeUsersMenu();
      break;
    }
    case enMangeUsersOptions::enDleteUser:
    {
      system("cls");
      _ShowDeleteUserScreen();
      _GoBacktoMangeUsersMenu();
      break;
    }
    case enMangeUsersOptions::enUpdateUser:
    {
      system("cls");
      _ShowUpdateUserScreen();
      _GoBacktoMangeUsersMenu();
      break;
    }
    case enMangeUsersOptions::enFindUser:
    {
      system("cls");
      _ShowFindUserScreen();
      _GoBacktoMangeUsersMenu();
      break;
    }
    case enMangeUsersOptions::enMainMenu:
    {
      //*no implements ...
    }
    }
  }

public:
  static void showScreenMangeUser()
  {

    if (!checkAccessRights(ClsUsers::enPermissions::enpMangeUser))
    {
      return;
    }
    system("cls");
    printHeader("\tMange Users Screen.");
    cout << setw(35) << left << "" << "===================================\n";
    cout << setw(35) << left << "" << "    Mange Users Menue Screen         \n";
    cout << setw(35) << left << "" << "===================================\n";
    cout << setw(35) << left << "" << "\t[1] List Users.\n";
    cout << setw(35) << left << "" << "\t[2] Add New User.\n";
    cout << setw(35) << left << "" << "\t[3] Delete User.\n";
    cout << setw(35) << left << "" << "\t[4] Update User.\n";
    cout << setw(35) << left << "" << "\t[5] Find User.\n";
    cout << setw(35) << left << "" << "\t[6] Main Meune Screen.\n";
    cout << setw(35) << left << "" << "===================================\n";
    _PerformMangeUsersMenuOption((enMangeUsersOptions)_ReadMangeUsersOption());
  }
};