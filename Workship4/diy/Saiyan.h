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
      char* m_name{};
      int m_dob{};
      int m_power{};
      bool m_super{};
      //new
      int m_level{};
   public:
      Saiyan();
      Saiyan(const char* name, int dob, int power);
      ~Saiyan();
      bool isSuper() const;
      bool isValid() const;
      void setEmpty();
      void display() const;
      void set(const char* name, int dob, int power, int level = 0,bool super = false);
      bool hasLost(Saiyan& other) ;
      void freememory();
      void powerup();
   };
}
#endif 
