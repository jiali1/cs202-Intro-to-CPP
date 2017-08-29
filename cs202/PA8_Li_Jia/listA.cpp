// Program Information ////////////////////////////////////////////////////////
/**
 * @file listA.cpp
 * 
 * @details The listA Class.
 *
 * @version 1.00 
 *          Jia Li (3 Dec. 2016)
 *          Updated with all member functions.
 *
 *
 * @Note N/A
 */

#ifndef LIST_CPP
#define LIST_CPP 
#include <iostream>
#include "listA.h"

using namespace std; 

/**
 * @function List default constructor. 
 *
 * @details initialize all members with value.
 *          
 */
List::List(int iMax)
{
   size = iMax; 
   actual = 0; 
   cursor = -1; 
   data = new int[size]; 
}

/**
 * @function List destructor. 
 *
 * @details clear all values from members.
 *          
 */
List::~List()
{
   clear();
}

/**
 * @function isEmpty function.
 *
 * @details checks if the list is empty.
 *          
 */
bool List::isEmpty() const
{
   if(actual == 0)
   {
      return true; 
   }
   return false; 
}

/**
 * @function isFull function.
 *
 * @details checks if the list is full. 
 *          
 */
bool List::isFull() const
{
   if(actual == size)
   {
      return true; 
   }
   return false; 
}

/**
 * @function goToBeginning function.
 *
 * @details go to the beginning of the list. 
 *          
 */
bool List::goToBeginning()
{
   if(isEmpty() || cursor == 0)
   {
      return false; 
   }
   cursor = 0; 
   return true; 
}

/**
 * @function goToEnd function.
 *
 * @details go to the end of the list. 
 *          
 */
bool List::goToEnd()
{
   if(isEmpty() || cursor == actual - 1 )
   {
      return false; 
   }
   cursor = actual - 1; 
   return true; 
}

/**
 * @function goToNext function.
 *
 * @details go to the next member in the list. 
 *          
 */
bool List::goToNext()
{
   if(isEmpty() || cursor == actual - 1 )
   {
      return false; 
   }
   cursor = cursor + 1; 
   return true; 
}

/**
 * @function goToPrior function.
 *
 * @details go to the prior member. 
 *          
 */
bool List::goToPrior()
{
   if(isEmpty() || cursor == 0 )
   {
      return false; 
   }
   cursor = cursor - 1; 
   return true; 
}

/**
 * @function insertBefore function.
 *
 * @details insert a member before the cursor. 
 *          
 */
bool List::insertBefore(int iData)
{
   if(isFull())
   {
      return false;
   }
   else if(isEmpty())
   {
      data[actual] = iData; 
      actual++; 
      cursor++; 
   }
   else 
   {
      for(int i = actual; i > cursor; i--)
      {
         data[i] = data[i-1];
      }
      data[cursor] = iData;
      actual++;  
   }
   return true; 
}

/**
 * @function insertAfter function. 
 *
 * @details insert a member after the cursor. 
 *          
 */
bool List::insertAfter(int iData)
{
   if(isFull())
   {
      return false;
   }
   else if(isEmpty())
   {
      data[actual] = iData; 
      actual++; 
      cursor++; 
   }
   else if(cursor == actual - 1)
   {
      cursor++;
      data[cursor] = iData; 
      actual++; 
   }
   else 
   {
      for(int i = actual - 1; i > cursor; i--)
      {
         data[i] = data[i-1];
      }
      cursor++; 
      data[cursor] = iData;
      actual++;
   }
   return true;
}

/**
 * @function remove function.
 *
 * @details remove a member at the cursor from the list. 
 *          
 */
bool List::remove()
{
   if(isEmpty())
   {
      return false; 
   }
   else if(cursor == actual - 1)
   {
      cursor = 0; 
      actual--; 
   }
   else 
   {
      for(int i = cursor; i < actual - 1; i++)
      {
         data[i] = data[i + 1]; 
      }
      actual--; 
   }
   return true; 
}

/**
 * @function clear function.
 *
 * @details clear all data from the list. 
 *          
 */
void List::clear()
{
   if(!isEmpty())
   {
      size = 0;
      delete[] data;
      data = NULL; 
      cursor = -1; 
      actual = 0;
   } 
}

/**
 * @function overload assignment operator. 
 *
 * @details copies from the src to the calling list object. 
 *          
 */
List& List::operator=(const List& src)
{
   if( (this != &src) || (!src.isEmpty()) )
   {
      clear(); 
      size = src.size; 
      actual = src.actual; 
      cursor = src.cursor; 
      data = new int[size]; 

      for(int i = 0; i < actual; i++)
      {
         data[i] = src.data[i]; 
      }
   }
   return *this;
}

/**
 * @function copy constructor. 
 *
 * @details initialize the calling object with data from the src object. 
 *          
 */
List::List(const List& src)
{
   size = src.size; 
   actual = src.actual; 
   cursor = src.cursor; 
   data = new int[size]; 

   if( !src.isEmpty() )
   { 
      for(int i = 0; i < actual; i++)
      {
         data[i] = src.data[i]; 
      }
   }
}

/**
 * @function overload extraction operator.
 *
 * @details extracts the data from all members in the list.
 *          
 */
ostream& operator<<(ostream& output, const List& src)
{
   for(int i = 0; i < src.actual; i++)
   {
      if( i == src.cursor )
      {
         output << "[" << src.data[i] << "] ";
      }
      else 
      {
         output << src.data[i] << " "; 
      }
   }
   return output;
}

#endif
