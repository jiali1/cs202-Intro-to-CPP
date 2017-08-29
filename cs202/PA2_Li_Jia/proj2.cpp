// Program Information ////////////////////////////////////////////////////////
/**
 * @file proj2.cpp
 * 
 * @details A menu that shares information with the car buyer.
 *
 * @version 1.20 
 *          Jia Li (23 Sep. 2016)
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
   char make[30];
   char model[30]; 
   int year; 
   float price;
   bool available;
};

void readData( RentalCar carData[] );
void printData( RentalCar carData[] );
void estimateCost( RentalCar carData[] );
void findMostExpensive( RentalCar carData[] ); 
void printOnlyAvailableCars( RentalCar carData[] ); 

/**
 * @function Main Function
 *
 * @details offers the car dealing menu to the user.
 *          
 */
int main( )
{
   RentalCar carData[10];
   int choice = 0; 

   readData( carData ); 

   do 
   {
      cout << "press 1 to print out the data for all the cars\n";
      cout << "press 2 to estimate cost for renting a car\n";
      cout << "press 3 to find the most expensive car\n";
      cout << "press 4 to print the available cars\n";
      cout << "press 5 to quit\n"; 

      cin >> choice; 

      if( choice == 1 )
      {
         printData( carData );
      }
      else if( choice == 2 )
      { 
         estimateCost( carData ); 
      }
      else if( choice == 3 )
      {
         findMostExpensive( carData );
      }
      else if( choice == 4 )
      {
         printOnlyAvailableCars( carData );
      } 
   }while( choice < 5 );

   return 0;
}

/**
 * @function readData function.
 *
 * @details reads car data from a file.
 *          
 */
void readData( RentalCar carData[] )
{
   ifstream fin; 
   char buffer[30];
   int index = 0;

   cout << "Please enter the filename: ";
   cin >> buffer; 
   cout << endl;
   fin.open(buffer);

   for( index = 0; index < 10; index++ )
   {
      fin >> carData[index].year;
      fin >> carData[index].make;
      fin >> carData[index].model;
      fin >> carData[index].price;
      fin >> carData[index].available;
   }

   fin.close();
}

/**
 * @function printData function.
 *
 * @details prints data from the array of structs.
 *          
 */
void printData( RentalCar carData[] )
{
   int index = 0;
   
   for( index = 0; index < 10; index++ )
   {
      cout << carData[index].year << " "; 
      cout << carData[index].make << " ";
      cout << carData[index].model << " "; 
      cout << "$" << carData[index].price << " ";
      cout << "per day " << "Available: ";
      cout << boolalpha << carData[index].available << endl; 
      cout << endl;
   }
}

/**
 * @function estimateCost function.
 *
 * @details estimate the cost of renting a car based
 *          on the user input. 
 *          
 */
void estimateCost( RentalCar carData[] )
{
   int carNumber = 0; 
   int numberOfDays = 0;
   float cost = 0.0; 

   cout << "please enter the car number: ";
   cin >> carNumber; 
   cout << endl; 
   cout << "how many days you want to rent the car? "; 
   cin >> numberOfDays; 
   cout << endl; 

   carNumber--; 
   cost = numberOfDays * carData[carNumber].price; 
   cout << "Your total cost is: " << cost << endl; 
   cout << endl;
}

/**
 * @function findMostExpensive function.
 *
 * @details find the most expensive car 
 *          in the array of structs. 
 *          
 */
void findMostExpensive( RentalCar carData[] )
{
   float maxPrice = 0.0; 
   int index = 0;
   int carIndex = 0;  
 
   for( index = 0; index < 10; index++ )
   {
      if( carData[index].price > maxPrice )
      {
         maxPrice = carData[index].price; 
      }
   }
   for( index = 0; index < 10; index++ )
   {
      if( maxPrice == carData[index].price )
      {
         carIndex = index; 
      }
   }
   cout << "the most expensive car is: " << endl;
   cout << carData[carIndex].year << " "; 
   cout << carData[carIndex].make << " ";
   cout << carData[carIndex].model << " "; 
   cout << "$" << carData[carIndex].price << " ";
   cout << "per day " << "Available: ";
   cout << boolalpha << carData[carIndex].available << endl; 
   cout << endl;
}

/**
 * @function printOnlyAvailableCars function.
 *
 * @details print only the available cars in 
 *          the array of structs.
 *          
 */
void printOnlyAvailableCars( RentalCar carData[] )
{
   int index = 0;
   
   for( index = 0; index < 10; index++ )
   {
      if( carData[index].available == true )
      {
         cout << carData[index].year << " "; 
         cout << carData[index].make << " ";
         cout << carData[index].model << " "; 
         cout << "$" << carData[index].price << " ";
         cout << "per day " << "Available: ";
         cout << boolalpha << carData[index].available 
              << endl; 
         cout << endl;
      }
   }
}
