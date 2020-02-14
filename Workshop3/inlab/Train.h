// Train.h
/***********************************************************************
// OOP244 Workshop 3: Classes & Privacy
// File Train.h
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
#ifndef SDDS_TRAIN_H__ 
#define SDDS_TRAIN_H__

namespace sdds {
   const int MAX_NAME = 30;
   const int MAX_DESC = 20;
   const double MAX_WEIGHT = 700.555;
   const double MIN_WEIGHT = 40.444;

   class Cargo {
      char c_description[MAX_DESC + 1];
      double c_weight;
   public:
      const char* getDesc() const;
      double getWeight() const;
      void setDesc(const char* description);
      void setWeight(double weight);
      void init(const char* description, double weight);
   };
   class Train {
      char t_name[MAX_NAME + 1];
      int t_id;
      Cargo* t_cargo;
   public:
      void setTrain(const char* name, int id);
      bool isEmpty() const;
      void display() const;
      void loadCargo(Cargo& cargo);
      void unloadCargo();
   };

}
#endif