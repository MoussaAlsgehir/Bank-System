#pragma once
#include <iostream>
#include <iomanip>
#include "ClsInputValdate.h"
#include "ClsScreen.h"
#include "ClsListClients.h"
#include "ClsAddNewClientScreen.h"
#include "ClsDeleteClientScreen.h"
#include "ClsUpdateClientScreen.h"
#include "ClsFindClientScreen.h"
#include "ClsTransactionsScreen.h"
#include "ClsMangeUsersScreen.h"
#include "ClsLoginRegisterScreen.h"
#include "ClsCurrencyExchangeScreen.h"
#include "Globle.h"
class ClsMainScreen : protected ClsScreen
{

private:
  enum enMainMenuOptions

  {
    enShowAllClient = 1,
    enAddNewClient = 2,
    enDeleteClient = 3,
    enUpdateClient = 4,
    enFindClinet = 5,
    enTransactionsMenu = 6,
    enMangeMenu = 7,
    enLoginRegister = 8,
    enCurrencyExchange = 9,
    enExit = 10
  };
  static void _GoBacktoMainMenu()
  {
    cout << "Press any key go to back to main menu.";
    system("pause>0");
    ClsMainScreen::showMainMenuScreen();
  }
  static void _ShowShowAllClientsScreen()
  {
    // cout << "welcome All Client\n";
    ClsListClients::showListClient();
  }

  static void _ShowAddNewClientScreen()
  {
    // cout << "welcome Add New Client\n";
    CLsAddNewClientScreen::showAddNewClient();
  }
  static void _ShowDeletClientScreen()
  {
    // cout << "welcome Delete Client\n";
    ClsDeleteClientScreen::showDeleteClient();
  }
  static void _ShowUpdateClientScreen()
  {
    // cout << "welcome Update Client\n";
    ClsUpdateClientScreen::showUpdataClient();
  }
  static void _FindClientScreen()
  {
    // cout << "welcome Find Client\n";
    ClsFindClientScreen::showFindClient();
  }
  static void _ShowTransactionScreen()
  {
    // cout << "welcome Transaction Screen\n";
    ClsTransactionsScreen::showTransactionScreen();
  }

  static void _ShowMangeMneuScreen()
  {
    // cout << "welcome Mange Menu\n";
    CLsMangeUsersScreen::showScreenMangeUser();
  }
  static void _ShowLoginRegisterScreen()
  {
    // cout<<"Welcome LoginRegister.";
    ClsLoginRegisterScreen::showListLoginRegister();
  }
  static void _ShowCurrencyExchangeScreen()
  {
    // cout<<"Welcome Currency Screen ."<<endl;
    ClsCurrencyExcange::showCurrencyExcangeScreen();
  }
  static void _Logout()
  {
    userGloble = ClsUsers::find("", "");
  }
  static void _PerformMainMenuOption(enMainMenuOptions option)
  {
    switch (option)
    {
    case enMainMenuOptions::enShowAllClient:
    {
      system("cls");
      _ShowShowAllClientsScreen();
      _GoBacktoMainMenu();
      break;
    }
    case enMainMenuOptions::enAddNewClient:
    {
      system("cls");
      _ShowAddNewClientScreen();
      _GoBacktoMainMenu();
      break;
    }
    case enMainMenuOptions::enDeleteClient:
    {
      system("cls");
      _ShowDeletClientScreen();
      _GoBacktoMainMenu();
      break;
    }
    case enMainMenuOptions::enUpdateClient:
    {
      system("cls");
      _ShowUpdateClientScreen();
      _GoBacktoMainMenu();
      break;
    }
    case enMainMenuOptions::enFindClinet:
    {
      system("cls");
      _FindClientScreen();
      _GoBacktoMainMenu();
      break;
    }
    case enMainMenuOptions::enMangeMenu:
    {
      system("cls");
      _ShowMangeMneuScreen();
      _GoBacktoMainMenu();
      break;
    }
    case enMainMenuOptions::enTransactionsMenu:
    {
      system("cls");
      _ShowTransactionScreen();
      _GoBacktoMainMenu();
      break;
    }
    case enMainMenuOptions::enLoginRegister:
    {
      system("cls");
      _ShowLoginRegisterScreen();
      _GoBacktoMainMenu();
      break;
    }

    case enMainMenuOptions::enCurrencyExchange:
    {
      system("cls");
      _ShowCurrencyExchangeScreen();
      _GoBacktoMainMenu();
      break;
    }
    case enMainMenuOptions::enExit:
    {
      system("cls");
      _Logout();
      break;
    }
    }
  }
  static short _ReadMainMenuOption()
  {
    cout << setw(35) << left << " " << "Choose what do you want to do ? [1->10]?";
    return ClsInputValdate::readShortNumberBetween(1, 10, "Enter number between 1 to 10: ");
  }

public:
  static void showMainMenuScreen()
  {
    system("cls");
    printHeader("\t\tMain Screen");
    cout << setw(35) << left << " " << "====================================\n";
    cout << setw(35) << left << " " << "         Main Menue Screen          \n";
    cout << setw(35) << left << " " << "====================================\n";
    cout << setw(35) << left << " " << "\t[1] Show Client List.\n";
    cout << setw(35) << left << " " << "\t[2] Add New Client.\n";
    cout << setw(35) << left << " " << "\t[3] Delete Client.\n";
    cout << setw(35) << left << " " << "\t[4] Update Client Info.\n";
    cout << setw(35) << left << " " << "\t[5] Find Client.\n";
    cout << setw(35) << left << " " << "\t[6] TransActions.\n";
    cout << setw(35) << left << " " << "\t[7] Mange Users.\n";
    cout << setw(35) << left << " " << "\t[8] Login Register.\n";
    cout << setw(35) << left << " " << "\t[9] Currency Exchange.\n";
    cout << setw(35) << left << " " << "\t[10] Logout.\n";
    cout << setw(35) << left << " " << "====================================\n";
    _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
  }
};
