// Program Information ////////////////////////////////////////////////////////
/**
 * @file stackA.cpp
 * 
 * @details The stackA Class.
 *
 * @version 1.00 
 *          Jia Li (12 Dec. 2016)
 *          Updated with all member functions.
 *
 *
 * @Note N/A
 */


#include <iostream>
#include "stackA.h"

using namespace std; 

/**
 * @function the default constructor.
 *
 * @details initialize all members with values.
 *          
 */
stackA::stackA(int nMax)
{
   max = nMax;
   top = -1; 
   data = new int[max];
}

/**
 * @function destructor.
 *
 * @details deallocate memory and clear values from members.
 *          
 */
stackA::~stackA()
{
   clear(); 
}

/**
 * @function empty function.
 *
 * @details check if the stack is empty.
 *          
 */
bool stackA::empty() const
{
   if( top == -1 )
   {
      return true; 
   }
   return false; 
}

/**
 * @function full function
 *
 * @details check if the stack is full.
 *          
 */
bool stackA::full() const
{
   if( top == max - 1 )
   {
      return true; 
   }
   return false; 
}

/**
 * @function getTop function
 *
 * @details extract the value from the top
 *          
 */
int stackA::getTop()
{
   if( empty() )
   {
      return -1; 
   }
   return data[top]; 
}

/**
 * @function push function
 *
 * @details push an data onto the top of the stack
 *          
 */
bool stackA::push(int nData)
{
   if( full() )
   {
      return false; 
   }
   else 
   {
      data[++top] = nData; 
      return true; 
   }
}

/**
 * @function pop function
 *
 * @details pop a value from the top of the stack
 *          
 */
bool stackA::pop()
{
   if( empty() )
   {
      return false; 
   }
   top--;
   if( top == -1 )
   {
      delete[] data;
      data = NULL;
      max = 0;
   }
   return true; 
}

/**
 * @function clear function
 *
 * @details clear all data from the stack and clears all members
 *          
 */
bool stackA::clear()
{
   if( empty() )
   {
      return false; 
   }

   delete[] data; 
   data = NULL; 
   max = 0; 
   top = -1; 
   
   return true;
}

/**
 * @function overload equality operator
 *
 * @details check if two stacks are equal
 *          
 */
bool stackA::operator==(const stackA& src) const
{
   if( top != src.top )
      return false;
   if( empty() && src.empty() )
      return true; 
 
   for( int index = 0; index <= top; index++ )
   {
      if( data[index] != src.data[index] )
         return false; 
   }
   return true; 
}

/**
 * @function overload assignment operator
 *
 * @details assign data from one stack onto another stack
 *          
 */
stackA& stackA::operator=(const stackA& src)
{
   if( this != &src )
   {
      clear(); 
      if( src.empty() )
         return *this; 
    
      max = src.max; 
      top = src.top; 
      data = new int[max]; 
      
      for( int index = 0; index <= top; index++ )
         data[index] = src.data[index]; 
   }
   return *this; 
}

/**
 * @function copy constructor
 *
 * @details copies data from one stack to another stack
 *          
 */
stackA::stackA(const stackA& src)
{
   max = src.max; 
   top = src.top; 
   data = new int[max]; 
      
   for( int index = 0; index <= top; index++ )
      data[index] = src.data[index]; 
}

/**
 * @function overload extraction operator
 *
 * @details extracts data from the stack to the output stream
 *          
 */
ostream& operator<<(ostream& output, const stackA& src)
{
   for( int index = 0; index <= src.top; index++ )
   {
      output << src.data[index] << " "; 
   }
  
   return output; 
}

