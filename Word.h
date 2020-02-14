/***********************************************************************
// 244-200 Workshop 1: Compiling modular source code
// File	Word.h
// Version 1.0
// Date	2020/01/17
// Author	Ya Jian Yu
// Description
// This provide the declearation for the Word module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Ya Jian Yu
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_WORD_H__ 
#define SDDS_WORD_H__


namespace sdds {
   const int MAX_WORD_LEN = 21;
   const int MAX_NO_OF_WORDS = 500;
   struct Word {
      char letters[MAX_WORD_LEN];
      int  count;
   };
   int searchWords(const Word words[], int num, const char word[]);
   void addWord(Word words[], int* index, const char newWord[]);
   void title();
   void endList();
   void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
   void print(const Word* w, bool gotoNextLine);
   void report(const Word words[], int noOfWords, int longestWord);
   void wordStats(bool logOn);
   void programTitle();
   void swap(Word* p1, Word* p2);
   void sort(Word words[], int cnt);
}


#endif
