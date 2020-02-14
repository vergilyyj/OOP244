// OOP244 Workshop 4: Constructors 
// File: Saiyan.cpp
// Version: 1.0
// Date: 2/6/2020
// Author: Ya Jian Yu
// Description:
// This file provide class and member function defination for Saiyan
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Saiyan.h"

using namespace std;

namespace sdds {
   bool Saiyan::isSuper() const {
      return m_super;
   }
   bool Saiyan::isValid() const {
      return  (m_name != nullptr && m_name[0] != '\0' && m_dob > 0 && m_dob < 2020 && m_power > 0);
   }
   void Saiyan::setEmpty() {
      m_name[0] = '\0';
      m_dob = 0;
      m_power = 0;
   }
   void Saiyan::display() const {
      if (isValid()) {
         cout << m_name << endl;
         cout << "DOB: " << m_dob << " Power: " << m_power << endl;
         cout << "Super Saiyan Ability: ";
         if (isSuper())
            cout << "Super Saiyan." << endl;
         else
            cout << "Not super Saiyan." << endl;
         cout << endl;
      }
      else
         cout << "Invalid Saiyan!" << endl;
   }
   void Saiyan::set(const char* name, int dob, int power, bool super) {
      if (strlen(name) > (MAX_NAME + 1)|| dob >=2020 || dob <=0 || power <=0) 
         setEmpty();
      else {
         strcpy(m_name, name);
         m_dob = dob;
         m_power = power;
         m_super = super;
      }
   }
   bool Saiyan::hasLost(const Saiyan& other) const {
      bool result;
      if (!isValid() || !other.isValid())
         result = false;
      else if (this->m_power <= other.m_power)
         result = true;
      else
         result = false;
      return result;
   }
   Saiyan::Saiyan() {
      setEmpty();
   }
   Saiyan::Saiyan(const char* name, int dob, int power) {
      if (name == nullptr || strlen(name) > (MAX_NAME + 1) || dob >= 2020 || dob <= 0 || power <= 0)
         setEmpty();
      else {
         strcpy(m_name, name);
         m_dob = dob;
         m_power = power;
         m_super = false;
      }
   }
   Saiyan::~Saiyan() {

   }
}