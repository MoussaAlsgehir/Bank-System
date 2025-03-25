#pragma once
#include <iostream>
#include <string>
using namespace std;
class ClsPerson
{

private:
  string _LastName;
  string _FirstName;
  string _Email;
  string _Phone;

public:
  ClsPerson(string firstName, string lastName, string email, string phone)
  {
    _LastName = lastName;
    _FirstName = firstName;
    _Email = email;
    _Phone = phone;
  }

  void setLastName(string lastName){
    _LastName=lastName;
  }
  string getLastName(){
    return _LastName;

  }

  void setFirstName(string firstName)
  {
    _FirstName = firstName;
  }
  string getFirstName()
  {
    return _FirstName;
  }

  void setEmail(string email)
  {
    _Email = email;
  }
  string getEmail()
  {
    return _Email;
  }

  void setPhone(string phone)
  {
    _Phone = phone;
  }
  string getPhone()
  {
    return _Phone;
  }

  string fullName(){
    return _FirstName + " " + _LastName;
  }
  
};