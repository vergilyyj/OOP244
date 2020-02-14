//Train.cpp
/***********************************************************************
// OOP244 Workshop 3: Classes & Privacy
// File Train.cpp
// Version 1.0
// Date	2020/01/31
// Author Ya Jian Yu
// Description
// Tests Train module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Train.h"

using namespace std;

namespace sdds {
   void Train::setTrain(const char* name, int id) {
      if (name == nullptr || name[0] == 0 || id < 1) {
         strcpy(t_name, "");
         t_id = 0;
      }
      else {
         strcpy(t_name, name);
         t_id = id;
      }
      t_cargo = nullptr;
   }
   bool Train::isEmpty() const {
      bool empty = false;
      if (t_name == nullptr || t_name[0] == '\0' || t_id < 1) {
         empty = true;
      }
      return empty;
   }
   void Train::display() const {
      cout << "***Train Summary***" << endl;
      if (isEmpty()) {
         cout << "This is an empty train." << endl;
      }
      else {
         cout << "Name: " << t_name << " ID: " << t_id << endl;
         if (t_cargo == nullptr) {
            cout << "No cargo on this train." << endl;
         }
         else {
            cout << "Cargo: " << t_cargo->getDesc() << " Weight: " << t_cargo->getWeight() << endl;
         }
      }

   }
   void Train::loadCargo(Cargo& cargo) {
      t_cargo = new Cargo;
      t_cargo->setDesc(cargo.getDesc());
      t_cargo->setWeight(cargo.getWeight());
   }
   void Train::unloadCargo() {
      delete t_cargo;
      t_cargo = nullptr;
   }
   const char* Cargo::getDesc() const {
      return c_description;
   }
   double Cargo::getWeight() const {
      return c_weight;
   }
   void Cargo::setDesc(const char* description) {
      strcpy(c_description, description);
   }
   void Cargo::setWeight(double weight) {
      c_weight = weight;
   }
}