#pragma once
#include <iostream>
#include <limits>
#include "ClsDate.h"

using namespace std;

class ClsInputValdate
{

public:
  static bool isNumberBetween(int numBetween, int from, int to)
  {
    return (numBetween >= from && numBetween <= to);
  }

  static bool isNumberBetween(double numBetween, double from, double to)
  {
    return (numBetween >= from && numBetween <= to);
  }

  static bool isDateBetween(ClsDate isDateBetween, ClsDate from, ClsDate to)
  {
    return (ClsDate::IsDate1AfterDate2(isDateBetween, from) && !ClsDate::IsDate1AfterDate2(isDateBetween, to)) || (ClsDate::IsDate1AfterDate2(isDateBetween, to) && !ClsDate::IsDate1AfterDate2(isDateBetween, from));
  }

  static int readIntNumber(string messageError)
  {
    int num;
    while (true)
    {

      cin >> num;
      if (cin.fail())
      {
        cout << messageError;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // تجاهل الإدخال غير الصالح
      }
      else
      {
        break;
      }
    }
    return num;
  }
  static int readIntNumberBetween(int from, int to, string messageError)
  {
    int num;
    while (true)
    {
      num = readIntNumber("Formate Error");
      if (isNumberBetween(num, from, to))
      {
        cout << messageError << endl;
      }
      else
      {
        break;
      }
    }
    return num;
  }

  static short readShortNumber(string messageError="Invaild input ,Enter agin.")
  {
    short num;
    while (true)
    {

      cin >> num;
      if (cin.fail())
      {
        cout << messageError;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // تجاهل الإدخال غير الصالح
      }
      else
      {
        break;
      }
    }
    return num;
  }

  static short readShortNumberBetween(short from, short to, string messageError)
  {
    short num;
    while (true)
    {
      num = readShortNumber();
      if (!isNumberBetween(num, from, to))
      {
        cout << messageError << endl;
      }
      else
      {
        break;
      }
    }
    return num;
  }

  //*-------------------------------------------------------------------------------------------
  static double readDoubleNumber(string messageError)
  {
    double num;
    while (true)
    {

      cin >> num;
      if (cin.fail())
      {
        cout << messageError;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // تجاهل الإدخال غير الصالح
      }
      else
      {
        break;
      }
    }
    return num;
  }
  static double readDoubleNumberBetween(double from, double to, string messageError)
  {
    double num;
    while (true)
    {
      num = readIntNumber("Formate Error");
      if(isNumberBetween(num, from, to)) 
      { cout << messageError << endl;} 
      else{
        break;
      }
    }
    return num;
  }

  static string readString()
  {
    string str;
    getline(cin >> ws, str);
    return str;
  }
  //*-------------------------------------------------------------------------------------------
  static bool isVaildDate(ClsDate date)
  {
    ClsDate::IsValidDate(date);
  }

  //*-------------------------------------------------------------------------------------------
//! convert number to rext string 
  
static string TextNumber(long long num)
  {
    string belowTwenty[20] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string thousands[6] = {"", "hundreds", "thousand", "million", "billion"};
    if (num >= 0 && num < 20)
      return belowTwenty[num] + " ";
    else if (num % 10 == 0 && num >= 20 && num < 100)
      return tens[num / 10] + " ";
    else if (num % 10 != 0 && num >= 20 && num < 100)
      return TextNumber((num / 10) * 10) + TextNumber(num % 10);
    else if (num % 100 == 0 && num >= 100 && num < 1000)
      return TextNumber(num / 100) + thousands[1] + " ";
    else if (num % 100 != 0 && num >= 100 && num < 1000)
      return TextNumber((num / 100) * 100) + TextNumber(num % 100);
    else if (num % 1000 == 0 && num >= 1000 && num < 1000000)
      return TextNumber(num / 1000) + thousands[2] + " ";
    else if (num % 1000 != 0 && num >= 1000 && num < 1000000)
      return TextNumber((num / 1000) * 1000) + TextNumber(num % 1000);
    else if (num % 1000000 == 0 && num >= 1000000 && num < 1000000000)
      return TextNumber(num / 1000000) + thousands[3] + " ";
    else if (num % 1000000 != 0 && num >= 1000000 && num < 1000000000)
      return TextNumber((num / 1000000) * 1000000) + TextNumber(num % 1000000);
    else if (num % 1000000000 == 0 && num >= 1000000000)
      return TextNumber(num / 1000000000) + thousands[4] + " ";
    else if (num % 1000000000 != 0 && num >= 1000000000)
      return TextNumber((num / 1000000000) * 1000000000) + TextNumber(num % 1000000000);
    else
    {
      return "";
    }
  }
};