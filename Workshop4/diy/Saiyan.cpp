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
      m_name = nullptr;
      m_dob = 0;
      m_power = 0;
      m_level = 0;
   }
   void Saiyan::display() const {
      if (isValid()) {
         cout << m_name << endl;
         cout << "DOB: " << m_dob << " Power: " << m_power << endl;
         cout << "Super Saiyan Ability: ";
         if (isSuper()) {
            cout << "Super Saiyan." << endl;
            cout << "Super Saiyan level is: " << m_level;
         }
         else
            cout << "Not super Saiyan." << endl;
            cout << endl;
      }
      else
         cout << "Invalid Saiyan!" << endl;
   }
   void Saiyan::set(const char* name, int dob, int power, int level, bool super) {
      if (name == nullptr || strlen(name) > (MAX_NAME + 1) || dob >= 2020 || dob <= 0 || power <= 0) {
         delete[] m_name;
         setEmpty();
      }
      else {
         if (m_name != nullptr) {
            delete[] m_name;
            m_name = nullptr;
         }
         m_name = new char[strlen(name) + 1];
         strcpy(m_name, name);
         m_dob = dob;
         m_power = power;
         m_level = level;
         m_super = super;
      }
   }
   bool Saiyan::hasLost(Saiyan& other) {
      bool result = false;
      if (!isValid() || !other.isValid())
         result = false;
      else
         powerup();
         other.powerup();
         if (m_power <= other.m_power)
            result = true;
      else 
         result = false; 
      return result;
   }
   Saiyan::Saiyan() {
      setEmpty();
   }
   Saiyan::Saiyan(const char* name, int dob, int power) {
      freememory();
      set(name, dob, power);
   }
   Saiyan::~Saiyan() {
      freememory();
   }
   void Saiyan::freememory() {
      delete [] m_name;
      m_name = nullptr;
   }
   void Saiyan::powerup() {
      if (m_super) {
         m_power = m_power * (m_level +1); 
      }
   }
}