#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "ClsString.h"
#include "ClsPerson.h"

class ClsBankClient : public ClsPerson
{

  public:
    struct infoRecord
    {

      string date, s_Client, d_Client, userOpertor;
      double amount, s_AmountClients, d_AmountClients;
    };

private:
  enum enMode
  {
    EmptyMode = 0,
    UpdateMode = 1,
    AddNewMode = 2
  };
  enMode _Mode;
  string _AccountNumber;
  string _PinCode;
  float _AccountBalance;
  bool _MarkedForDelete = false;
  void _AddNew()
  {
    _AddDataLineToFile(_ConvertObjectToLine(*this));
  }

  static infoRecord _ConvertRecordToStruct(vector<string> temp)
  {
    infoRecord line;
    line.date = temp[0];
    line.s_Client = temp[1];
    line.d_Client = temp[2];
    line.amount = stod(temp[3]);
    line.s_AmountClients = stod(temp[4]);
    line.d_AmountClients = stod(temp[5]);
    line.userOpertor = temp[6];
    return line;
  }
  static vector<infoRecord> _LoadRegisterLogTransfer()
  {
    vector<infoRecord> tempinfo;
    fstream readInfo;
    readInfo.open("TransferLog.txt", ios::in);
    if (readInfo.is_open())
    {
      string line;
      vector<string> splitRecord;
      while (getline(readInfo, line))
      {
        splitRecord = ClsString::Split(line, "#//#");
        tempinfo.push_back(_ConvertRecordToStruct(splitRecord));
        splitRecord.clear();
      }
      readInfo.close();
    }
    return tempinfo;
  }
  static void _AddDataLineToFile(string line)
  {
    fstream addline;
    addline.open("Client.txt", ios::app | ios::out);
    if (addline.is_open())
      addline << line << endl;
    addline.close();
  }
  static ClsBankClient _ConvertLineToCLientObject(string line, string delm = "#//#")
  {
    vector<string> bankClinet = ClsString::Split(line, delm);
    return ClsBankClient(enMode::UpdateMode, bankClinet[0], bankClinet[1], bankClinet[2], bankClinet[3], bankClinet[4], bankClinet[5], stof(bankClinet[6]));
  }
  static ClsBankClient _GetEmptyClientObject()
  {
    return ClsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
  }
  static vector<ClsBankClient> _LoadClientDataFromFile()
  {
    fstream readFile;
    readFile.open("Client.txt", ios::in);
    vector<ClsBankClient> _vClient;

    if (readFile.is_open())
    {
      string line;
      while (getline(readFile, line))
      {
        ClsBankClient bankClient = _ConvertLineToCLientObject(line);
        _vClient.push_back(bankClient);
      }
      readFile.close();
    }
    return _vClient;
  }
  void _Update()
  {
    vector<ClsBankClient> _vClients;
    _vClients = _LoadClientDataFromFile();

    for (ClsBankClient &bankClient : _vClients)
    {
      if (bankClient._AccountNumber == _AccountNumber)
      {
        bankClient = *this;
        break;
      }
    }
    _SaveClientsDataToFile(_vClients);
  }
  static void _SaveClientsDataToFile(vector<ClsBankClient> bankClient)
  {
    fstream writeFile;
    writeFile.open("Client.txt", ios::out);
    if (writeFile.is_open())
    {
      for (ClsBankClient &i : bankClient)
      {
        writeFile << _ConvertObjectToLine(i) << endl;
      }
    }
    writeFile.close();
  }
  static void _SaveClientsDataToFileAfterDelete(vector<ClsBankClient> bankClient)
  {
    fstream writeFile;
    writeFile.open("Client.txt", ios::out);
    if (writeFile.is_open())
    {
      for (ClsBankClient &i : bankClient)
      {
        if (i._MarkedForDelete != true)
          writeFile << _ConvertObjectToLine(i) << endl;
      }
    }
    writeFile.close();
  }

