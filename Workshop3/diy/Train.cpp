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
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << fixed;
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
      strcpy(c_description,description);
   }
   void Cargo::setWeight(double weight) {
      c_weight = weight;
   }
   void Cargo::init(const char* description, double weight) {
      if (strlen(description) <= (MAX_DESC + 1))
         setDesc(description);
      else setDesc("");
      if (weight >= MIN_WEIGHT && weight <= MAX_WEIGHT)
         setWeight(weight);
      else
         setWeight(MIN_WEIGHT);    
   }
   bool Train::swapCargo(Train& train) {
      bool result = false;
      if (t_cargo == nullptr || train.t_cargo == nullptr)
         result = false;
      else {
         Cargo* swap = t_cargo;
         t_cargo = train.t_cargo;
         train.t_cargo = swap;
         result = true;
      }
      return result;
   }
   bool Train::increaseCargo(double increase) {
      bool result1;
      if (t_cargo == nullptr|| t_cargo->getWeight()== MAX_WEIGHT)
         result1 = false;
      else {
         if (t_cargo->getWeight() + increase > MAX_WEIGHT) {
            t_cargo->setWeight(MAX_WEIGHT);
            result1 = false;
         }
         else 
            t_cargo->setWeight(t_cargo->getWeight() + increase);
            result1 = true;
      }
      return result1;
   }
   bool Train::decreaseCargo(double decrease) {
      bool result2;
      if (t_cargo == nullptr||t_cargo->getWeight()==MIN_WEIGHT)
         result2 = false;
      else {
         if (t_cargo->getWeight() - decrease < MIN_WEIGHT) {
            t_cargo->setWeight(MIN_WEIGHT);
            result2 = false;
         }
         else {
            t_cargo->setWeight(t_cargo->getWeight() - decrease);
            result2 = true;
         }
      }
      return result2;
   }
}