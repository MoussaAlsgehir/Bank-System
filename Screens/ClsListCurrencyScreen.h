#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsCurrency.h"
class ClsListCurrencyScreen : protected ClsScreen
{

private:
  static void _PrintInfoCurrencyList(vector<ClsCurrency> currencys)
  {
    for (ClsCurrency &i : currencys)
      cout << "|" << setw(20) << left << i.getCountry() << "| " << setw(15) << left << i.getCurrencyCode() << "| " << setw(45) << left << i.getCurrencyName() << "| " << setw(24) << left << i.getRate() << "|\n";
  }

public:
  static void showListCurrencyScreen()
  {
    vector<ClsCurrency> currencys = ClsCurrency::getCurrencyList();
    string title = "\t List Currency Screen.";
    string subTitle = "\t      (" + to_string(currencys.size()) + ") Currency(s).";
    printHeader(title, subTitle);

    cout << "----------------------------------------------------------------------------------------------------------------\n";
    cout << "|" << setw(20) << left << "Country " << "| " << setw(15) << left << "Code " << "| " << setw(45) << left << "Name " << "| " << setw(24) << left << "Rate(1$)" << "|\n";
    cout << "----------------------------------------------------------------------------------------------------------------\n";
    if (currencys.size() == 0)
    {
      cout << "\nnot Found Currency \n";
    }
    else
    {
      _PrintInfoCurrencyList(currencys);
    }
    cout << "----------------------------------------------------------------------------------------------------------------\n";
  }
};
