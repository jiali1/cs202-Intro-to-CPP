// Program Information ////////////////////////////////////////////////////////
/**
 * @file proj1.cpp
 * 
 * @details Read name strings and sort them into alphabatical order.
 *
 * @version 1.20 
 *          Jia Li (16 Sep. 2016)
 *          Updated with all functions
 *
 *
 * @Note N/A
 */

#include <iostream> 
#include <fstream> 

using namespace std; 

void printNames( char nameBuffer[][30] );
void sortNames( char nameBuffer[][30] );
int strcmp( char strOne[], char strTwo );
void strcpy( char strDest[], char strSrc[] );
void swap( char strOne[], char strTwo[] );

/**
 * @function Main Function
 *
 * @details Print both the unsort and sort name strings.
 *          
 */
int main( )
{
   char filename[30];
   char nameBuffer[10][30]; 
   int index = 0;
   ifstream fin;

   cout << "please enter the filename: ";
   cin >> filename; 
   fin.open(filename); 
   
   for( index = 0; index < 10; index++ )
   {
      fin >> nameBuffer[index]; 
   }
   index = 0;

   cout << "Unsorted Namelist: " << endl;
   printNames(nameBuffer);
   cout << "Sorted Namelist: " << endl;
   sortNames(nameBuffer); 
   printNames(nameBuffer);

   return 0;
}

/**
 * @function printNames Function
 *
 * @details Print name strings in the 2D array.
 *          
 */
void printNames( char nameBuffer[][30] )
{
   int index = 0; 
   int indexTwo = 0;
   
   for( index = 0; index < 10; index++ )
   {
      cout << nameBuffer[index];
      cout << endl; 
   }
   cout << endl;
}

/**
 * @function strcmp Function
 *
 * @details compare strings based on their alphabatical order.
 *          
 */
int strcmp( char strOne[], char strTwo[] )
{
   int index = 0;
   
   while( (strOne[index] != '\0') && 
         (strTwo[index] != '\0') )
   {
      if( strOne[index] < strTwo[index] )
      {
         return -1; 
      }
      else if( strOne[index] > strTwo[index] )
      {
         return 1;
      }
      index++; 
   }
   if( strOne[index] != '\0' )
   {
      return 1; 
   }
}

/**
 * @function strcpy Function
 *
 * @details copies one string into another.
 *          
 */
void strcpy( char strDest[], char strSrc[] )
{
   int index = 0; 

   while( strSrc[index] != '\0' )
   {
      strDest[index] = strSrc[index]; 
      index++;
   }
   strDest[index] = '\0';
}

/**
 * @function swap Function
 *
 * @details swap the value of two strings.
 *          
 */
void swap( char strOne[], char strTwo[] )
{
   char temp[30]; 
   
   strcpy( temp, strOne ); 
   strcpy( strOne, strTwo ); 
   strcpy( strTwo, temp ); 
}

/**
 * @function sortNames Function
 *
 * @details sort the 2D array's name strings 
 *          based on the alphabatical order.
 *          
 */
void sortNames( char nameBuffer[][30] )
{
   int index = 0;
   int indexTwo = 0; 
   int swapFlag = 0; 
   
   for( index = 0; index < 9; index++ )
   {
      for( indexTwo = 0; indexTwo < 9; indexTwo++ )
      {
         swapFlag = strcmp( nameBuffer[indexTwo], nameBuffer[indexTwo+1] ); 
         if( swapFlag == 1 )
         {
            swap( nameBuffer[indexTwo], nameBuffer[indexTwo+1] ); 
         }
      }
   }
}

