#pragma once
#include <iostream>
#include <iomanip>
#include "ClsMainScreen.h"
#include "ClsScreen.h"
#include "ClsBankClient.h"
#include "ClsDepositScreen.h"
#include "ClsWithdrawScreen.h"
#include "ClsTotalBalanceScreen.h"
#include "ClsTransferScreen.h"
#include "ClsTransferLogScreen.h"
class ClsTransactionsScreen : protected ClsScreen
{

private:
  enum enTransactionsOptions
  {
    enDeposit = 1,
    enWithdraw = 2,
    enTotalBalance = 3,
    enTransfer = 4,
    enTransferLog = 5,
    enMainMenu = 6
  };

  static short _ReadTreansactionsOption()
  {
    cout << setw(35) << left << " " << "Choose what do you want to do ? [1->6]?";
    return ClsInputValdate::readShortNumberBetween(1, 6, "Enter number between 1 to 6: ");
  }
  static void _GoBackTransactionsMenu()
  {
    cout << "\nPress any key go to back to Transactions Menu.";
    system("pause>0");
    ClsTransactionsScreen::showTransactionScreen();
  }

  //*staps :no implement ...

  static void _ShowDepositScreen()
  {
    cout << "welcome Deposit.\n";
    ClsDepositScreen::showDepositScreen();
  }

  static void _ShowWithdrawScreen()
  {
    // cout << "welcome withDraw.\n";
    ClsWithdrawScreen::showWithdrawScreen();
  }

  static void _ShowTotalBalanceScreen()
  {
    // cout << "welcome total Balance.\n";
    ClsTotalBalanceScreen::showTotalBalanceScreen();
  }

  static void _ShowTransferScreen()
  {
    // cout << "welcome Transfer Screen.\n";
    CLsTransferScreen::showTransferScreen();
  }
  static void _ShowTransferLogScreen()
  {
    // cout << "welcome Transfer log Screen.\n";
    ClsTransferLogScreen::showTrasferLogScreen();
  }

  static void _PerformTransactionsOptions(enTransactionsOptions optionTrans)
  {
    switch (optionTrans)
    {
    case enTransactionsOptions::enDeposit:
    {
      system("cls");
      _ShowDepositScreen();
      _GoBackTransactionsMenu();
      break;
    }
    case enTransactionsOptions::enWithdraw:
    {
      system("cls");
      _ShowWithdrawScreen();
      _GoBackTransactionsMenu();
      break;
    }
    case enTransactionsOptions::enTransfer:
    {
      system("cls");
      _ShowTransferScreen();
      _GoBackTransactionsMenu();

      break;
    }
    case enTransactionsOptions::enTotalBalance:
    {
      system("cls");
      _ShowTotalBalanceScreen();
      _GoBackTransactionsMenu();
      break;
    }
    case enTransactionsOptions::enTransferLog:
    {
      system("cls");
      _ShowTransferLogScreen();
      _GoBackTransactionsMenu();
      break;
    }
    case enTransactionsOptions::enMainMenu:
    {
      //! no impementions things...
    }
    }
  }

public:
  static void showTransactionScreen()
  {

    system("cls");

    if (!checkAccessRights(ClsUsers::enPermissions::enpTreansactions))
    {
      return;
    }
    printHeader("\tTransactions Menu Screen.");

    cout << setw(35) << left << "" << "===================================\n";
    cout << setw(35) << left << "" << "     Menue Transactions Screen          \n";
    cout << setw(35) << left << "" << "===================================\n";
    cout << setw(35) << left << "" << "\t[1] Deposit.\n";
    cout << setw(35) << left << "" << "\t[2] Withdraw.\n";
    cout << setw(35) << left << "" << "\t[3] Total Balances.\n";
    cout << setw(35) << left << "" << "\t[4] Transfer.\n";
    cout << setw(35) << left << "" << "\t[5] Transfer Log.\n";
    cout << setw(35) << left << "" << "\t[6] Main Meune Screen.\n";
    cout << setw(35) << left << "" << "===================================\n";
    _PerformTransactionsOptions((enTransactionsOptions)_ReadTreansactionsOption());
  }
};