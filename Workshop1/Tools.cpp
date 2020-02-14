/***********************************************************************
// 244-200 Workshop 1: Compiling modular source code
// File	Tools.cpp
// Version 1.0
// Date	2020/01/17
// Author	Ya Jian Yu
// Description
// This provide defination for the tools prototype
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Ya Jian Yu
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <cctype>
#include "Tools.h"


namespace sdds {
   void toLowerCaseAndAlphabeticCopy(char des[], const char source[]) {
      int i = 0, j = 0;
      char lower;
      for (; source[i] != 0; i++) {
         lower = tolower(source[i]);
         if (lower >= 'a' && lower <= 'z') {
            des[j++] = tolower(source[i]);
         }
      }
      des[j] = 0;
   }

}