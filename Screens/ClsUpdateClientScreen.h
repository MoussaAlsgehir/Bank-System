#pragma once
#include <iostream>
#include "ClsScreen.h"
#include"ClsInputValdate.h"
#include"ClsBankClient.h"
class ClsUpdateClientScreen : protected ClsScreen
{

  static void _ReadClientInfo(ClsBankClient &bankClient)
  {

    cout << "\nEnter First Name:";
    bankClient.setFirstName(ClsInputValdate::readString());
    cout << "\nEnter Last Name:";
    bankClient.setLastName(ClsInputValdate::readString());
    cout << "\nEnter Email :";
    bankClient.setEmail(ClsInputValdate::readString());
    cout << "\nEnter Phone :";
    bankClient.setPhone(ClsInputValdate::readString());
    cout << "\nEnter PinCode :";
    bankClient.setPinConde(ClsInputValdate::readString());
    cout << "\nEnter Balance :";
    bankClient.setAccountBalance(ClsInputValdate::readDoubleNumber(""));
  }
  static void _PrintClient(ClsBankClient cbc)
  {
    cout << "\nClient Card:";
    cout << "\n------------------";
    cout << "\nFirstName    :" << cbc.getFirstName();
    cout << "\nLastName     :" << cbc.getLastName();
    cout << "\nFull Name    :" << cbc.fullName();
    cout << "\nEmail        :" << cbc.getEmail();
    cout << "\nPhone        :" << cbc.getPhone();
    cout << "\nAccountNumber:" << cbc.getAccountNumber();
    cout << "\nPassword     :" << cbc.getPinCode();
    cout << "\nBalance      :" << cbc.getAccountBalance();
    cout << "\n------------------\n";
  }

public:
 static void showUpdataClient()
  {
  
    if(!checkAccessRights(ClsUsers::enPermissions::enpUpdateClinet)){
      return;
    }
    
   printHeader("\tUpdate Client Screen.");
    cout << "Please Enter Client Account Number : ";

    string accountNumber = "";
    accountNumber = ClsInputValdate::readString();
    while (!ClsBankClient::isClientExist(accountNumber))
    {
      cout << "Account number is not found ,choose another one:";
      accountNumber = ClsInputValdate::readString();
    }

    ClsBankClient banckClient = ClsBankClient::find(accountNumber);
    _PrintClient(banckClient);
cout << "\n\nUpdate Client info:";
    cout << "\n\n---------------------";
    _ReadClientInfo(banckClient);
    ClsBankClient::enSaveResult saveResult;
    saveResult = banckClient.save();

    switch (saveResult)
    {
    case ClsBankClient::enSaveResult::svSucceeded:
    {
      cout << "\n Account Updated Successfly :-)\n";
      _PrintClient(banckClient);
      break;
    }
    case ClsBankClient::enSaveResult::svFaildEmptyObject:
    {
      cout << "\nError account was not saved becouse it's Empty.\n";
      break;
    }
    }
  }
};