#pragma once
#include <iostream>
#include "ClsInputValdate.h"
#include "ClsCurrency.h"
#include "ClsScreen.h"
class ClsCurrencyCalculatorScreen : protected ClsScreen
{
private:
  static void _PrintCurrency(ClsCurrency currency, string titleHeder = "\nCurrency Card : \n")
  {
    cout << titleHeder;
    cout << "--------------------------------\n";
    cout << "\nCountry       : " << currency.getCountry();
    cout << "\nCurrency Code : " << currency.getCurrencyCode();
    cout << "\nCurrency Name : " << currency.getCurrencyName();
    cout << "\nRate(1$)      : " << currency.getRate();
    cout << "\n--------------------------------\n";
  }

  static ClsCurrency _ReadCurrency(string message)
  {
    cout << message;
    string code = ClsInputValdate::readString();
    while (!ClsCurrency::isCurrencyExist(code))
    {
      cout << "\ninput wrong ,Please Enter another one:";
      code = ClsInputValdate::readString();
    }
    return ClsCurrency::FindByCurrenyCode(code);
  }
  static double _CalculatorToUsd(ClsCurrency c, double amount)
  {
    return (amount / c.getRate());
  }
  static double _CalculatorToCurrencyTwo(ClsCurrency c, double amount)
  {
    return (amount * c.getRate());
  }

public:
  static void showCalculatorCurrencyScreen()
  {
    char answer = 'n';
    do
    {
      system("cls");
      printHeader("\t Calculator Currency Screen.");

      ClsCurrency currency1 = _ReadCurrency("Please Enter Currency One Code:");
      ClsCurrency currency2 = _ReadCurrency("Please Enter Currency Two Code:");
      double amount = 0.0;
      if (currency2.getCurrencyCode() == "USD")
      {
        cout << "\nEnter amount to convert :";
        amount = ClsInputValdate::readDoubleNumber("\nWrong !!");
        _PrintCurrency(currency1, "\nConvert From :\n");
        cout << amount << currency1.getCurrencyCode() << " = " << _CalculatorToUsd(currency1, amount) << currency2.getCurrencyCode();
      }
      else
      {

        cout << "\nEnter amount to convert :";
        amount = ClsInputValdate::readDoubleNumber("\nWrong !!");
        _PrintCurrency(currency1, "\nConvert From :\n");
        double USD = _CalculatorToUsd(currency1, amount);
        cout << amount << currency1.getCurrencyCode() << " = " << USD << "USD" << endl;
        _PrintCurrency(currency1, "\nConvert To :\n");

        cout << amount << currency1.getCurrencyCode() << " = " << _CalculatorToCurrencyTwo(currency2, USD) << currency2.getCurrencyCode();
      }
      cout << "\ndo you want to perform another Calculator?y/n?";
      cin >> answer;
    } while (answer == 'y' || answer == 'Y');
  }
};