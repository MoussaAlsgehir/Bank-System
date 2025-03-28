// ProgrammingAdivces.com
// Mohammed Abu-Hadhoud

#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string>
#include "ClsString.h"
#include<ctime>
using namespace std;

class ClsDate
{

private:
  short _Day = 1;
  short _Month = 1;
  short _Year = 1900;

public:
  ClsDate()
  {
    time_t t = time(0);
    tm *now = localtime(&t);
    _Day = now->tm_mday;
    _Month = now->tm_mon + 1;
    _Year = now->tm_year + 1900;
  }

  ClsDate(string sDate)
  {

    vector<string> vDate;
    vDate = ClsString::Split(sDate, "/");

    _Day = stoi(vDate[0]);
    _Month = stoi(vDate[1]);
    _Year = stoi(vDate[2]);
  }

  ClsDate(short Day, short Month, short Year)
  {

    _Day = Day;
    _Month = Month;
    _Year = Year;
  }

  ClsDate(short DateOrderInYear, short Year)
  {
    // This will construct a date by date order in year
    ClsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
    _Day = Date1._Day;
    _Month = Date1._Month;
    _Year = Date1._Year;
  }

  void SetDay(short Day)
  {
    _Day = Day;
  }

  short GetDay()
  {
    return _Day;
  }
  // __deClspec(property(get = GetDay, put = SetDay)) short Day;

  void SetMonth(short Month)
  {
    _Month = Month;
  }

  short GetMonth()
  {
    return _Month;
  }
  // __deClspec(property(get = GetMonth, put = SetMonth)) short Month;

  void SetYear(short Year)
  {
    _Year = Year;
  }

  short GetYear()
  {
    return _Year;
  }
  // __deClspec(property(get = GetYear, put = SetYear)) short Year;

  void Print()
  {
    cout << DateToString() << endl;
  }

  static ClsDate GetSystemDate()
  {
    // system date
    time_t t = time(0);
    tm *now = localtime(&t);

    short Day, Month, Year;

    Year = now->tm_year + 1900;
    Month = now->tm_mon + 1;
    Day = now->tm_mday;

    return ClsDate(Day, Month, Year);
  }

  static bool IsValidDate(ClsDate Date)
  {

    if (Date._Day < 1 || Date._Day > 31)
      return false;

    if (Date._Month < 1 || Date._Month > 12)
      return false;

    if (Date._Month == 2)
    {
      if (isLeapYear(Date._Year))
      {
        if (Date._Day > 29)
          return false;
      }
      else
      {
        if (Date._Day > 28)
          return false;
      }
    }

    short DaysInMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);

    if (Date._Day > DaysInMonth)
      return false;

