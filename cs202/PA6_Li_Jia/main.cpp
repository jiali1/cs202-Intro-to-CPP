// Program Information ////////////////////////////////////////////////////////
/**
 * @file main.cpp
 * 
 * @details The Test Driver.
 *
 * @version 1.20 
 *          Jia Li (05 Nov. 2016)
 *          Updated with the main function
 *
 *
 * @Note N/A
 */

#include <iostream> 
#include "Agency.h"

using namespace std; 

/**
 * @function Main Function
 *
 * @details offers the car dealing menu to the user.
 *          
 */
int main( )
{
   Agency one; 
   int num = 0;
   int carNum = 0; 
   int numOfDays = 0;
   char* filename = new char[30]; 
   char* buffer = new char[30];
   float price = 0.0;

   cout << "please enter the filename: "; 
   cin >> filename; 
   cout << endl;

   do{
      cout << "press 1 to read the file\n"; 
      cout << "press 2 to print the file\n";
      cout << "press 3 to estimate cost\n"; 
      cout << "press 4 to print the most expensive car\n";
      cout << "press 5 to print only the available cars\n";
      cout << "press 6 to sort by make\n";
      cout << "press 7 to sort by price\n"; 
      cout << "press 8 to search by a matching string for make\n";
      cout << "press 9 to exit\n"; 
      
      cin >> num;
      
      if( num == 1 )
      {
         one.readInData( filename );
      }
      else if( num == 2 )
      { 
         one.print( ); 
      }
      else if( num == 3 )
      {
         cout << "please enter the car number (1-15): ";
         cin >> carNum; 
         cout << endl << "please enter the number of days: "; 
         cin >> numOfDays; 
         price = one.estimateCost( carNum, numOfDays );
         cout << "your cost is: " << price << endl;
      }
      else if( num == 4 )
      {
         one.findMostExpensive( );
      }
      else if( num == 5 )
      {
         one.printAvailableCars( );
      }
      else if( num == 6 )
      {
         one.sortByMake( );
      }
      else if( num == 7 )
      {
         one.sortByPrice( );
      }
      else if( num == 8 )
      {
         cout << "please enter the matching string: ";
         cin >> buffer; 
         one.searchByMake(buffer);
      }
   }while(num < 9); 

   delete[] filename; 
   filename = NULL;
   delete[] buffer; 
   buffer = NULL;
   return 0;
}