  static string _ConvertObjectToLine(ClsBankClient bankClient, string sperator = "#//#")
  {
    string line = "";
    line += bankClient.getFirstName() + sperator;
    line += bankClient.getLastName() + sperator;
    line += bankClient.getEmail() + sperator;
    line += bankClient.getPhone() + sperator;
    line += bankClient._AccountNumber + sperator;
    line += bankClient._PinCode + sperator;
    line += to_string(bankClient._AccountBalance);
    return line;
  }

public:
  ClsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string pincode, float accountBalance)
      : ClsPerson(firstName, lastName, email, phone)
  {
    _Mode = mode;
    _AccountNumber = accountNumber;
    _AccountBalance = accountBalance;
    _PinCode = pincode;
  }

  bool isEmpty()
  {
    return _Mode == enMode::EmptyMode;
  }
  //*Read only property Account Number...
  string getAccountNumber()
  {
    return _AccountNumber;
  }

  void setPinConde(string pinCode)
  {
    _PinCode = pinCode;
  }
  string getPinCode()
  {
    return _PinCode;
  }

  void setAccountBalance(float accountBalance)
  {
    _AccountBalance = accountBalance;
  }
  float getAccountBalance()
  {
    return _AccountBalance;
  }

  // void print()
  // {
  //   cout << "\nClient Card:";
  //   cout << "\n------------------";
  //   cout << "\nFirstName    :" << getFirstName();
  //   cout << "\nLastName     :" << getLastName();
  //   cout << "\nFull Name    :" << fullName();
  //   cout << "\nEmail        :" << getEmail();
  //   cout << "\nPhone        :" << getPhone();
  //   cout << "\nAccountNumber:" << _AccountNumber;
  //   cout << "\nPassword     :" << _PinCode;
  //   cout << "\nBalance      :" << _AccountBalance;
  //   cout << "\n------------------\n";
  // }

  static ClsBankClient find(string accountNumber)
  {

    vector<ClsBankClient> vClient;
    fstream readFile;
    readFile.open("Client.txt", ios::in);
    string line;
    if (readFile.is_open())
    {
      while (getline(readFile, line))
      {
        ClsBankClient bankCLient = _ConvertLineToCLientObject(line);

        if (bankCLient._AccountNumber == accountNumber)
        {
          readFile.close();
          return bankCLient;
        }
        vClient.push_back(bankCLient);
      }
    }
    readFile.close();

    return _GetEmptyClientObject();
  }

  static ClsBankClient find(string accountNumber, string pinCode)
  {

    vector<ClsBankClient> vClient;
    fstream readFile;
    readFile.open("Client.txt", ios::in);
    string line;
    if (readFile.is_open())
    {
      while (getline(readFile, line))
      {
        ClsBankClient bankCLient = _ConvertLineToCLientObject(line);

        if (bankCLient._AccountNumber == accountNumber && bankCLient._PinCode == pinCode)
        {
          readFile.close();
          return bankCLient;
        }
        vClient.push_back(bankCLient);
      }
    }
    readFile.close();

    return _GetEmptyClientObject();
  }

  static bool isClientExist(string accountNumber)
  {
    ClsBankClient bankClient = ClsBankClient::find(accountNumber);
    return !(bankClient.isEmpty());
  }

  enum enSaveResult
  {
    svFaildEmptyObject = 0,
    svSucceeded = 1,
    svFaildAccountNuberExists = 2
  };

  enSaveResult save()
  {

    switch (_Mode)
    {
    case enMode::EmptyMode:
    {
      if (isEmpty())
        return enSaveResult::svFaildEmptyObject;
    }
    case enMode::UpdateMode:
    {
      _Update();
      return enSaveResult::svSucceeded;
      break;
    }
    case enMode::AddNewMode:
    {
      if (isClientExist(_AccountNumber))
        return enSaveResult::svFaildAccountNuberExists;
      else
      {
        _AddNew();
        _Mode = enMode::UpdateMode;
        return enSaveResult::svSucceeded;
      }
      break;
    }
    }
  }

  static ClsBankClient getAddNewClientObject(string account)
  {
    return ClsBankClient(enMode::AddNewMode, "", "", "", "", account, "", 0);
  }

  bool Delete()
  {
    vector<ClsBankClient> _vClients;
    _vClients = _LoadClientDataFromFile();

    for (ClsBankClient &cbc : _vClients)
    {
      if (cbc._AccountNumber == this->_AccountNumber)
      {
        cbc._MarkedForDelete = true;
        break;
      }
    }
    _SaveClientsDataToFileAfterDelete(_vClients);
    *this = _GetEmptyClientObject();
    return true;
  }

  static vector<ClsBankClient> getListClient()
  {
    return _LoadClientDataFromFile();
  }
  static double getTotalBalance(vector<ClsBankClient> cbc)
  {
    double total = 0.0;
    for (ClsBankClient &cbc1 : cbc)
    {
      total += cbc1.getAccountBalance();
    }
    return total;
  }
  void deposit(double amount)
  {
    _AccountBalance += amount;
    save();
  }
  bool withdraw(double amount)
  {

    if (amount > _AccountBalance)
    {
      return false;
    }
    else
    {
      _AccountBalance -= amount;
      save();
    }

    return true;
  }
  bool transfer(double amount, ClsBankClient &distinationsClient)
  {
    if (amount > _AccountBalance)
    {
      return false;
    }

    withdraw(amount);
    distinationsClient.deposit(amount);
    return true;
  }

  static vector<infoRecord> getInfoOpertionsTransfer(){
  return _LoadRegisterLogTransfer();
}
};
