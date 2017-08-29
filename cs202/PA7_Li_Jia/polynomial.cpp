// Program Information ////////////////////////////////////////////////////////
/**
 * @file polynomial.cpp
 * 
 * @details The Polynomial Class.
 *
 * @version 1.00 
 *          Jia Li (21 Nov. 2016)
 *          Updated with all member functions.
 *
 *
 * @Note N/A
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include "polynomial.h"

using namespace std; 

/**
 * @function Polynomial class constructor.
 *
 * @details Initialize the member with default values.
 *          
 */
Polynomial::Polynomial()
{
   maxDegree = 3; 
   coefficients = new int[maxDegree + 1]; 
}

/**
 * @function Parameterized constructor. 
 *
 * @details Initialize members with parameters. 
 *          
 */
Polynomial::Polynomial(int max, int* ptr)
{
   maxDegree = max;
   coefficients = ptr; 
}

/**
 * @function Copy constructor.
 *
 * @details Initialize members with the source obj.
 *          
 */
Polynomial::Polynomial(const Polynomial& src)
{
   maxDegree = src.maxDegree;  
   coefficients = new int[maxDegree + 1];
   int* temp = coefficients; 
   int* tempSrc = src.coefficients; 
   int counter = 0; 
  
   for(counter = 0; counter < (maxDegree + 1); counter++ )
   {
      *temp = *tempSrc; 
      temp++; 
      tempSrc++; 
   } 
   
   temp = NULL;
   tempSrc = NULL;
}

/**
 * @function destructor.
 *
 * @details dallocate and clear all members.
 *          
 */
Polynomial::~Polynomial()
{
   maxDegree = 0; 
   delete[] coefficients; 
   coefficients = NULL; 
}

/**
 * @function solve function.
 *
 * @details plug the parameter into the polynomial.
 *          
 */
int Polynomial::solve( int inputValue )
{
   int product = 1;
   int result = 0; 
   int index = maxDegree;
   int indexTwo = 0; 
   int counter = 0; 
   
   for( index = maxDegree; index >= 0; index-- )
   {
      product = 1;
      for( indexTwo = 0; indexTwo < counter; indexTwo++ )
      {
         product = product * inputValue; 
      }
      product = product * coefficients[index];
      result = product + result; 
      counter++;
   }
   
   return result; 
}

/**
 * @function overload assignment operator. 
 *
 * @details copies to the members with values from the src obj. 
 *          
 */
Polynomial Polynomial::operator=(const Polynomial& src)
{
   int* temp;
   int* tempSrc; 

   if( this != &src )
   {
      delete[] coefficients; 
      coefficients = NULL; 
      maxDegree = src.maxDegree; 
      coefficients = new int[maxDegree + 1]; 
      temp = coefficients; 
      tempSrc = src.coefficients;  
  
      for(int counter = 0; counter < (maxDegree + 1); counter++ )
      {
         *temp = *tempSrc; 
         temp++; 
         tempSrc++; 
      } 
   }
   temp = NULL; 
   tempSrc = NULL;
   return *this; 
}

/**
 * @function overload equality operator. 
 *
 * @details checks if the src obj is equal to the calling obj. 
 *          
 */
bool Polynomial::operator==(const Polynomial& src)
{
   int index = 0;
   int counter = 0;

   if( maxDegree == src.maxDegree )
   {
      for( int i = 0; i <= maxDegree; i++ )
      {
         if( coefficients[i] != src.coefficients[i] )
         {
            return false; 
         }
      }
      return true; 
   }
   else if( maxDegree > src.maxDegree )
   {
      counter = maxDegree - src.maxDegree; 
      for( index = 0; index < counter; index++ )
      {
         if( coefficients[index] != 0 )
         {
            return false; 
         }
      } 
      for( int i = 0; i <= src.maxDegree; i++ )
      {
         if( coefficients[index] != src.coefficients[i] )
         {
            return false; 
         }
         index++; 
      }
      return true; 
   }
   else 
   {
      counter = src.maxDegree - maxDegree; 
      for( index = 0; index < counter; index++ )
      {
         if( src.coefficients[index] != 0 )
         {
            return false; 
         }
      } 
      for( int i = 0; i <= maxDegree; i++ )
      {
         if( src.coefficients[index] != coefficients[i] )
         {
            return false; 
         }
         index++; 
      }
      return true; 
   }
}

/**
 * @function overload inequality operator. 
 *
 * @details checks if the src obj is not equal to the calling obj or not. 
 *          
 */
bool Polynomial::operator!=(const Polynomial& src)
{
   if( *this == src )
   {
      return false; 
   }
   return true; 
}

