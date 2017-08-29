// Program Information ////////////////////////////////////////////////////////
/**
 * @file listN.cpp
 * 
 * @details The listN Class.
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
#include "listN.h"

/**
 * @function Node default constructor. 
 *
 * @details initialize all members with value.
 *          
 */
Node::Node(int iData, Node* nPtr)
{
   data = iData;
   next = nPtr; 
}

/**
 * @function List default constructor. 
 *
 * @details initialize all members with value.
 *          
 */
List::List(int iMax)
{
   head = cursor = NULL; 
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
   if( head == NULL )
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
   if(isEmpty() || (head == cursor))
   {
      return false; 
   }
   cursor = head;
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
   if(isEmpty() || (cursor->next == NULL))
   {
      return false;
   }
   while(cursor->next != NULL)
   {
      cursor = cursor->next; 
   }
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
   if(isEmpty() || (cursor->next == NULL))
   {
      return false; 
   }
   cursor = cursor->next; 
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
   Node* tempPtr = NULL; 
   if(isEmpty() || (head == cursor))
   {
      return false; 
   }
   tempPtr = head; 
   while(tempPtr->next != cursor)
   {
      tempPtr = tempPtr->next; 
   }
   cursor = tempPtr; 
   tempPtr = NULL; 
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
   Node* tempPtr = NULL;
   Node* tempPtrTwo = NULL; 
   if(isEmpty())
   {
      head = cursor = new Node(iData,NULL); 
   }
   else if(head == cursor)
   {
      cursor = new Node(iData,head);
      head = cursor; 
   }
   else 
   {
      tempPtr = head; 
      while(tempPtr->next != cursor)
      {
         tempPtr = tempPtr->next; 
      }
      tempPtrTwo = new Node(iData,cursor); 
      tempPtr->next = tempPtrTwo; 
      cursor = tempPtrTwo; 
      tempPtr = tempPtrTwo = NULL; 
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
   Node* tempPtr = NULL;
   Node* tempPtrTwo = NULL;  

   if(isEmpty())
   {
      head = cursor = new Node(iData,NULL);
   }
   else if(cursor->next == NULL)
   {
      cursor->next = new Node(iData,NULL);
      cursor = cursor->next; 
   }
   else 
   {
      tempPtr = cursor->next; 
      tempPtrTwo = new Node(iData,tempPtr); 
      cursor->next = tempPtrTwo; 
      cursor = cursor->next;
      tempPtr = tempPtrTwo = NULL; 
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
   Node* tempPtr = NULL;
   Node* tempPtrTwo = NULL; 

   if(isEmpty())
   {
      return false; 
   }
   else if(head->next == NULL)
   {
      delete head; 
      head = cursor = NULL; 
   }
   else if(cursor->next == NULL)
   {
      tempPtr = head; 
      while(tempPtr->next != cursor)
      {
         tempPtr = tempPtr->next; 
      }
      tempPtr->next = NULL; 
      delete cursor; 
      cursor = head; 
   }
   else 
   {
      tempPtr = head; 
      while(tempPtr->next != cursor)
      {
         tempPtr = tempPtr->next; 
      }
      tempPtrTwo = cursor->next; 
      tempPtr->next = tempPtrTwo; 
      delete cursor; 
      cursor = tempPtrTwo; 
   }
   tempPtr = tempPtrTwo = NULL; 
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
   Node* tempPtr = NULL; 

   if(!isEmpty())
   {
      tempPtr = head->next;
      while(tempPtr != NULL)
      {
         delete head; 
         head = tempPtr; 
         tempPtr = tempPtr->next; 
      }
      delete head;
      head = tempPtr = cursor = NULL; 
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
   Node* tempPtr = NULL; 

   if((this != &src)||(!src.isEmpty()))
   {
      if(!isEmpty())
      {
         clear(); 
      }

      tempPtr = src.head;

      while(tempPtr != NULL)
      {
         insertAfter(tempPtr->data);
         tempPtr = tempPtr->next;
      }

      tempPtr = src.head;
      cursor = head;
      while(tempPtr != src.cursor)
      {
         tempPtr = tempPtr->next;
         cursor = cursor->next; 
      }
      
      tempPtr = NULL;
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
   Node* tempPtr = NULL; 

   head = cursor = NULL; 
   
   if(!src.isEmpty())
   {

      tempPtr = src.head;

      while(tempPtr != NULL)
      {
         insertAfter(tempPtr->data);
         tempPtr = tempPtr->next;
      }

      tempPtr = src.head;
      cursor = head;
      while(tempPtr != src.cursor)
      {
         tempPtr = tempPtr->next;
         cursor = cursor->next; 
      }
   }
   tempPtr = NULL;
}

/**
 * @function overload extraction operator.
 *
 * @details extracts the data from all members in the list.
 *          
 */
ostream& operator<<(ostream& output, const List& src)
{
   Node* tempPtr = src.head; 
   
   while(tempPtr != NULL)
   {
      if(tempPtr == src.cursor)
         output << "[" << tempPtr->data << "] "; 
      else 
         output << tempPtr->data << " "; 
      tempPtr = tempPtr->next; 
   }
   output << endl; 
   return output;
}

#endif
