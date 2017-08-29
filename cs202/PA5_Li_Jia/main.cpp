// Program Information ////////////////////////////////////////////////////////
/**
 * @file main.cpp
 * 
 * @details The Test Driver.
 *
 * @version 1.20 
 *          Jia Li (22 Oct. 2016)
 *          Updated with the main function
 *
 *
 * @Note N/A
 */

#include <iostream> 
#include <fstream>
#include "String.h" 

using namespace std; 

/**
 * @function Main Function
 *
 * @details test all string member functions using 
 *          both an object and an array of objects.
 *          
 */
int main( )
{
   String strOne;
   String strTwo; 
   ifstream fin;
   char* temp = new char[30];
   String* strPtr = new String[30];
   String* strPtrTwo = new String[30];
   String* home = strPtr; 
   String* homeTwo = strPtrTwo; 
  
   cout << "Please enter the name of the file containing words: ";
   cin >> temp; 
   fin.open(temp);
   
   fin >> temp; 
   strOne.initialize(temp); 
   fin >> temp; 
   strTwo.initialize(temp); 

   cout << "strOne is: "; 
   strOne.print(); 
   cout << "its length is: " << strOne.length() << endl << endl; 
  
   cout << "strTwo is: ";
   strTwo.print(); 
   cout << "its length is: " << strTwo.length() << endl << endl;

   cout << "when we compare the two strings, we get: "
        << strOne.compare(strTwo) << endl << endl;

   cout << "when you concate strOne and strTwo, you get: "; 
   strOne.concat(strTwo); 
   strOne.print(); 
   cout << "its length is: " << strOne.length() << endl << endl;

   cout << "when you copied strTwo into strOne, you should get: ";
   strOne.copy(strTwo);
   strOne.print();
   cout << "its length is: " << strOne.length() << endl << endl;

   cout << "strOne should equal to strTwo, it should return 0: ";
   cout << strOne.compare(strTwo) << endl << endl;

   cout << "comparing strTwo(calling) with strOne, we got: ";
   strTwo.concat(strOne); 
   cout << strOne.compare(strTwo) << endl << endl;

   cout << "comparing strOne(calling) with strTwo, we got: ";
   strOne.concat(strTwo); 
   cout << strOne.compare(strTwo) << endl << endl;

   cout << "deallocating strOne and strTwo, their length should be 0" << endl; 
   strOne.deallocate();
   strTwo.deallocate(); 
   cout << "according to the test, strOne's length is now " << strOne.length()
        << " and strTwo's length is now " << strTwo.length() << endl << endl; 

   cout << "Here's the first array of strings: \n" << endl; 

   for( int index = 0; index < 10; index++ )
   {
      fin >> temp; 
      (*strPtr).initialize(temp); 
      cout << "str" << index << " is: ";
      (*strPtr).print(); 
      cout << "its length is: " << (*strPtr).length() << endl << endl;
      strPtr++;
   }
   strPtr--; 

   cout << "Here's the second array of strings," 
        << "which is a inverse copy of the first array: \n";
   cout << endl;    

   for( int index = 0; index < 10; index++ )
   {
      (*strPtrTwo).copy(*strPtr); 
      cout << "strTwo" << index << " is: ";
      (*strPtrTwo).print(); 
      cout << "its length is: " << (*strPtrTwo).length() << endl << endl;
      strPtr--; 
      strPtrTwo++; 
   }
   strPtr = home; 
   strPtrTwo = homeTwo; 

   for( int index = 0; index < 10; index++ )
   {
      cout << "when we compare str" << index << " and strTwo" << index
           << ", we get: "; 
      cout << (*strPtrTwo).compare(*strPtr) << endl << endl; 
      strPtr++; 
      strPtrTwo++; 
   }
   strPtr = home; 
   strPtrTwo = homeTwo; 

   cout << "if we concat arrayString 1 with arrayString 2 and into" 
        << " arrayString 1, we get: \n" << endl; 

   for( int index = 0; index < 10; index++ )
   {
      (*strPtr).concat(*strPtrTwo); 
      cout << "str" << index << " is: ";
      (*strPtr).print(); 
      cout << "its length is: " << (*strPtr).length() << endl << endl;
      cout << "when we compare str" << index << " and strTwo" << index
           << ", we get: "; 
      cout << (*strPtr).compare(*strPtrTwo) << endl << endl; 
      cout << "if we did it the other way around, we get: ";
      cout << (*strPtrTwo).compare(*strPtr) << endl << endl; 
      strPtr++; 
      strPtrTwo++; 
   }
   strPtr = home; 
   strPtrTwo = homeTwo; 
   

   fin.close();

   for( int index = 0; index < 10; index++ )
   {
      (*strPtr).deallocate();
      cout << "deallocating str" << index << " its length should be 0" << endl; 
      cout << "according to the test, str" << index << "'s length is now " << (*strPtr).length()
           << endl << endl;
      strPtr++;
   }
   strPtr = home;

   for( int index = 0; index < 10; index++ )
   {
      (*strPtrTwo).deallocate();
      cout << "deallocating strTwo" << index << " its length should be 0" << endl; 
      cout << "according to the test, strTwo" << index << "'s length is now " << (*strPtrTwo).length()
           << endl << endl;
      strPtrTwo++;
   }
   strPtrTwo = homeTwo; 
  
 
   delete[] strPtr; 
   strPtr = NULL; 
   home = NULL;
   delete[] strPtrTwo; 
   strPtrTwo = NULL; 
   homeTwo = NULL;
   delete[] temp; 
   temp = NULL;
   return 0; 
}
