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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
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
      if (gift.wrap == nullptr) {
         cout << "Unwrapped" << endl;
      }
      else {
         cout << "Wrap Layers: " << gift.wrap_layers << endl;
         for (int i = 0; i < gift.wrap_layers; i++) {
            cout << "Wrap #" << i + 1 << ": " << gift.wrap[i].w_pattern << endl;
         }
      }
   }
   bool wrap(Gift& w_gift) {
      bool value = false;
      if (w_gift.wrap_layers != 0) {
         cout << "Gift is already wrapped!" << endl;
         value = false;
      }
      else {
         cout << "Wrapping gifts..." << endl;
         do {
            cout << "Enter the number of wrapping layers for the Gift: ";
            cin >> w_gift.wrap_layers;
            if (cin.fail()) {
               cout << "Enter must be a integer!" << endl;
               cin.clear();
               cin.ignore(1000, '\n');
            }
            if (w_gift.wrap_layers < 1) {
               cout << "Layers at minimum must be 1, try again." << endl;
            }
         } while (w_gift.wrap_layers < 1);
         
         w_gift.wrap = new Wrapping[w_gift.wrap_layers];
         char* pattern = nullptr;
         pattern = new char[MAX_LENGTH + 1];
         for (int i = 0; i < w_gift.wrap_layers; i++) {
            cout << "Enter wrapping pattern #" << i + 1 << ": ";
            cin >> pattern;
            w_gift.wrap[i].w_pattern = new char[strlen(pattern) + 1];
            strcpy(w_gift.wrap[i].w_pattern, pattern);
         }
            delete[] pattern;
            pattern = nullptr;
            value = true;
      } return value;
   }
   bool unwrap(Gift& w_gift) {
      bool value = false;
      if (w_gift.wrap_layers == 0) {
         cout << "Gift isn't wrapped! Can't unwrap." << endl;
      }
      else {
         cout << "Gift being unwrapped." << endl;
         for (int i = 0; i < w_gift.wrap_layers; i++) {
            delete[] w_gift.wrap[i].w_pattern;
            w_gift.wrap[i].w_pattern = nullptr;
         }
         delete[] w_gift.wrap;
         w_gift.wrap = nullptr;
         w_gift.wrap_layers = 0;
         value = true;
      }
      return value;
   }
   void gifting(Gift& gift) {
      cout << "Preparing a gift..." << endl;
      gifting(gift.g_description);
      gifting(gift.g_price);
      gifting(gift.g_units);
      wrap(gift);
   }
}