#pragma once
// OOP244 Workshop 5: Operator Overloading
// File: Ship.h
// Version: 1.0
// Date: 2/14/2020
// Author: Ya Jian Yu
// Description:
// This file provide declearation for Ship
/////////////////////////////////////////////
#ifndef SDDS_SHIP_H__
#define SDDS_SHIP_H__
#include "Engine.h"

namespace sdds {
   const int MAX_ENGINE = 10;
   const int MAX_SHIPTYPE = 6;
   class Ship {
      Engine m_engine[MAX_ENGINE];
      char m_shipType[MAX_SHIPTYPE + 1];
      int m_nOfEngine;
      float m_distance;
   public:
      Ship();
      Ship(const char* shipType, Engine* engine, int nOfEngine);
      ~Ship();
      void setEmpty();  
      void set(const char* shipType, Engine* engine, int nOfEngine);
      bool empty() const;
      float calculatePower() const;
      void display() const;
      bool isValid();
      Ship& operator+=(Engine e);
      friend bool operator==(const Ship& left, const Ship& right);
   };
   bool operator<(const Ship& ship, double power);
}
#endif 