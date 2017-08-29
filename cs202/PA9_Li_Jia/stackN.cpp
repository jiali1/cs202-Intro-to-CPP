// Program Information ////////////////////////////////////////////////////////
/**
 * @file stackN.cpp
 * 
 * @details The stackN Class.
 *
 * @version 1.00 
 *          Jia Li (12 Dec. 2016)
 *          Updated with all member functions.
 *
 *
 * @Note N/A
 */

#include <iostream>
#include "stackN.h"

using namespace std; 

/**
 * @function NodeS parameterized constructor
 *
 * @details initialized all members with passed in values
 *          
 */
NodeS::NodeS( int nData, NodeS* ptr )
{
   data = nData;
   next = ptr; 
}

/**
 * @function the default constructor.
 *
 * @details initialize all members with values.
 *          
 */
stackN::stackN( )
{
   top = NULL; 
}

/**
 * @function destructor.
 *
 * @details deallocate memory and clear values from members.
 *          
 */
stackN::~stackN( )
{
   clear(); 
}

/**
 * @function empty function.
 *
 * @details check if the stack is empty.
 *          
 */
bool stackN::empty() const
{
   if( top == NULL )
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
bool stackN::full() const
{
   return false; 
}

/**
 * @function getTop function
 *
 * @details extract the value from the top
 *          
 */
int stackN::getTop()
{
   if( empty() )
   {
      return -1;
   }
   return top->data; 
}

/**
 * @function push function
 *
 * @details push an data onto the top of the stack
 *          
 */
bool stackN::push( int nData )
{
   NodeS* tempPtr = NULL; 

   if( empty() )
   {
      top = new NodeS(nData, NULL);
   }
   else
   {
      tempPtr = new NodeS(nData, top);
      top = tempPtr; 
      tempPtr = NULL;
   }
   return true; 
}

/**
 * @function pop function
 *
 * @details pop a value from the top of the stack
 *          
 */
bool stackN::pop()
{
   NodeS* tempPtr = NULL; 

   if( empty() )
   {
      return false; 
   }
   else 
   {
      tempPtr = top; 
      top = top->next; 
      delete tempPtr; 

      tempPtr = NULL;
      
      return true; 
   }
}

/**
 * @function clear function
 *
 * @details clear all data from the stack and clears all members
 *          
 */
bool stackN::clear()
{
   if( empty() )
   {
      return false; 
   }
   else 
   {
      while( empty() == false )
      {
         pop();
      }
      top = NULL; 
   
      return true; 
   }
}

/**
 * @function overload equality operator
 *
 * @details check if two stacks are equal
 *          
 */
bool stackN::operator==(const stackN& src) const
{
   NodeS* tempPtr = top; 
   NodeS* tempSrcPtr = src.top;  

   if( ( empty() ) && ( src.empty() ) )
   {
      return true; 
   }
   else if( ( empty() ) && ( !src.empty() ) )
   {
      return false; 
   }
   else if( ( !empty() ) && ( src.empty() ) )
   {
      return false; 
   }

   while( ( tempPtr != NULL ) || ( tempSrcPtr != NULL ) )
   {
      if( tempPtr->data != tempSrcPtr->data ) 
         return false; 
      tempPtr = tempPtr->next;
      tempSrcPtr = tempSrcPtr->next; 
   }
   
   if( ( tempPtr != NULL ) || ( tempSrcPtr != NULL ) )
   {
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
stackN& stackN::operator=(const stackN& src)
{
   NodeS* tempPtr = NULL; 
   NodeS* tempPtrTwo = NULL; 
   int arrSize = 0; 
   int index = 0;

   if( this != &src )
   {
      clear();

      if( src.empty() )
      {
         return *this; 
      }
      
      tempPtr = src.top; 
   
      while( tempPtr != NULL )
      {
         tempPtr = tempPtr->next;
         arrSize++; 
      } 

      int arr[arrSize];
 
      tempPtr = src.top; 
   
      while( tempPtr != NULL )
      {
         arr[index] = tempPtr->data;
         tempPtr = tempPtr->next; 
         index++;
      }    
      
      index--;
      tempPtr = src.top; 
   
      top = new NodeS( arr[index], NULL ); 
      tempPtr = tempPtr->next; 
      index--;

      while( tempPtr != NULL )
      {
         tempPtrTwo = new NodeS(arr[index], top);
         top = tempPtrTwo; 
         tempPtrTwo = NULL;
         tempPtr = tempPtr->next; 
         index--;
      }
   }
   return *this; 
}

/**
 * @function copy constructor
 *
 * @details copies data from one stack to another stack
 *          
 */
stackN::stackN( const stackN& src )
{
   top = NULL; 
   *this = src; 
}

/**
 * @function overload extraction operator
 *
 * @details extracts data from the stack to the output stream
 *          
 */
ostream& operator<<(ostream& output, const stackN& src)
{
   NodeS* tempPtr = src.top; 
   
   while( tempPtr != NULL )
   {
      output << tempPtr->data << " "; 
      tempPtr = tempPtr->next; 
   }
   return output; 
}
