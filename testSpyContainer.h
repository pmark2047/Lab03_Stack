/***********************************************************************
 * Header:
 *    TEST SPY CONTAINER
 * Summary:
 *    Unit tests for the spy
 * Author:
 *    James Helfrich, PhD. (c) 2022 by Kendall Hunth
 ************************************************************************/

#pragma once
#ifdef DEBUG

#include "spyContainer.h"        // class under test
#include "unitTest.h"   // unit test baseclass

 /***********************************************
  * TEST SPY
  * Unit tests for the Spy class
  ***********************************************/
class TestSpyContainer : public UnitTest
{

public:
   void run()
   {
      reset();

      // Constructor
      test_constructorDefault();
      test_constructorCopy();
      test_constructorMove();
      test_destructor();

      // Assignment Operator
      test_assignCopy();
      test_assignMove();
      test_swap();

      // Status
      test_size();
      test_empty();

      // Modification
      test_pushBackCopy();
      test_pushBackMove();
      test_popBack();
      test_backCopy();
      test_backMove();

      report("SpyCon");
   }


   /***************************************
    * CONSTRUCTOR
    ***************************************/

    // default constructor: create a default spy without allocation
   void test_constructorDefault()
   {  // setup
      SpyContainer<int>::reset();
      // exercise
      SpyContainer<int> sc;
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 1);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
      assertUnit(SpyContainer<int>::numSwap() == 0);
   }  // teardown

   // copy constructor
   void test_constructorCopy()
   {  // setup
      SpyContainer<int> sSrc;
      SpyContainer<int>::reset();
      // exercise
      SpyContainer<int> sDes(sSrc);
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 1);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
      assertUnit(SpyContainer<int>::numSwap() == 0);
   }  // teardown

      // move constructor
   void test_constructorMove()
   {  // setup
      SpyContainer<int> sSrc;
      SpyContainer<int>::reset();
      // exercise
      SpyContainer<int> sDes(std::move(sSrc));
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 1);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
      assertUnit(SpyContainer<int>::numSwap() == 0);
   }  // teardown

   // delete a default and empty spy
   void test_destructor()
   {  // setup
      {
         SpyContainer<int> sc;
         SpyContainer<int>::reset();
      }  // exercise
      // verify
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numDestructor() == 1);
      assertUnit(SpyContainer<int>::numSwap() == 0);
   }  // teardown



   /***************************************
    * ASSIGN
    ***************************************/

   // assign-copy
   void test_assignCopy()
   {  // setup
      SpyContainer<int> sSrc;
      SpyContainer<int> sDes;
      SpyContainer<int>::reset();
      // exercise
      sDes = sSrc;
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 1);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
   }  // teardown

      // assign-move
   void test_assignMove()
   {  // setup
      SpyContainer<int> sSrc;
      SpyContainer<int> sDes;
      SpyContainer<int>::reset();
      // exercise
      sDes = std::move(sSrc);
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 1);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
   }  // teardown

         // swap
   void test_swap()
   {  // setup
      SpyContainer<int> sSrc;
      SpyContainer<int> sDes;
      SpyContainer<int>::reset();
      // exercise
      sDes.swap(sSrc);
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numSwap() == 1);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
   }  // teardown

   /***************************************
    * STATUS
    ***************************************/

    // size
   void test_size()
   {  // setup
      SpyContainer<int> s;
      SpyContainer<int>::reset();
      // exercise
      s.size();
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 1);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
   }  // teardown

       // empty
   void test_empty()
   {  // setup
      SpyContainer<int> s;
      SpyContainer<int>::reset();
      // exercise
      s.empty();
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 1);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
   }  // teardown



   /***************************************
    * MODIFICATION
    ***************************************/

    //  push back copy
   void test_pushBackCopy()
   {  // setup
      SpyContainer<int> s;
      const int x = 7;
      SpyContainer<int>::reset();
      // exercise
      s.push_back(x);
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 1);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
   }  // teardown

   //  push back move
   void test_pushBackMove()
   {  // setup
      SpyContainer<int> s;
      int x = 9;
      SpyContainer<int>::reset();
      // exercise
      s.push_back(std::move(x));
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 1);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
   }  // teardown

       // pop back
   void test_popBack()
   {  // setup
      SpyContainer<int> s;
      SpyContainer<int>::reset();
      // exercise
      s.pop_back();
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 1);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
   }  // teardown

  // pop back read
   void test_backCopy()
   {  // setup
      const SpyContainer<int> s;
      SpyContainer<int>::reset();
      // exercise
      s.back();
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 1);
      assertUnit(SpyContainer<int>::numWriteBack() == 0);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
   }  // teardown

     // pop back write
   void test_backMove()
   {  // setup
      SpyContainer<int> s;
      SpyContainer<int>::reset();
      // exercise
      s.back() = 7;
      // verify
      assertUnit(SpyContainer<int>::numDefaultConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyConstruct() == 0);
      assertUnit(SpyContainer<int>::numMoveConstruct() == 0);
      assertUnit(SpyContainer<int>::numCopyAssign() == 0);
      assertUnit(SpyContainer<int>::numMoveAssign() == 0);
      assertUnit(SpyContainer<int>::numCopyPushBack() == 0);
      assertUnit(SpyContainer<int>::numMovePushBack() == 0);
      assertUnit(SpyContainer<int>::numPopBack() == 0);
      assertUnit(SpyContainer<int>::numReadBack() == 0);
      assertUnit(SpyContainer<int>::numWriteBack() == 1);
      assertUnit(SpyContainer<int>::numSize() == 0);
      assertUnit(SpyContainer<int>::numEmpty() == 0);
      assertUnit(SpyContainer<int>::numDestructor() == 0);
   }  // teardown

};

#endif // DEBUG


