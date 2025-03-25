#pragma once
#include <iostream>
#include <fstream>
#include "ClsString.h"

#include <vector>
using namespace std;
class ClsCurrency
{

private:
  enum enMode
  {
    EmptyMode = 0,
    UpdateMode = 1
  };

  enMode _Mode;
  string _Country;
  string _CurrencyCode;
  string _CurrencyName;
  double _Rate;

  static ClsCurrency _ConvertlineRecordToCurrencyObject(string lineRecord)
  {
    vector<string> tempInfo = ClsString::Split(lineRecord, "#//#");
    return ClsCurrency(enMode::UpdateMode, tempInfo[0], tempInfo[1], tempInfo[2], stod(tempInfo[3]));
  }
  static ClsCurrency _GetEmptyCurrencyObject()
  {
    return ClsCurrency(enMode::EmptyMode, "", "", "", 0.0);
  }
  static vector<ClsCurrency> _LoadDateCurrencyFormFile()
  {
    vector<ClsCurrency> infoCurrency;
    fstream readInfo;
    readInfo.open("Currenses.txt", ios::in);
    if (readInfo.is_open())
    {
      string line;
      ClsCurrency currency;
      while (getline(readInfo, line))
      {
        currency = _ConvertlineRecordToCurrencyObject(line);
        infoCurrency.push_back(currency);
      }

      readInfo.close();
    }
    return infoCurrency;
  }
  static string _ConvertObjectCurrencyToLineRecord(ClsCurrency currency, string sperator = "#//#")
  {
    return currency.getCountry() + sperator + currency.getCurrencyCode() + sperator + currency.getCurrencyName() + sperator + to_string(currency.getRate());
  }
  static void _SaveDateCurrencyToFile(vector<ClsCurrency> infoCurrency)
  {
    fstream saveDate;
    saveDate.open("Currenses.txt", ios::out);
    if (saveDate.is_open())
    {
      for (ClsCurrency &i : infoCurrency)
      {
        saveDate << _ConvertObjectCurrencyToLineRecord(i) << endl;
      }
      saveDate.close();
    }
  }
  void _UpDate()
  {

    vector<ClsCurrency> infoCurrency = _LoadDateCurrencyFormFile();

    for (ClsCurrency &i : infoCurrency)
    {
      if (i.getCurrencyCode() == getCurrencyCode())
      {
        i = *this;
        break;
      }
    }
    _SaveDateCurrencyToFile(infoCurrency);
  }

public:
  //*parmeter constructer*//
  ClsCurrency(){}
  ClsCurrency(enMode mode, string country, string currencyCode, string currencyName, double rate)
  {
    _Mode = mode;
    _Country = country;
    _CurrencyCode = currencyCode;
    _CurrencyName = currencyName;
    _Rate = rate;
  }

  //! REad Only proprty
  string getCountry()
  {
    return _Country;
  }

  string getCurrencyCode()
  {
    return _CurrencyCode;
  }

  string getCurrencyName()
  {
    return  _CurrencyName;
  }

  double getRate()
  {
    return _Rate;
  }

  void upDateRate(double newRate)
  {
    _Rate = newRate;
    _UpDate();
  }
  bool isEmpty()
  {
    return (_Mode == enMode::EmptyMode);
  }

  static ClsCurrency FindByCurrenyCode(string currencyCode)
  {
    currencyCode = ClsString::UpperAllString(currencyCode);
    fstream searchInfo;
    searchInfo.open("Currenses.txt", ios::in);
    if (searchInfo.is_open())
    {
      string line;
      ClsCurrency currency;
      while (getline(searchInfo, line))
      {
        currency = _ConvertlineRecordToCurrencyObject(line);
        if (currency._CurrencyCode == currencyCode)
        {
          searchInfo.close();
          return currency;
        }
      }
    }
    searchInfo.close();
    return _GetEmptyCurrencyObject();
  }
  static ClsCurrency FindByCurrenyName(string country)
  {
    country = ClsString::UpperAllString(country);
    fstream searchInfo;
    searchInfo.open("Currenses.txt", ios::in);
    if (searchInfo.is_open())
    {
      string line;
      ClsCurrency currency;
      while (getline(searchInfo, line))
      {
        currency = _ConvertlineRecordToCurrencyObject(line);
        if (ClsString::UpperAllString(currency._Country) == country)
        {
          searchInfo.close();
          return currency;
        }
      }
    }
    searchInfo.close();
    return _GetEmptyCurrencyObject();
  }
  static bool isCurrencyExist(string currencyCode)
  {
    ClsCurrency currency = currency.FindByCurrenyCode(currencyCode);
    return !(currency.isEmpty());
  }
  static vector<ClsCurrency> getCurrencyList()
  {
    return _LoadDateCurrencyFormFile();
  }
};