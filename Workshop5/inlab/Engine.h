// OOP244 Workshop 5: Operator Overloading
// File: Engine.h
// Version: 1.0
// Date: 2/14/2020
// Author: Ya Jian Yu
// Description:
// This file provide declearation for Engine
/////////////////////////////////////////////
#pragma once
#ifndef SDDS_ENGINE_H__
#define SDDS_ENGINE_H__

namespace sdds {
   const int MAX_TYPE = 30;
   class Engine {
      double m_size;
      char m_type[MAX_TYPE + 1];
   public:
      Engine();
      Engine(const char* type, double size);
      ~Engine();
      void setEmpty();
      double get() const;
      void set(Engine e);
      void display() const;
   };
}
#endif 