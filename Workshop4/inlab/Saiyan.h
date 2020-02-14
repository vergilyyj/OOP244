#pragma once
// OOP244 Workshop 4: Constructors 
// File: Saiyan.h
// Version: 1.0
// Date: 2/6/2020
// Author: Ya Jian Yu
// Description:
// This file provide class and member function declearation for Saiyan.cpp
/////////////////////////////////////////////
#ifndef SDDS_SAIYAN_H__
#define SDDS_SAIYAN_H__
 
namespace sdds {
   const int MAX_NAME = 30;
   class Saiyan {
      char m_name[MAX_NAME + 1];
      int m_dob;
      int m_power;
      bool m_super;
   public:
      Saiyan();
      Saiyan(const char* c_name, int c_dob, int c_power);
      ~Saiyan();
      bool isSuper() const;
      bool isValid() const;
      void setEmpty();
      void display() const;
      void set(const char* name, int dob, int power, bool super = false);
      bool hasLost(const Saiyan& other) const;
   };
}
#endif 
