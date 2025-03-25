#pragma once
#include <iostream>
#include <vector>
#include "ClsScreen.h"
#include "ClsCurrency.h"
#include "ClsInputValdate.h"
class ClsFindCurrencyScreen : protected ClsScreen
{

private:
  enum eFind
  {
    eFindByCode = 1,
    eFindByCountry = 2
  };
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
  static short _ReadFindOption()
  {
    cout << "Find By: [1] Code or [2] Country ? ";
    return ClsInputValdate::readShortNumberBetween(1, 2, "\nInputVaild ,enter number  1 or 2 :");
  }
  static void _GetFindByCode()
  {
    cout << "\nEnter Currency Code:";
    string code = ClsInputValdate::readString();
    while (!ClsCurrency::isCurrencyExist(code))
    {
      cout << "\nInput invaild ,Please another one choose:";
      code = ClsInputValdate::readString();
    }
    ClsCurrency currency = ClsCurrency::FindByCurrenyCode(code);
    _PrintCurrency(currency);
  }
  static void _GetFindByCountry()
  {
    cout << "\nEnter Country Currency:";
    string country = ClsInputValdate::readString();
    ClsCurrency currency = ClsCurrency::FindByCurrenyName(country);
    while (currency.isEmpty())
    {
      cout << "\nInput invaild ,Please another one choose:";
      country = ClsInputValdate::readString();
      currency = ClsCurrency::FindByCurrenyCode(country);
    }
    _PrintCurrency(currency);
  }

public:
  static void showFindCurrencyScreen()
  {
    printHeader("\t Find Currency Screen.");
    short option = _ReadFindOption();
    switch ((eFind)option)
    {
    case eFind::eFindByCode:
    {
      _GetFindByCode();
      break;
    }
    case eFind::eFindByCountry:
    {
      _GetFindByCountry();
      break;
    }
    }
  }
};
