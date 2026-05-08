/***********************************************************************
 * Component:
 *    SPY
 * Author:
 *    James Helfrich, PhD. (c) 2022 by Kendall Hunt
 * Summary:
 *    A mock class designed to measure its usage: a spy!
 ************************************************************************/

#pragma once

#include <cassert>


/*************************************************************
 * SPY CONTAINER
 * A mock container class that records how it was used
 *************************************************************/
template <class T>
class SpyContainer
{
private:
   enum {
      DEFAULT_CONSTRUCTOR, // 0
      COPY_CONSTRUCTOR,    // 1
      MOVE_CONSTRUCTOR,    // 2
      COPY_ASSIGN,         // 3
      MOVE_ASSIGN,         // 4
      COPY_PUSH_BACK,      // 5
      MOVE_PUSH_BACK,      // 6
      POP_BACK,            // 7
      READ_BACK,           // 8
      WRITE_BACK,          // 9
      SIZE,                // 10
      EMPTY,               // 11
      DESTRUCTOR,          // 12
      SWAP,                // 13
      NUM_MARKERS          // 14
   };
   T * p;

public:
   // default constructor
   SpyContainer() 
   { 
      p = new T[10];
      counters[DEFAULT_CONSTRUCTOR]++; 
   }


   // copy constructor
   SpyContainer(const SpyContainer& rhs) 
   {
      p = new T[10];
      counters[COPY_CONSTRUCTOR]++;
   }

   // move constructor
   SpyContainer(SpyContainer && rhs) 
   {
      p = new T[10];
      counters[MOVE_CONSTRUCTOR]++;
   }

   // destructor
   ~SpyContainer()
   {
      delete [] p;
      counters[DESTRUCTOR]++;
   }

   // copy assignment operator
   SpyContainer& operator=(const SpyContainer& rhs) noexcept
   {
      counters[COPY_ASSIGN]++;
      return *this;
   }

   // move assignment operator
   SpyContainer& operator=(SpyContainer&& rhs) noexcept
   {
      counters[MOVE_ASSIGN]++;
      return *this;
   }

   // swap member 
   void swap(SpyContainer& rhs) 
   {
      counters[SWAP]++;
   }

   // empty 
   bool empty() const
   {
      counters[EMPTY]++;
      return false;
   }

   // empty 
   size_t size() const
   {
      counters[SIZE]++;
      return 1;
   }

   // copy push back
   void push_back(const T& t)
   {
      counters[COPY_PUSH_BACK]++;
   }

   // move push back
   void push_back(T&& t)
   {
      counters[MOVE_PUSH_BACK]++;
   }

   // pop back
   void pop_back()
   {
      counters[POP_BACK]++;
   }

   // read back
   const T& back() const
   {
      counters[READ_BACK]++;
      return *(new T());
   }

   // write back
   T& back() 
   {
      counters[WRITE_BACK]++;
      return *(new T());
   }

   // reset the counters for a new test
   static void reset()
   {
      for (int i = 0; i < NUM_MARKERS; i++)
         counters[i] = 0;
   }

   static int numDefaultConstruct() { return counters[DEFAULT_CONSTRUCTOR]; }
   static int numCopyConstruct() { return counters[COPY_CONSTRUCTOR]; }
   static int numMoveConstruct() { return counters[MOVE_CONSTRUCTOR]; }
   static int numCopyAssign() { return counters[COPY_ASSIGN]; }
   static int numMoveAssign() { return counters[MOVE_ASSIGN]; }
   static int numCopyPushBack() { return counters[COPY_PUSH_BACK]; }
   static int numMovePushBack() { return counters[MOVE_PUSH_BACK]; }
   static int numPopBack() { return counters[POP_BACK]; }
   static int numReadBack() { return counters[READ_BACK]; }
   static int numWriteBack() { return counters[WRITE_BACK]; }
   static int numSize() { return counters[SIZE]; }
   static int numEmpty() { return counters[EMPTY]; }
   static int numDestructor() { return counters[DESTRUCTOR]; }
   static int numSwap() { return counters[SWAP]; }

   // keep track of how it is used
   static int counters[NUM_MARKERS];
};
