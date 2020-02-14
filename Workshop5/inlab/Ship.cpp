// OOP244 Workshop 5: Operator Overloading
// File: Ship.cpp
// Version: 1.0
// Date: 2/14/2020
// Author: Ya Jian Yu
// Description:
// This file provide defination for Ship
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Ship.h"


using namespace std;
namespace sdds {
   void Ship::setEmpty() {
      m_shipType[0] = '\0';
      m_nOfEngine = 0;
      m_distance = 0.0;
   }
   Ship::Ship() {
      setEmpty();
   }
   Ship::Ship(const char* shipType, Engine* engine, int nOfEngine) {

      set(shipType, engine, nOfEngine);
   }
   Ship::~Ship() {

   }
   void Ship::set(const char* shipType, Engine* engine, int nOfEngine) {
      if (shipType != nullptr && shipType[0] != '\0' && strlen(shipType) <= 6 && strlen(shipType) > 0 && nOfEngine >= 1 && nOfEngine <= 10) {
         strcpy(m_shipType, shipType);
         m_nOfEngine = nOfEngine;
            for (int i = 0; i < nOfEngine; i++) {
               m_engine[i].set(engine[i]);
            }
      }
      else
         setEmpty();
   }
   bool Ship::empty() const {
      return (m_shipType[0] == '\0' && m_nOfEngine == 0 && m_distance == 0.0);
   }
   float Ship::calculatePower() const {
      float power = 0.0;
      for (int i = 0; i < m_nOfEngine; i++)
         power += m_engine[i].get() * 5;
      return power;
   }
   void Ship::display() const {
      if (empty())
         cout << "No available data" << endl;
      else {
         cout.setf(ios::fixed);
         cout.width(6);
         cout.precision(2);
         cout << m_shipType << "- " << calculatePower() << endl;
         for (int i = 0; i < m_nOfEngine; i++) {
            m_engine->display();
         }
      }
   }
   bool Ship::isValid() {
      return (m_shipType != nullptr && m_shipType[0] != '\0' && strlen(m_shipType) <= 6 && strlen(m_shipType) > 0 && m_nOfEngine >= 1 && m_nOfEngine < 10);
   }
   Ship& Ship::operator+=(Engine e) {
      if (!isValid())
         cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
      else {
         this->m_engine[m_nOfEngine] = e;
         m_nOfEngine++;
      }
      return *this;
   }
   bool operator==(const Ship& left, const Ship& right) {
      return (left.calculatePower() == right.calculatePower());
   }
   bool operator<(const Ship& ship, double power) {
      return(ship.calculatePower() < power);
   }
}