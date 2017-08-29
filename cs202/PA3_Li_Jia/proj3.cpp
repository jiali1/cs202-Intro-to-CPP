// Program Information ////////////////////////////////////////////////////////
/**
 * @file proj3.cpp
 * 
 * @details A menu that shares information with the car buyer.
 *
 * @version 1.20 
 *          Jia Li (7 Oct. 2016)
 *          Updated with all functions
 *
 *
 * @Note N/A
 */


#include<iostream>
#include<fstream>

using namespace std;

struct RentalCar
{
   char buffer[30];
   char bufferTwo[30];
   char* make = buffer;
   char* model = bufferTwo; 
   int year; 
   float price; 
   bool available; 
};

struct Agency
{
   char buffer[30];
   int numBuffer[5];
   RentalCar carBuffer[5];
   char* name = buffer; 
   int* zipcode = numBuffer; 
   RentalCar* inventory = carBuffer; 
};

void read( Agency* agencyPtr ); 
void print( Agency* agencyPtr ); 
void charToInt(char* str, int* numStr );
void estimateCost( Agency* agencyPtr );
bool strcmp( char* strOne, char* strTwo );
void findMostExpensiveCar( Agency* agencyPtr );
void printOnlyAvailable( Agency* agencyPtr );

/**
 * @function Main Function
 *
 * @details offers the car dealing menu to the user.
 *          
 */
int main( )
{
   Agency* agencyPtr; 
   Agency agencyArr[3];
   agencyPtr = agencyArr; 
   int num = 0;

   do{
      cout << "press 1 to read the file\n"; 
      cout << "press 2 to print and output the file\n";
      cout << "press 3 to estimate cost\n"; 
      cout << "press 4 to print the most expensive car\n";
      cout << "press 5 to print only the available cars\n";
      cout << "press 6 to exit\n"; 
      
      cin >> num;
      
      if( num == 1 )
      {
         read( agencyPtr );
      }
      else if( num == 2 )
      { 
         print( agencyPtr ); 
      }
      else if( num == 3 )
      {
         estimateCost( agencyPtr );
      }
      else if( num == 4 )
      {
         findMostExpensiveCar( agencyPtr );
      }
      else if( num == 5 )
      {
         printOnlyAvailable( agencyPtr );
      }
   }while(num < 6); 
 
   agencyPtr = NULL;
   return 0; 
}

/**
 * @function read function.
 *
 * @details reads car data from a file.
 *          
 */
void read( Agency* agencyPtr )
{
   ifstream fin;
   RentalCar* carTmpPtr; 
   char buffer[30];
   char tmpBuffer[5]; 
   cout << "please enter filename: \n"; 
   cin >> buffer; 
   fin.open(buffer); 
   
   for( int i = 0; i < 3; i++ )
   { 
      fin >> (*agencyPtr).name; 
      fin >> tmpBuffer;
      charToInt( tmpBuffer, (*agencyPtr).zipcode);  
      carTmpPtr = (*agencyPtr).inventory;
      for( int j = 0; j < 5; j++ )
      {
         fin >> (*carTmpPtr).year;  
         fin >> (*carTmpPtr).make; 
         fin >> (*carTmpPtr).model; 
         fin >> (*carTmpPtr).price; 
         fin >> (*carTmpPtr).available; 
         carTmpPtr++;
      }
      agencyPtr++;
   }
   fin.close(); 

   carTmpPtr = NULL; 
   agencyPtr = NULL;
}

/**
 * @function print function.
 *
 * @details prints data from the array of structs.
 *          
 */
void print( Agency* agencyPtr )
{
   ofstream fout; 
   RentalCar* carTmpPtr;
   int* tmp; 

   fout.open("output.txt");
   for( int i = 0; i < 3; i++ )
   {
      cout << (*agencyPtr).name << " "; 
      fout << (*agencyPtr).name << " ";
      tmp = (*agencyPtr).zipcode; 
      for( int k = 0; k < 5; k++ )
      {
         cout << *tmp; 
         fout << *tmp;
         tmp++;
      }
      
      tmp = (*agencyPtr).zipcode;
      cout << endl; 
      fout << endl; 
      carTmpPtr = (*agencyPtr).inventory;
      for( int j = 0; j < 5; j++ )
      {
         cout << (*carTmpPtr).year << " ";
         fout << (*carTmpPtr).year << " ";
         cout << (*carTmpPtr).make << " "; 
         fout << (*carTmpPtr).make << " ";
         cout << (*carTmpPtr).model << " "; 
         fout << (*carTmpPtr).model << " ";
         cout << "$" << (*carTmpPtr).price << " per day ";
         fout << "$" << (*carTmpPtr).price << " per day ";
         cout << "Available: " << boolalpha << (*carTmpPtr).available;
         fout << "Available: " << boolalpha << (*carTmpPtr).available;
         cout << endl; 
         fout << endl;
         carTmpPtr++;
      }
      carTmpPtr = (*agencyPtr).inventory;
      agencyPtr++;
   }

   fout.close();
   carTmpPtr = NULL;
   tmp = NULL;
   agencyPtr = NULL;
}

