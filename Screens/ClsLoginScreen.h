#pragma once
#include <iostream>
#include <fstream>
#include "ClsDate.h"
#include "ClsScreen.h"
#include "ClsInputValdate.h"
#include "Globle.h"
#include "ClsMainScreen.h"
class ClsLoginScreen : protected ClsScreen
{

private:
  //*-----------save to file Date and time Login Screen -----------------------
  static string _RecordLineLoginRegister(string sepertor = "#//#")
  {
    return ClsDate::GetTimeAndDate() + sepertor + userGloble.getUserName() + sepertor + ClsUtil::EncryptText(userGloble.getPassword()) + sepertor + to_string(userGloble.getPermissions());
  }
  static void _SaveInfoLoginRegister()
  {
    fstream saveInfo;
    saveInfo.open("LoginRegister.txt", ios::app | ios::out);
    if (saveInfo.is_open())
      saveInfo << _RecordLineLoginRegister() << endl;

    saveInfo.close();
  }
  //*---------------------------------------------------------------------------
  static bool _Login()
  {

    string userName, password;
    bool loginFaild = false;
    short countFaild = 0;
    do
    {
      if (loginFaild)
      {
        countFaild++;
        cout << "\nInvaild Input,UserName/Password!!" << endl;
        cout << "You have " << 3 - countFaild << " Trials to Login." << endl;
      }
      if (countFaild == 3)
      {
        cout << "\nYour are Locked after 3 faild trials.";
        return false;
      }

      cout << "\nEnter User Name:";
      userName = ClsInputValdate::readString();
      cout << "\nEnter password :";
      password = ClsInputValdate::readString();
      userGloble = ClsUsers::find(userName, password);
      loginFaild = userGloble.isEmpty();

    } while (loginFaild);

    _SaveInfoLoginRegister();
    ClsMainScreen::showMainMenuScreen();
    return true;
  }

public:
  // static vector<string> getInfoLogin()
  // {
  //   return _LoadLoginRegister();
  // }
  static bool showLoginScreen()
  {
    system("cls");
    printHeader("\t Login Screen.");
    return _Login();
  }
  
};