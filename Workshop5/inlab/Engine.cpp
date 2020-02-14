// OOP244 Workshop 5: Operator Overloading
// File: Engine.cpp
// Version: 1.0
// Date: 2/14/2020
// Author: Ya Jian Yu
// Description:
// This file provide defination for Engine
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Engine.h"

using namespace std;

namespace sdds {
   void Engine::setEmpty() {
      m_type[0] = '\0';
      m_size = 0.0;
   }
   Engine::Engine() {
      setEmpty();
   }
   Engine::Engine(const char* type, double size) {
      if (size > 0.0 && type[0] != '\0' && type != nullptr) {
         m_size = size;
         strcpy(m_type, type);
      }
      else
         setEmpty();
   }
   Engine::~Engine() {

   }
   double Engine::get()const {
      return m_size;
   }
   void Engine::display() const {
      cout.setf(ios::fixed);
      cout.precision(2);
      cout << m_size << " liters - " << m_type << endl;
   }
   void Engine::set(Engine e) {
      if (e.m_size > 0.0 && e.m_type[0] != '\0' && e.m_type != nullptr) {
         m_size = e.m_size;
         strcpy(m_type, e.m_type);
      }
      else
         setEmpty();
   }
}