/**
 * @function charToInt function.
 *
 * @details convert a character string to a integer string.
 *          
 */
void charToInt(char* str, int* numStr )
{
   char* strPtr = str; 
   while( *strPtr != '\0' )
   {
      *numStr = *strPtr - '0'; 
      strPtr++;
      numStr++; 
   }
   strPtr = NULL; 
   numStr = NULL;
}

/**
 * @function estimateCost function.
 *
 * @details estimate the cost of renting a car based
 *          on the user input. 
 *          
 */
void estimateCost( Agency* agencyPtr )
{
   char buffer[30];
   int carNum = 0;
   float cost = 0.0;
   bool flag = false;
   RentalCar* carPtr;  
   
   cout << "please enter the agency name: ";
   cin >> buffer; 
   cout << endl;
   cout << "please enter the car number: ";
   cin >> carNum; 
   cout << endl; 

   for( int i = 0; i < 3; i++ )
   {      
      flag = strcmp( buffer, (*agencyPtr).name );
      if( flag )
      {
         carPtr = (*agencyPtr).inventory; 
         for( int j = 0; j < ( carNum - 1); j++ )
         {
            carPtr++;  
         }
         cost = (*carPtr).price; 
      }
      agencyPtr++;
   }
   cout << "Your price is: " << cost << endl; 
   carPtr = NULL;
   agencyPtr = NULL;
}

/**
 * @function strcmp Function
 *
 * @details compare two strings to see if they are the same.
 *          
 */
bool strcmp( char* strOne, char* strTwo )
{
   while( *strOne != '\0' )
   {
      if( *strOne != *strTwo )
      {
         return false; 
      }
      strOne++;
      strTwo++;
   }
   if( *strOne != *strTwo )
   {
      return false; 
   }
   strOne = strTwo = NULL;
   return true; 
}

/**
 * @function findMostExpensiveCar function.
 *
 * @details find the most expensive car 
 *          in the array of structs. 
 *          
 */
void findMostExpensiveCar( Agency* agencyPtr )
{
   float max = 0.0; 
   RentalCar* carPtr;
   Agency* homePtr = agencyPtr;
   int* tmp;  

   for( int i = 0; i < 3; i++ )
   {
      carPtr = (*agencyPtr).inventory;
      for( int j = 0; j < 5; j++)
      {
         if( (*carPtr).price > max )
         {
            max = (*carPtr).price;
         }
         carPtr++;
      }
      agencyPtr++;
   }
   agencyPtr = homePtr; 

   for( int i = 0; i < 3; i++ )
   {
      carPtr = (*agencyPtr).inventory;
      for( int j = 0; j < 5; j++)
      {
         if( (*carPtr).price == max )
         {
            cout << "the most expensive is: \n";
            cout << (*agencyPtr).name << " "; 
	    tmp = (*agencyPtr).zipcode; 
	    for( int k = 0; k < 5; k++ )
	    {
	       cout << *tmp; 
	       tmp++;
	    }
            cout << endl;
            cout << (*carPtr).year << " ";
            cout << (*carPtr).make << " "; 
            cout << (*carPtr).model << " "; 
            cout << "$" << (*carPtr).price << " per day ";
            cout << "Available: " << boolalpha << (*carPtr).available;
            cout << endl; 
         }
         carPtr++;
      }
      agencyPtr++;
   }
   
}

/**
 * @function printOnlyAvailable function.
 *
 * @details print only the available cars in 
 *          the array of structs.
 *          
 */
void printOnlyAvailable( Agency* agencyPtr )
{
   RentalCar* carTmpPtr;
   int* tmp; 
   for( int i = 0; i < 3; i++ )
   {
      cout << (*agencyPtr).name << " "; 
      tmp = (*agencyPtr).zipcode; 
      for( int k = 0; k < 5; k++ )
      {
         cout << *tmp; 
         tmp++;
      }
      tmp = (*agencyPtr).zipcode;
      cout << endl; 
      carTmpPtr = (*agencyPtr).inventory;
      for( int j = 0; j < 5; j++ )
      {
         if( (*carTmpPtr).available == true )
         {
            cout << (*carTmpPtr).year << " ";
            cout << (*carTmpPtr).make << " "; 
            cout << (*carTmpPtr).model << " "; 
            cout << "$" << (*carTmpPtr).price << " per day ";
            cout << "Available: " << boolalpha << (*carTmpPtr).available;
            cout << endl; 
         }
         carTmpPtr++;
      }
      carTmpPtr = (*agencyPtr).inventory;
      agencyPtr++;
   }

   carTmpPtr = NULL;
   tmp = NULL;
   agencyPtr = NULL;
}
