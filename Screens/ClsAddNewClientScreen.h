#pragma once
#include<iostream>
#include"ClsScreen.h"
#include"ClsMainScreen.h"
class CLsAddNewClientScreen: protected ClsScreen
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
 static void showAddNewClient()
  {

    if (!checkAccessRights(ClsUsers::enPermissions::enpAddClient))
    {
      return;
    }

    printHeader("\tAdd new CLient.");
    string accountNumber = "";
    cout << "please Enter Account Number :";
    accountNumber = ClsInputValdate::readString();
    while (ClsBankClient::isClientExist(accountNumber))
    {
      cout << "\n Account Number Is Already Used, Choose another one :";
      accountNumber = ClsInputValdate::readString();
    }
    ClsBankClient addClient = ClsBankClient::getAddNewClientObject(accountNumber);

  _ReadClientInfo(addClient);

    ClsBankClient::enSaveResult saveResult;
    saveResult = addClient.save();

    switch (saveResult)
    {
    case ClsBankClient::enSaveResult::svSucceeded:
    {
      cout << "\n Account Updated Successfly :-)\n";
      _PrintClient(addClient);
      break;
    }
    case ClsBankClient::enSaveResult::svFaildEmptyObject:
    {
      cout << "\nError account was not saved becouse it's Empty.\n";
      break;
    }
    case ClsBankClient::enSaveResult::svFaildAccountNuberExists:
    {
      cout << "this Account number used .";
      break;
    }
    }
  }
};
