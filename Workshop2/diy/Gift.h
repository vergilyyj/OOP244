// Gift.h
/***********************************************************************
// 244-200 Workshop 2: Dynamic Memory & Function Overloading
// File	Gift.h
// Version 1.0
// Date	2020/01/24
// Author	Ya Jian Yu
// Description
// This provide the prototypes
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Ya Jian Yu
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_GIFT_H__ 
#define SDDS_GIFT_H__

namespace sdds {
   const int MAX_DESC = 15;
   const double MAX_PRICE = 999.99;
   const int MAX_LENGTH = 20;
   struct Wrapping {
      char* w_pattern;
   };
   struct Gift {
      char g_description[MAX_DESC + 1];
      double g_price;
      int g_units;
      Wrapping* wrap;
      int wrap_layers;
   };
   void gifting(char* desc);
   void gifting(double& price);
   void gifting(int& units);
   void gifting(Gift& gift);
   void display(const Gift& gift);
   bool wrap(Gift& w_gift);
   bool unwrap(Gift& w_gift);

}
#endif