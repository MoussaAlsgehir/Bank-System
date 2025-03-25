#pragma once
#include <iostream>
#include <iomanip>
#include "ClsUsers.h"
#include "Globle.h"
#include"ClsDate.h"
using namespace std;

class ClsScreen
{

public:
  static void printHeader(string title, string subTitle = "")
  {

    cout << setw(35) << left << " " << "------------------------------------\n";
    cout << setw(35) << left << " " << title << endl;
    if (subTitle != "")
      cout << setw(35) << left << " " << subTitle << endl;

    cout << setw(35) << left << " " << "------------------------------------\n";

    cout << setw(35) << left << " " << "User :" << userGloble.getUserName() << endl;

    cout << setw(35) << left << " "<<"Date :"<<ClsDate::DateToString(ClsDate())<<"\n\n\n";
  }

  static bool checkAccessRights(ClsUsers::enPermissions permissions)
  {

    if (!userGloble.checkAccessPermissions(permissions))
    {
      printHeader("Access Denid! Contect your Admin.");

      return false;
    }
    else
    {
      return true;
    }
  }
};