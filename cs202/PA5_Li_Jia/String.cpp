// Program Information ////////////////////////////////////////////////////////
/**
 * @file String.cpp
 * 
 * @details The String Class.
 *
 * @version 1.20 
 *          Jia Li (22 Oct. 2016)
 *          Updated with all functions
 *
 *
 * @Note N/A
 */


#include <iostream> 
#include "String.h"

using namespace std; 

/**
 * @function initialize function.
 *
 * @details initialize the data members
 *          through the parameter.
 *          
 */
void String::initialize(char *src)
{
   wordLength = 0; 
   char* srcHome = src;
   char* bufferHome;

   while( *src != '\0' )
   {
      wordLength++;
      src++;
   }
   buffer = new char[wordLength+1];
   bufferHome = buffer;
   src = srcHome; 
    
   while( *src != '\0' )
   {
      *buffer = *src;
      buffer++;
      src++; 
   }
   *buffer = '\0'; 
   buffer = bufferHome; 

   src = NULL; 
   srcHome = NULL; 
   bufferHome = NULL; 
}

/**
 * @function deallocate function.
 *
 * @details deallocate all data members.
 *          
 */
void String::deallocate()
{
   delete[] buffer; 
   buffer = NULL; 
   wordLength = 0; 
}

/**
 * @function copy function.
 * 
 * @details copies from object to another. 
 *          
 */
void String::copy(const String& src)
{
   char* srcBufferTemp = src.buffer; 
   char* bufferTemp = buffer; 

   if( this != &src )
   {
      if( wordLength == src.wordLength )
      {
         while( *srcBufferTemp != '\0' )
         {
            *bufferTemp = *srcBufferTemp; 
            srcBufferTemp++; 
            bufferTemp++; 
         }
      }
      else 
      {
         deallocate();
         wordLength = src.wordLength; 
         buffer = new char[wordLength + 1]; 
         bufferTemp = buffer; 
         while( *srcBufferTemp != '\0')
         {
            *bufferTemp = *srcBufferTemp; 
            bufferTemp++;
            srcBufferTemp++;
         }
         *bufferTemp = '\0';
      }
   }
   srcBufferTemp = NULL; 
   bufferTemp = NULL;
}

/**
 * @function length function.
 *
 * @details returns the wordLength.
 *          
 */
int String::length() const
{
   return wordLength; 
}

/**
 * @function concat function.
 *
 * @details concats this string object 
 *          with the string from src object.
 *          
 */
void String::concat(const String& src)
{
   wordLength = wordLength + src.wordLength; 
   char* objTemp = buffer;
   char* srcObjTemp = src.buffer;
   char* temp = new char[wordLength + 1]; 
   char* tempHome = temp; 
   
   while( *objTemp != '\0' )
   {
      *temp = *objTemp; 
      objTemp++;
      temp++;
   }
   while( *srcObjTemp != '\0')
   {
      *temp = *srcObjTemp; 
      srcObjTemp++;
      temp++;
   }
   *temp = '\0';
   temp = tempHome; 
   
   delete[] buffer; 
   buffer = NULL;  
   buffer = temp; 
   
   objTemp = NULL; 
   srcObjTemp = NULL; 
   temp = NULL; 
   tempHome = NULL; 
   
}

/**
 * @function compare function.
 *
 * @details See if the two strings are 
 *          equal, greater than, or 
 *          less than.
 *          
 */
int String::compare(const String& src)
{  
   char* temp = buffer; 
   char* tempSrc = src.buffer; 

   while( (*temp != '\0') && 
         (*tempSrc != '\0') )
   {
      if( *temp < *tempSrc )
      {
         return -1; 
      }
      else if( *temp > *tempSrc )
      {
         return 1;
      }
      temp++;
      tempSrc++;  
   }
   if( *temp != '\0' )
   {
      return 1; 
   }
   if( *tempSrc != '\0' )
   {
      return -1; 
   }
   return 0; 
}

/**
 * @function print function.
 *
 * @details prints the string. 
 *          
 */
void String::print()
{
   cout << buffer << endl; 
}