/**
 * @function overload product operator.
 *
 * @details times the coefficients with an scalar input. 
 *          
 */
Polynomial Polynomial::operator*(int value)
{
   for( int i = 0; i <= maxDegree; i++ )
   {
      coefficients[i] *= value; 
   }
   return *this; 
}

/**
 * @function overload addition operator.
 *
 * @details add the src obj to the calling obj.
 *          
 */
Polynomial Polynomial::operator+(const Polynomial& src)
{
   int counter = 0; 
   int* temp; 

   if( maxDegree == src.maxDegree )
   {
      for( int i = 0; i <= maxDegree; i++ )
      {
         coefficients[i] = src.coefficients[i] + coefficients[i];
      }
   }
   else if( maxDegree > src.maxDegree )
   {
      counter = maxDegree - src.maxDegree; 
      for( int i = 0; i <= src.maxDegree; i++ )
      {
         coefficients[counter] = src.coefficients[i] 
                              + coefficients[counter]; 
         counter++;
      }
   }
   else 
   {
      temp = coefficients;  
      coefficients = new int[src.maxDegree + 1];
      counter = src.maxDegree - maxDegree; 
      maxDegree = src.maxDegree; 

      for( int i = 0; i < counter; i++ )
      {
         coefficients[i] = src.coefficients[i]; 
      } 
      for( int i = 0; i <= maxDegree; i++ )
      {
         coefficients[counter] = src.coefficients[counter] + temp[i]; 
      }
      delete[] temp;
      temp = NULL;
   }
   return *this;
}

/**
 * @function overload subtraction operator.
 *
 * @details subtract the calling obj from the src obj.
 *          
 */ 
Polynomial Polynomial::operator-(const Polynomial& src)
{
   int counter = 0; 
   int* temp; 

   if( maxDegree == src.maxDegree )
   {
      for( int i = 0; i <= maxDegree; i++ )
      {
         coefficients[i] = coefficients[i] - src.coefficients[i];
      }
   }
   else if( maxDegree > src.maxDegree )
   {
      counter = maxDegree - src.maxDegree; 
      for( int i = 0; i <= src.maxDegree; i++ )
      {
         coefficients[counter] = coefficients[counter] - src.coefficients[i]; 
         counter++;
      }
   }
   else 
   {
      temp = coefficients;  
      coefficients = new int[src.maxDegree + 1];
      counter = src.maxDegree - maxDegree; 
      maxDegree = src.maxDegree; 

      for( int i = 0; i < counter; i++ )
      {
         coefficients[i] = 0 - src.coefficients[i]; 
      } 
      for( int i = 0; i <= maxDegree; i++ )
      {
         coefficients[counter] = temp[i] - src.coefficients[counter]; 
      }
      delete[] temp;
      temp = NULL;
   }
   return *this;
}

/**
 * @function overload product operator.  
 *
 * @details times the src obj with the calling obj to form 
 *          a new polynomial. 
 *          
 */
Polynomial Polynomial::operator*(const Polynomial& src)
{
   int* temp = coefficients; 
   coefficients = new int[src.maxDegree + maxDegree]; 
   
   for( int i = 0; i < (src.maxDegree + maxDegree); i++ )
   {
      coefficients[i] = 0; 
   } 

   for( int i = 0; i <= maxDegree; i++ )
   {
      for( int j = 0; j <= src.maxDegree; j++ )
      {
         coefficients[i+j] += temp[i] * src.coefficients[j]; 
      }
   }
   maxDegree = (src.maxDegree + maxDegree);
   return *this; 
}

/**
 * @function overload extraction operator.
 *
 * @details extracts all data members from the src obj.
 *          
 */
ostream& operator<<(ostream& output, const Polynomial& src)
{
   int counter = 0; 

   output << "maximum degree is: " << src.maxDegree << endl; 
   output << endl; 

   counter = src.maxDegree; 
   for( int i = 0; i <= src.maxDegree; i++ )
   {
      output << src.coefficients[i];
      output << "x^" << counter; 
      if( i != src.maxDegree )
      {  
         output << " + "; 
      }
      counter--; 
   }
   output << endl; 

   return output;
} 

/**
 * @function overload insertion operator. 
 *
 * @details insert to the data members with values. 
 *          
 */
istream& operator>>(istream& input, Polynomial& dest)
{
   input >> dest.maxDegree;
   delete[] dest.coefficients; 
   dest.coefficients = new int[dest.maxDegree + 1];
 
   for( int i = 0; i <= dest.maxDegree; i++ )
   {
      input >> dest.coefficients[i];  
   }
   return input; 
}        





