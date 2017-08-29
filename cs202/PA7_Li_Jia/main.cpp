// Program Information ////////////////////////////////////////////////////////
/**
 * @file main.cpp
 * 
 * @details The Test Driver.
 *
 * @version 1.00 
 *          Jia Li (21 Nov. 2016)
 *          Updated with the main function
 *
 *
 * @Note N/A
 */

#include <iostream>
#include <fstream> 
#include "polynomial.h"

using namespace std; 

/**
 * @function main.cpp
 *
 * @details test all member functions of the Polynomial class.
 *          
 */
int main( )
{
   Polynomial equationOne; 
   int* ptr = new int[6]; 
   char* filename = new char[30]; 
   int* home = ptr; 
   int result = 0; 
   int input = 0; 
   ifstream fin; 
   
   for( int i = 0; i < 6; i++ )
   {
      *ptr = i; 
      ptr++; 
   }
   ptr = home; 
   
   cout << "testing parameterized constructor\n";
   Polynomial equationTwo( 5, ptr ); 
   cout << "equationTwo is: \n";
   cout << equationTwo << endl; 

   cout << "testing copy constructor\n"; 
   Polynomial equationThree( equationTwo );
   cout << "equationThree is: \n";
   cout << equationThree << endl; 
   
   cout << "please enter an input for the polynomial: "; 
   cin >> input; 
   result = equationThree.solve(input);
   cout << "the result from substituting";
   cout << " " << input << " into the polynomial";
   cout << " 0x^5 + x^4 + 2x^3 + 3x^2 + 4x^1 + 5x^0 is: "; 
   cout << result << endl; 

   Polynomial equationFourth;
   cout << "now testing overload assignment operator\n"; 
   equationFourth = equationThree;
   cout << "equationFourth is: \n";
   cout << equationFourth << endl;
   Polynomial equationFifth = equationFourth; 
   
   cout << "now testing boolean operators: \n";

   cout << "== should return: "; 
   if( equationFifth == equationFourth )
   {
      cout << "true\n"; 
   }
   else 
   {
      cout << "false\n";
   }
   
   cout << "which means != should return: "; 
   if( equationFifth != equationFourth )
   {
      cout << "true\n"; 
   }
   else 
   {
      cout << "false\n";
   }
   
   cout << "please enter a scalar value to multiply the polynomial: ";
   cin >> input; 
   equationFifth = equationFifth * input; 

   
   cout << "please enter the filename: ";
   cin >> filename; 
   fin.open(filename); 

   Polynomial equationSixth;
   Polynomial equationSeventh; 
   Polynomial equationEighth; 
   Polynomial equationNinth; 
   Polynomial equationTenth; 
   Polynomial equationEleven; 
   Polynomial equationTwelve;

   cout << "here's equation 6, 7, 8, and 9 from the data file respectively: ";
   cout << endl;
   cout << endl;
   fin >> equationSixth; 
   cout << equationSixth << endl;
   fin >> equationSeventh; 
   cout << equationSeventh << endl; 
   fin >> equationEighth;
   cout << equationEighth << endl;
   fin >> equationNinth;
   cout << equationNinth << endl;

   cout << "when you multiply "; 
   cout << "equationSeventh";
   cout << " and "; 
   cout << "equationNinth";
   cout << " you get: \n"; 
   
   equationTenth = equationSeventh * equationNinth; 
   
   cout << equationTenth << endl;

   cout << "press 1 to add equation8 and equation9 or press 0 to subtract: ";
   cin >> input; 
   if( input == 1 )
   {
      cout << "when you add equation8 and equation9, you get: \n"; 
      equationEleven = equationEighth + equationNinth; 
      cout << equationEleven << endl; 
   }
   else
   {
      cout << "when you subtract equation8 from equation9, you get: \n"; 
      equationTwelve = equationEighth - equationNinth; 
      cout << equationTwelve << endl; 
   }

   delete[] ptr; 
   delete[] filename; 
   filename = NULL;
   ptr = NULL; 
   home = NULL; 
   return 0; 
}
