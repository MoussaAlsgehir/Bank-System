#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "ClsPerson.h"
#include "ClsString.h"
#include"ClsUtil.h"
using namespace std;

class ClsUsers : public ClsPerson
{
private:
  enum enMode
  {
    EmptyMode = 0,
    UpdateMode = 1,
    AddNewMode = 2
  };
  enMode _Mode;

  string _UserName;
  string _Password;
  int _Permissions;
  bool _MarkedForDeleted = false;

  static ClsUsers _GetEmptyUserObject()
  {
    return ClsUsers(enMode::EmptyMode, "", "", "", "", "", "", 0);
  }

  static ClsUsers _ConvertLineToUserObject(string line, string delm = "#//#")
  {
    vector<string> _User = ClsString::Split(line, delm);
    return ClsUsers(enMode::UpdateMode, _User[0], _User[1], _User[2], _User[3], _User[4], ClsUtil::DecryptText(_User[5]), stoi(_User[6]));
  }

  static void _AddDataLineToFile(string line)
  {
    fstream addline;
    addline.open("Users.txt", ios::app | ios::out);
    if (addline.is_open())
      addline << line << endl;
    addline.close();
  }

  static vector<ClsUsers> _LoadUserDataFromFile()
  {
    fstream readFile;
    readFile.open("Users.txt", ios::in);
    vector<ClsUsers> _vUser;

    if (readFile.is_open())
    {
      string line;
      while (getline(readFile, line))
      {
        ClsUsers user = _ConvertLineToUserObject(line);
        _vUser.push_back(user);
      }
      readFile.close();
    }
    return _vUser;
  }

  void _AddNew()
  {
    _AddDataLineToFile(_ConvertUserObjectToLine(*this));
  }

  static string _ConvertUserObjectToLine(ClsUsers user, string sperator = "#//#")
  {
    string line = "";
    line += user.getFirstName() + sperator;
    line += user.getLastName() + sperator;
    line += user.getEmail() + sperator;
    line += user.getPhone() + sperator;
    line += user._UserName + sperator;
    line += ClsUtil::EncryptText(user._Password) + sperator;
    line += to_string(user._Permissions);
    return line;
  }

  void _Update()
  {
    vector<ClsUsers> _User;
    _User = _LoadUserDataFromFile();

    for (ClsUsers &user : _User)
    {
      if (user._UserName == _UserName)
      {
        user = *this;
        break;
      }
    }
    _SaveUsersDataToFile(_User);
  }

  static void _SaveUsersDataToFile(vector<ClsUsers> user)
  {
    fstream writeFile;
    writeFile.open("Users.txt", ios::out);
    if (writeFile.is_open())
    {
      for (ClsUsers &i : user)
      {
        writeFile << _ConvertUserObjectToLine(i) << endl;
      }
    }
    writeFile.close();
  }

  static void _SaveUsersDataToFileAfterDelete(vector<ClsUsers> user)
  {
    fstream writeFile;
    writeFile.open("Users.txt", ios::out);
    if (writeFile.is_open())
    {
      for (ClsUsers &i : user)
      {
        if (i._MarkedForDeleted != true)
          writeFile << _ConvertUserObjectToLine(i) << endl;
      }
    }
    writeFile.close();
  }

public:
  enum enPermissions
  {
    eAll = -1,
    enpShowClients = 1,
    enpAddClient = 2,
    enpDeleteClient = 4,
    enpUpdateClinet = 8,
    enpFindClient = 16,
    enpTreansactions = 32,
    enpLoginRegister=64,
    enpMangeUser = 128
  };
  ClsUsers(enMode mode, string firstName, string lastName, string email, string phone, string userName, string password, int permissions) : ClsPerson(firstName, lastName, email, phone)
  {

    _Mode = mode;
    _UserName = userName;
    _Password = password;
    _Permissions = permissions;
  }

  bool isEmpty()
  {
    return _Mode == enMode::EmptyMode;
  }

  void setUserName(string userName)
  {
    _UserName = userName;
  }

  string getUserName()
  {
    return _UserName;
  }

  void setPassword(string password)
  {
    _Password = password;
  }

  string getPassword()
  {
    return _Password;
  }

  void setPermissions(int permissions)
  {

    _Permissions = permissions;
  }
  int getPermissions()
  {
    return _Permissions;
  }

  void setMarkedForDeleted(bool markedForDelete)
  {
    _MarkedForDeleted = markedForDelete;
  }

  bool getMarkedForDeleted()
  {
    return _MarkedForDeleted;
  }

  static ClsUsers find(string userName)
  {

    vector<ClsUsers> vUser;
    fstream readFile;
    readFile.open("Users.txt", ios::in);
    string line;
    if (readFile.is_open())
    {
      while (getline(readFile, line))
      {
        ClsUsers user = _ConvertLineToUserObject(line);

        if (user._UserName == userName)
        {
          readFile.close();
          return user;
        }
        vUser.push_back(user);
      }
    }
    readFile.close();

    return _GetEmptyUserObject();
  }

  static ClsUsers find(string userName, string password)
  {

    vector<ClsUsers> vUser;
    fstream readFile;
    readFile.open("Users.txt", ios::in);
    string line;
    if (readFile.is_open())
    {
      while (getline(readFile, line))
      {
        ClsUsers user = _ConvertLineToUserObject(line);

        if (user._UserName == userName && user._Password == password)
        {
          readFile.close();
          return user;
        }
        vUser.push_back(user);
      }
    }
    readFile.close();

    return _GetEmptyUserObject();
  }

  static bool isUserExist(string userName)
  {

    ClsUsers user = ClsUsers::find(userName);
    return !(user.isEmpty());
  }

  enum enSaveResult
  {
    svFaildEmptyObject = 0,
    svSucceeded = 1,
    svFaildAccountNuberExists = 2
  };

  enSaveResult
  save()
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
      if (isUserExist(_UserName))
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

  bool Delete()
  {
    vector<ClsUsers> _User;
    _User = _LoadUserDataFromFile();

    for (ClsUsers &cbc : _User)
    {
      if (cbc._UserName == this->_UserName)
      {
        cbc._MarkedForDeleted = true;
        break;
      }
    }
    _SaveUsersDataToFileAfterDelete(_User);
    *this = _GetEmptyUserObject();
    return true;
  }

  static ClsUsers getAddNewUserObject(string userName)
  {
    return ClsUsers(enMode::AddNewMode, "", "", "", "", userName, "", 0);
  }
  static vector<ClsUsers> getListUser()
  {
    return _LoadUserDataFromFile();
  }
  bool checkAccessPermissions(enPermissions permissions)
  {
    if (this->_Permissions == enPermissions::eAll)
      return true;

    if ((permissions & this->_Permissions) == permissions)
      return true;
    else
      return false;
 
    }
};