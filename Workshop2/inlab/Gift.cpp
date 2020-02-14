// Gift.cpp
/***********************************************************************
// 244-200 Workshop 2: Dynamic Memory & Function Overloading 
// File	Gift.cpp
// Version 1.0
// Date	2020/01/24
// Author	Ya Jian Yu
// Description
// This provide the Gift defination
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Ya Jian Yu
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Gift.h"
using namespace std;

namespace sdds {
   void gifting(char* description) {
      cout << "Enter gift description: ";
      cin.width(MAX_DESC + 1);
      cin >> description;
   }
   void gifting(double& price) {
         do {
            cout << "Enter gift price: ";
            cin >> price;
         if (price < 0 || price > MAX_PRICE) {
            cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
         }
         } while (price < 0 || price > MAX_PRICE); 
   }
   void gifting(int& units) {
      do {
         cout << "Enter gift units: ";
         cin >> units;
         if (cin.fail()) {
            cout << "Bad int, try again: ";
            cin.clear();
         }
         if (units < 1) {
            cout << "Gift units must be at least 1" << endl;
         }
      } while (units < 1);
   }
   void display(const Gift& gift) {
      cout << "Gift Details:" << endl;
      cout << "Description: " << gift.g_description << endl;
      cout << "Price: " << gift.g_price << endl;
      cout << "Units: " << gift.g_units << endl;
   }
}