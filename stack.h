/***********************************************************************
 * Module:
 *    Stack
 * Summary:
 *    Our custom implementation of std::stack
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *       stack             : similar to std::stack
 * Author
 *    Nathan Lipovich - 1h15m
 ************************************************************************/

#pragma once

#include <cassert>  // because I am paranoid
#include "vector.h"

namespace custom
{

/**************************************************
 * STACK
 * First-in-Last-out data structure
 *************************************************/
template<class T, class Container = custom::vector<T>>
class stack
{
public:
  
   //
   // Construct
   //
   
   stack() : container()                                                            {  }
   stack(const stack<T, Container>& rhs) : container(rhs.container)                 {  }
   stack(      stack<T, Container>&& rhs) : container(std::move(rhs.container))     {  }
   stack(const Container&  rhs) : container(rhs)                                    {  }
   stack(      Container&& rhs) : container(std::move(rhs))                         {  }
   ~stack()                      {                      }     
   
   //
   // Assign
   //
   stack <T> & operator = (const stack <T> & rhs)
   {
      return *this;
   }
   stack <T>& operator = (stack <T> && rhs)
   {
      return *this;
   }
   void swap(stack <T>& rhs)
   {

   }

   //
   // Access
   //
   
   T & top()       
   { 
      return container.back(); 
   }
   const T & top() const 
   { 
      return container.back(); 
   }

   //
   // Insert
   //
   
   void push(const T &  t) 
   {  
      container.push_back(t);
   }
   void push(      T && t) 
   {  
      container.push_back(std::move(t));
   }

   //
   // Remove
   //
   
   void pop() 
   {  
      container.pop_back();
   }

   //
   // Status
   //
   
   size_t size () const { return container.size(); }
   bool   empty() const { return container.empty(); }
   

#ifdef DEBUG // make this visible to the unit tests
public:
#else
private:
#endif
   
   Container container;  // underlying container (probably a vector)
};



} // custom namespace


