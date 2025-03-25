#pragma once
#include <iostream>
#include "ClsScreen.h"
#include <vector>
#include "ClsCurrency.h"
#include "ClsInputValdate.h"

class ClsUpdateCurrencyScreen : protected ClsScreen
{

private:
  static void _PrintCurrency(ClsCurrency currency)
  {
    cout << "\nCurrency Card : \n";
    cout << "--------------------------------\n";
    cout << "\nCountry       : " << currency.getCountry();
    cout << "\nCurrency Code : " << currency.getCurrencyCode();
    cout << "\nCurrency Name : " << currency.getCurrencyName();
    cout << "\nRate(1$)      : " << currency.getRate();
    cout << "\n--------------------------------\n";
  }

public:
  static void showUpdateCurrencyScreen()
  {
    printHeader("\t Update Currency Screen.");
    cout << "\nEnter Currency Code :";
    string code = ClsInputValdate::readString();
    while (!ClsCurrency::isCurrencyExist(code))
    {
      cout << "\nCurrency code not Found ,Please Enter another one:";
      code = ClsInputValdate::readString();
    }
    ClsCurrency currency = ClsCurrency::FindByCurrenyCode(code);
    _PrintCurrency(currency);
    char answer;
    cout << "\nAre you sure you want to Update Currency Rate ?Y/N";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
      cout << "\nPlease Enter Rate Currency New:";
      double rateNew = ClsInputValdate::readDoubleNumber("\nInput Wrong!!");
      currency.upDateRate(rateNew);
      cout << "\nCurrency New Rate :";
      _PrintCurrency(currency);
    }
  }
};