    return true;
  }

  bool IsValid()
  {
    return IsValidDate(*this);
  }

  static string DateToString(ClsDate Date)
  {
    return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
  }

  string DateToString()
  {
    return DateToString(*this);
  }

  static bool isLeapYear(short Year)
  {

    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
  }

  bool isLeapYear()
  {
    return isLeapYear(_Year);
  }

  static short NumberOfDaysInAYear(short Year)
  {
    return isLeapYear(Year) ? 365 : 364;
  }

  short NumberOfDaysInAYear()
  {
    return NumberOfDaysInAYear(_Year);
  }

  static short NumberOfHoursInAYear(short Year)
  {
    return NumberOfDaysInAYear(Year) * 24;
  }

  short NumberOfHoursInAYear()
  {
    return NumberOfHoursInAYear(_Year);
  }

  static int NumberOfMinutesInAYear(short Year)
  {
    return NumberOfHoursInAYear(Year) * 60;
  }

  int NumberOfMinutesInAYear()
  {
    return NumberOfMinutesInAYear(_Year);
  }

  static int NumberOfSecondsInAYear(short Year)
  {
    return NumberOfMinutesInAYear(Year) * 60;
  }

  int NumberOfSecondsInAYear()
  {
    return NumberOfSecondsInAYear();
  }

  static short NumberOfDaysInAMonth(short Month, short Year)
  {

    if (Month < 1 || Month > 12)
      return 0;

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
  }

  short NumberOfDaysInAMonth()
  {
    return NumberOfDaysInAMonth(_Month, _Year);
  }

  static short NumberOfHoursInAMonth(short Month, short Year)
  {
    return NumberOfDaysInAMonth(Month, Year) * 24;
  }

  short NumberOfHoursInAMonth()
  {
    return NumberOfDaysInAMonth(_Month, _Year) * 24;
  }

  static int NumberOfMinutesInAMonth(short Month, short Year)
  {
    return NumberOfHoursInAMonth(Month, Year) * 60;
  }

  int NumberOfMinutesInAMonth()
  {
    return NumberOfHoursInAMonth(_Month, _Year) * 60;
  }

  static int NumberOfSecondsInAMonth(short Month, short Year)
  {
    return NumberOfMinutesInAMonth(Month, Year) * 60;
  }

  int NumberOfSecondsInAMonth()
  {
    return NumberOfMinutesInAMonth(_Month, _Year) * 60;
  }

  static short DayOfWeekOrder(short Day, short Month, short Year)
  {
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
  }

  short DayOfWeekOrder()
  {
    return DayOfWeekOrder(_Day, _Month, _Year);
  }

  static string DayShortName(short DayOfWeekOrder)
  {
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return arrDayNames[DayOfWeekOrder];
  }

  static string DayShortName(short Day, short Month, short Year)
  {

    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return arrDayNames[DayOfWeekOrder(Day, Month, Year)];
  }

  string DayShortName()
  {

    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)];
  }

  static string MonthShortName(short MonthNumber)
  {
    string Months[12] = {"Jan", "Feb", "Mar",
                         "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep",
                         "Oct", "Nov", "Dec"};

    return (Months[MonthNumber - 1]);
  }

  string MonthShortName()
  {

    return MonthShortName(_Month);
  }

  static void PrintMonthCalendar(short Month, short Year)
  {
    int NumberOfDays;

    // Index of the day from 0 to 6
    int current = DayOfWeekOrder(1, Month, Year);

    NumberOfDays = NumberOfDaysInAMonth(Month, Year);

    // Print the current month name
    printf("\n  _______________%s_______________\n\n",
           MonthShortName(Month).c_str());

    // Print the columns
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print appropriate spaces
    int i;
    for (i = 0; i < current; i++)
      printf("     ");

    for (int j = 1; j <= NumberOfDays; j++)
    {
      printf("%5d", j);

      if (++i == 7)
      {
        i = 0;
        printf("\n");
      }
    }

    printf("\n  _________________________________\n");
  }

  void PrintMonthCalendar()
  {
    PrintMonthCalendar(_Month, _Year);
  }

  static void PrintYearCalendar(int Year)
  {
    printf("\n  _________________________________\n\n");
    printf("           Calendar - %d\n", Year);
    printf("  _________________________________\n");

    for (int i = 1; i <= 12; i++)
    {
      PrintMonthCalendar(i, Year);
    }

    return;
  }

  void PrintYearCalendar()
  {
    printf("\n  _________________________________\n\n");
    printf("           Calendar - %d\n", _Year);
    printf("  _________________________________\n");

    for (int i = 1; i <= 12; i++)
    {
      PrintMonthCalendar(i, _Year);
    }

    return;
  }

  static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
  {

    short TotalDays = 0;

    for (int i = 1; i <= Month - 1; i++)
    {
      TotalDays += NumberOfDaysInAMonth(i, Year);
    }

    TotalDays += Day;

    return TotalDays;
  }

  short DaysFromTheBeginingOfTheYear()
  {

    short TotalDays = 0;

    for (int i = 1; i <= _Month - 1; i++)
    {
      TotalDays += NumberOfDaysInAMonth(i, _Year);
    }

    TotalDays += _Day;

    return TotalDays;
  }

  static ClsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
  {

    ClsDate Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;

    Date._Year = Year;
    Date._Month = 1;

    while (true)
    {
      MonthDays = NumberOfDaysInAMonth(Date._Month, Year);

      if (RemainingDays > MonthDays)
      {
        RemainingDays -= MonthDays;
        Date._Month++;
      }
      else
      {
        Date._Day = RemainingDays;
        break;
      }
    }

    return Date;
  }

  void AddDays(short Days)
  {

    short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
    short MonthDays = 0;

    _Month = 1;

    while (true)
    {
      MonthDays = NumberOfDaysInAMonth(_Month, _Year);

      if (RemainingDays > MonthDays)
      {
        RemainingDays -= MonthDays;
        _Month++;

        if (_Month > 12)
        {
          _Month = 1;
          _Year++;
        }
      }
      else
      {
        _Day = RemainingDays;
        break;
      }
    }
  }

  static bool IsDate1BeforeDate2(ClsDate Date1, ClsDate Date2)
  {
    return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
  }

  bool IsDateBeforeDate2(ClsDate Date2)
  {
    // note: *this sends the current object :-)
    return IsDate1BeforeDate2(*this, Date2);
  }

  static bool IsDate1EqualDate2(ClsDate Date1, ClsDate Date2)
  {
    return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
  }

  bool IsDateEqualDate2(ClsDate Date2)
  {
    return IsDate1EqualDate2(*this, Date2);
  }

  static bool IsLastDayInMonth(ClsDate Date)
  {

    return (Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year));
  }

  bool IsLastDayInMonth()
  {

    return IsLastDayInMonth(*this);
  }

  static bool IsLastMonthInYear(short Month)
  {
    return (Month == 12);
  }

  static ClsDate AddOneDay(ClsDate Date)
  {
    if (IsLastDayInMonth(Date))
    {
      if (IsLastMonthInYear(Date._Month))
      {
        Date._Month = 1;
        Date._Day = 1;
        Date._Year++;
      }
      else
      {
        Date._Day = 1;
        Date._Month++;
      }
    }
    else
    {
      Date._Day++;
    }

    return Date;
  }

  void AddOneDay()

  {
    *this = AddOneDay(*this);
  }

  static void SwapDates(ClsDate &Date1, ClsDate &Date2)
  {

    ClsDate TempDate;
    TempDate = Date1;
    Date1 = Date2;
    Date2 = TempDate;
  }

  static int GetDifferenceInDays(ClsDate Date1, ClsDate Date2, bool IncludeEndDay = false)
  {
    // this will take care of negative diff
    int Days = 0;
    short SawpFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
      // Swap Dates
      SwapDates(Date1, Date2);
      SawpFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
      Days++;
      Date1 = AddOneDay(Date1);
    }

    return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
  }

  int GetDifferenceInDays(ClsDate Date2, bool IncludeEndDay = false)
  {
    return GetDifferenceInDays(*this, Date2, IncludeEndDay);
  }

  static short CalculateMyAgeInDays(ClsDate DateOfBirth)
  {
    return GetDifferenceInDays(DateOfBirth, ClsDate::GetSystemDate(), true);
  }
  // above no need to have nonstatic function for the object because it does not depend on any data from it.

  static ClsDate IncreaseDateByOneWeek(ClsDate &Date)
  {

    for (int i = 1; i <= 7; i++)
    {
      Date = AddOneDay(Date);
    }

    return Date;
  }

  void IncreaseDateByOneWeek()
  {
    IncreaseDateByOneWeek(*this);
  }

  ClsDate IncreaseDateByXWeeks(short Weeks, ClsDate &Date)
  {

    for (short i = 1; i <= Weeks; i++)
    {
      Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
  }

  void IncreaseDateByXWeeks(short Weeks)
  {
    IncreaseDateByXWeeks(Weeks, *this);
  }

  ClsDate IncreaseDateByOneMonth(ClsDate &Date)
  {

    if (Date._Month == 12)
    {
      Date._Month = 1;
      Date._Year++;
    }
    else
    {
      Date._Month++;
    }

    // last check day in date should not exceed max days in the current month
    //  example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
    //  be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
    if (Date._Day > NumberOfDaysInCurrentMonth)
    {
      Date._Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
  }

  void IncreaseDateByOneMonth()
  {

    IncreaseDateByOneMonth(*this);
  }

  ClsDate IncreaseDateByXDays(short Days, ClsDate &Date)
  {

    for (short i = 1; i <= Days; i++)
    {
      Date = AddOneDay(Date);
    }
    return Date;
  }

  void IncreaseDateByXDays(short Days)
  {

    IncreaseDateByXDays(Days, *this);
  }

  ClsDate IncreaseDateByXMonths(short Months, ClsDate &Date)
  {

    for (short i = 1; i <= Months; i++)
    {
      Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
  }

  void IncreaseDateByXMonths(short Months)
  {
    IncreaseDateByXMonths(Months, *this);
  }

  static ClsDate IncreaseDateByOneYear(ClsDate &Date)
  {
    Date._Year++;
    return Date;
  }

  void IncreaseDateByOneYear()
  {
    IncreaseDateByOneYear(*this);
  }

  ClsDate IncreaseDateByXYears(short Years, ClsDate &Date)
  {
    Date._Year += Years;
    return Date;
  }

  void IncreaseDateByXYears(short Years)
  {
    IncreaseDateByXYears(Years);
  }

  ClsDate IncreaseDateByOneDecade(ClsDate &Date)
  {
    // Period of 10 years
    Date._Year += 10;
    return Date;
  }

  void IncreaseDateByOneDecade()
  {
    IncreaseDateByOneDecade(*this);
  }

  ClsDate IncreaseDateByXDecades(short Decade, ClsDate &Date)
  {
    Date._Year += Decade * 10;
    return Date;
  }

  void IncreaseDateByXDecades(short Decade)
  {
    IncreaseDateByXDecades(Decade, *this);
  }

  ClsDate IncreaseDateByOneCentury(ClsDate &Date)
  {
    // Period of 100 years
    Date._Year += 100;
    return Date;
  }

  void IncreaseDateByOneCentury()
  {
    IncreaseDateByOneCentury(*this);
  }

  ClsDate IncreaseDateByOneMillennium(ClsDate &Date)
  {
    // Period of 1000 years
    Date._Year += 1000;
    return Date;
  }

  ClsDate IncreaseDateByOneMillennium()
  {
    IncreaseDateByOneMillennium(*this);
  }

  static ClsDate DecreaseDateByOneDay(ClsDate Date)
  {
    if (Date._Day == 1)
    {
      if (Date._Month == 1)
      {
        Date._Month = 12;
        Date._Day = 31;
        Date._Year--;
      }
      else
      {

        Date._Month--;
        Date._Day = NumberOfDaysInAMonth(Date._Month, Date._Year);
      }
    }
    else
    {
      Date._Day--;
    }

    return Date;
  }

  void DecreaseDateByOneDay()
  {
    DecreaseDateByOneDay(*this);
  }

  static ClsDate DecreaseDateByOneWeek(ClsDate &Date)
  {

    for (int i = 1; i <= 7; i++)
    {
      Date = DecreaseDateByOneDay(Date);
    }

    return Date;
  }

  void DecreaseDateByOneWeek()
  {
    DecreaseDateByOneWeek(*this);
  }

  static ClsDate DecreaseDateByXWeeks(short Weeks, ClsDate &Date)
  {

    for (short i = 1; i <= Weeks; i++)
    {
      Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
  }

  void DecreaseDateByXWeeks(short Weeks)
  {
    DecreaseDateByXWeeks(Weeks, *this);
  }

  static ClsDate DecreaseDateByOneMonth(ClsDate &Date)
  {

    if (Date._Month == 1)
    {
      Date._Month = 12;
      Date._Year--;
    }
    else
      Date._Month--;

    // last check day in date should not exceed max days in the current month
    //  example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
    //  be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
    if (Date._Day > NumberOfDaysInCurrentMonth)
    {
      Date._Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
  }

  void DecreaseDateByOneMonth()
  {
    DecreaseDateByOneMonth(*this);
  }

  static ClsDate DecreaseDateByXDays(short Days, ClsDate &Date)
  {

    for (short i = 1; i <= Days; i++)
    {
      Date = DecreaseDateByOneDay(Date);
    }
    return Date;
  }

  void DecreaseDateByXDays(short Days)
  {
    DecreaseDateByXDays(Days, *this);
  }

  static ClsDate DecreaseDateByXMonths(short Months, ClsDate &Date)
  {

    for (short i = 1; i <= Months; i++)
    {
      Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
  }

  void DecreaseDateByXMonths(short Months)
  {
    DecreaseDateByXMonths(Months, *this);
  }

  static ClsDate DecreaseDateByOneYear(ClsDate &Date)
  {

    Date._Year--;
    return Date;
  }

  void DecreaseDateByOneYear()
  {
    DecreaseDateByOneYear(*this);
  }

  static ClsDate DecreaseDateByXYears(short Years, ClsDate &Date)
  {

    Date._Year -= Years;
    return Date;
  }

  void DecreaseDateByXYears(short Years)
  {
    DecreaseDateByXYears(Years, *this);
  }

  static ClsDate DecreaseDateByOneDecade(ClsDate &Date)
  {
    // Period of 10 years
    Date._Year -= 10;
    return Date;
  }

  void DecreaseDateByOneDecade()
  {
    DecreaseDateByOneDecade(*this);
  }

  static ClsDate DecreaseDateByXDecades(short Decades, ClsDate &Date)
  {

    Date._Year -= Decades * 10;
    return Date;
  }

  void DecreaseDateByXDecades(short Decades)
  {
    DecreaseDateByXDecades(Decades, *this);
  }

  static ClsDate DecreaseDateByOneCentury(ClsDate &Date)
  {
    // Period of 100 years
    Date._Year -= 100;
    return Date;
  }

  void DecreaseDateByOneCentury()
  {
    DecreaseDateByOneCentury(*this);
  }

  static ClsDate DecreaseDateByOneMillennium(ClsDate &Date)
  {
    // Period of 1000 years
    Date._Year -= 1000;
    return Date;
  }

  void DecreaseDateByOneMillennium()
  {
    DecreaseDateByOneMillennium(*this);
  }

  static short IsEndOfWeek(ClsDate Date)
  {
    return DayOfWeekOrder(Date._Day, Date._Month, Date._Year) == 6;
  }

  short IsEndOfWeek()
  {
    return IsEndOfWeek(*this);
  }

  static bool IsWeekEnd(ClsDate Date)
  {
    // Weekends are Fri and Sat
    short DayIndex = DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
    return (DayIndex == 5 || DayIndex == 6);
  }

  bool IsWeekEnd()
  {
    return IsWeekEnd(*this);
  }

  static bool IsBusinessDay(ClsDate Date)
  {
    // Weekends are Sun,Mon,Tue,Wed and Thur

    /*
   short DayIndex = DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
   return  (DayIndex >= 5 && DayIndex <= 4);
    */

    // shorter method is to invert the IsWeekEnd: this will save updating code.
    return !IsWeekEnd(Date);
  }

  bool IsBusinessDay()
  {
    return IsBusinessDay(*this);
  }

  static short DaysUntilTheEndOfWeek(ClsDate Date)
  {
    return 6 - DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
  }

  short DaysUntilTheEndOfWeek()
  {
    return DaysUntilTheEndOfWeek(*this);
  }

  static short DaysUntilTheEndOfMonth(ClsDate Date1)
  {

    ClsDate EndOfMontDate;
    EndOfMontDate._Day = NumberOfDaysInAMonth(Date1._Month, Date1._Year);
    EndOfMontDate._Month = Date1._Month;
    EndOfMontDate._Year = Date1._Year;

    return GetDifferenceInDays(Date1, EndOfMontDate, true);
  }

  short DaysUntilTheEndOfMonth()
  {
    return DaysUntilTheEndOfMonth(*this);
  }

  static short DaysUntilTheEndOfYear(ClsDate Date1)
  {

    ClsDate EndOfYearDate;
    EndOfYearDate._Day = 31;
    EndOfYearDate._Month = 12;
    EndOfYearDate._Year = Date1._Year;

    return GetDifferenceInDays(Date1, EndOfYearDate, true);
  }

  short DaysUntilTheEndOfYear()
  {
    return DaysUntilTheEndOfYear(*this);
  }

  // i added this method to calculate business days between 2 days
  static short CalculateBusinessDays(ClsDate DateFrom, ClsDate DateTo)
  {

    short Days = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo))
    {
      if (IsBusinessDay(DateFrom))
        Days++;

      DateFrom = AddOneDay(DateFrom);
    }

    return Days;
  }

  static short CalculateVacationDays(ClsDate DateFrom, ClsDate DateTo)
  {
    /*short Days = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo))
    {
      if (IsBusinessDay(DateFrom))
        Days++;

      DateFrom = AddOneDay(DateFrom);
    }*/

    return CalculateBusinessDays(DateFrom, DateTo);
  }
  // above method is eough , no need to have method for the object

  static ClsDate CalculateVacationReturnDate(ClsDate DateFrom, short VacationDays)
  {

    short WeekEndCounter = 0;

    for (short i = 1; i <= VacationDays; i++)
    {

      if (IsWeekEnd(DateFrom))
        WeekEndCounter++;

      DateFrom = AddOneDay(DateFrom);
    }
    // to add weekends
    for (short i = 1; i <= WeekEndCounter; i++)
      DateFrom = AddOneDay(DateFrom);

    return DateFrom;
  }

  static bool IsDate1AfterDate2(ClsDate Date1, ClsDate Date2)
  {
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
  }

  bool IsDateAfterDate2(ClsDate Date2)
  {
    return IsDate1AfterDate2(*this, Date2);
  }

  enum enDateCompare
  {
    Before = -1,
    Equal = 0,
    After = 1
  };

  static enDateCompare CompareDates(ClsDate Date1, ClsDate Date2)
  {
    if (IsDate1BeforeDate2(Date1, Date2))
      return enDateCompare::Before;

    if (IsDate1EqualDate2(Date1, Date2))
      return enDateCompare::Equal;

    /* if (IsDate1AfterDate2(Date1,Date2))
       return enDateCompare::After;*/

    // this is faster
    return enDateCompare::After;
  }

  enDateCompare CompareDates(ClsDate Date2)
  {
    return CompareDates(*this, Date2);
  }
  static string GetTimeAndDate()
  {
    time_t t = time(0);
    tm *now = localtime(&t);
    return DateToString(ClsDate()) + " - " + to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
  }
};
