#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsListCurrencyScreen.h"
#include "CLsFindCurrencyScreen.h"
#include "ClsUpdateCurrencyScreen.h"
#include "CLsCurrencyCalculatorScreen.h"
class ClsCurrencyExcange : protected ClsScreen
{

private:
  enum enCurrency
  {
    encListCurrency = 1,
    encFindCurrency = 2,
    encUpdateCurrency = 3,
    encCurrencyCalculator = 4,
    encMainMenu = 5
  };

  static short _ReadCurrencyoption()
  {
    cout << setw(35) << left << " " << "Choose what do you want to do ? [1->5]?";
    return ClsInputValdate::readShortNumberBetween(1, 5, "\nEnter number between 1 to 5: ");
  }

  static void _ShowListCurrenciesScreen()
  {
    // cout << "welcome in List Currency.\n";
    ClsListCurrencyScreen::showListCurrencyScreen();
  }
  static void _ShowFindCurrencyScreen()
  {
    // cout << "welcome in Find Currency.\n";
    ClsFindCurrencyScreen::showFindCurrencyScreen();
  }
  static void _ShowUpdateCurrencyScreen()
  {
    // cout << "welcome in Update Currency.\n";
    ClsUpdateCurrencyScreen::showUpdateCurrencyScreen();
  }
  static void _ShowCurrencyCalculatorScreen()
  {
    // cout << "welcome in  Currency Calculator.\n";
    ClsCurrencyCalculatorScreen::showCalculatorCurrencyScreen();
  }
  static void _GoBackCurrencyMain()
  {
    cout << "\nPress any key go to back to main Currency Exchange.";
    system("pause>0");
    ClsCurrencyExcange::showCurrencyExcangeScreen();
  }
  static void _PerformCurrencyExchangeOption(enCurrency option)
  {
    switch (option)
    {
    case enCurrency::encListCurrency:
    {
      system("cls");
      _ShowListCurrenciesScreen();
      _GoBackCurrencyMain();
      break;
    }

    case enCurrency::encFindCurrency:
    {
      system("cls");
      _ShowFindCurrencyScreen();
      _GoBackCurrencyMain();
      break;
    }
    case enCurrency::encUpdateCurrency:
    {
      system("cls");
      _ShowUpdateCurrencyScreen();
      _GoBackCurrencyMain();
      break;
    }
    case enCurrency::encCurrencyCalculator:
    {
      system("cls");
      _ShowCurrencyCalculatorScreen();
      _GoBackCurrencyMain();
      break;
    }
    case enCurrency::encMainMenu:
    {
      //! no implemention.....
    }
    }
  }

public:
  static void showCurrencyExcangeScreen()
  {

    system("cls");
    printHeader("    Currency Exchange Main Screen.");
    cout << setw(35) << left << " " << "====================================\n";
    cout << setw(35) << left << " " << "    Currency Exchange Main Screen          \n";
    cout << setw(35) << left << " " << "====================================\n";
    cout << setw(35) << left << " " << "\t[1] List Currencies.\n";
    cout << setw(35) << left << " " << "\t[2] Find Currency.\n";
    cout << setw(35) << left << " " << "\t[3] Update Rate.\n";
    cout << setw(35) << left << " " << "\t[4] Currency Calculator.\n";
    cout << setw(35) << left << " " << "\t[5] Main Menu\n";
    cout << setw(35) << left << " " << "====================================\n";

    _PerformCurrencyExchangeOption((enCurrency)_ReadCurrencyoption());
  }
};