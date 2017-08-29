// Program Information ////////////////////////////////////////////////////////
/**
 * @file Agency.cpp
 * 
 * @details The Car and Agency Class.
 *
 * @version 1.00 
 *          Jia Li (30 Oct. 2016)
 *          Updated with all functions except 
 *          sorting and searching.
 *
 *          1.10 
 *          Jia Li (05 Nov. 2016)
 *          Updated with sorting and searching
 *          functions.
 *
 *
 * @Note N/A
 */



#include <iostream> 
#include <fstream> 
#include "Agency.h"

using namespace std; 

/**
 * @function Car default constructor.
 *
 * @details initialize all data members
 *          with a default value.
 *          
 */
Car::Car()
{
   make = new char[30]; 
   model = new char[30]; 
   year = 0;
   price = 0.0; 
   available = false; 
}

/**
 * @function Car parameterized constructor. 
 *
 * @details initialize the data members with 
 *          the passed-in values. 
 *          
 */
Car::Car(char *makePtr, char *modelPtr, 
           int passedYear, float passedPrice, 
           bool passedAvailable)
{ 
   make = new char[30]; 
   model = new char[30];
   
   setMake(makePtr); 
   setModel(modelPtr); 
   setYear(passedYear); 
   setPrice(passedPrice); 
   setAvailable(passedAvailable); 
}

/**
 * @function Car copy constructor. 
 *
 * @details initialize all values of 
 *          the data members with the values
 *          from the source object. 
 *          
 */
Car::Car(const Car& src)
{
   make = new char[30]; 
   model = new char[30]; 
   
   setMake(src.make); 
   setModel(src.model); 
   setYear(src.year); 
   setPrice(src.price); 
   setAvailable(src.available);
}

/**
 * @function Car destructor.
 *
 * @details deallocate all dynamic memory. 
 *          
 */
Car::~Car()
{
   delete[] make; 
   delete[] model;
   make = NULL; 
   model = NULL; 
   year = 0; 
   price = 0.0; 
   available = false; 
}

/**
 * @function copy function.
 *
 * @details copy from src obj to the calling obj.
 *          
 */
void Car::copy(Car src)
{   
   if( this != &src)
   { 
      setMake(src.make); 
      setModel(src.model); 
      setYear(src.year); 
      setPrice(src.price); 
      setAvailable(src.available);
   } 
}

/**
 * @function print function.
 *
 * @details print all the data members.
 *          
 */
void Car::print() const
{
   cout << year << " ";
   cout << make << " "; 
   cout << model << " "; 
   cout << "$" << price << " per day ";
   cout << "Available: " << boolalpha << available;
   cout << endl;          
}

/**
 * @function getMake function.
 *
 * @details returns member make.
 *          
 */
char* Car::getMake() const
{
   return make; 
}

/**
 * @function getModel function.
 *
 * @details returns member model.
 *          
 */
char* Car::getModel() const
{
   return model;
}

/**
 * @function getYear function. 
 *
 * @details returns member year.
 *          
 */
int Car::getYear() const
{
   return year;
}

/**
 * @function getPrice function.
 *
 * @details returns member price.
 *          
 */
float Car::getPrice() const
{
   return price; 
}

/**
 * @function getAvailable function.
 *
 * @details returns member available.
 *          
 */
bool Car::getAvailable() const
{
   return available; 
}

/**
 * @function setMake function. 
 *
 * @details write to the member make. 
 *          
 */
void Car::setMake(char *passedMake)
{
   char* tempMake = make; 
   char* tempPassedMake = passedMake; 
   
   while( *tempPassedMake != '\0' )
   {
      *tempMake = *tempPassedMake; 
      tempMake++; 
      tempPassedMake++;
   }
   *tempMake = '\0'; 
   
   tempMake = NULL;
   tempPassedMake = NULL; 
}

/**
 * @function setModel function. 
 *
 * @details write to the member model. 
 *          
 */
void Car::setModel(char *passedModel)
{
   char* tempModel = model; 
   char* tempPassedModel = passedModel; 

   while( *tempPassedModel != '\0' )
   {
      *tempModel = *tempPassedModel; 
      tempModel++; 
      tempPassedModel++; 
   }
   *tempModel = '\0'; 

   tempModel = NULL; 
   tempPassedModel = NULL; 
}

/**
 * @function setYear function. 
 *
 * @details write to the member year. 
 *          
 */
void Car::setYear(int passedYear)
{
   year = passedYear;
}

/**
 * @function setPrice function. 
 *
 * @details write to the member price. 
 *          
 */
void Car::setPrice(float passedPrice)
{
   price = passedPrice; 
}

/**
 * @function setAvailable function. 
 *
 * @details write to the member available. 
 *          
 */
void Car::setAvailable(bool passedAvailable)
{
   available = passedAvailable; 
}

/**
 * @function Agency default constructor. 
 *
 * @details initialize all data members of Agency class.
 *          
 */
Agency::Agency()
{
   name = new char[30]; 
   zipcode = new int[5];
   inventory = new Car[15]; 
}

/**
 * @function Agency parameterized constructor.
 *
 * @details initialize all data members of Agency class
 *          with the passed-in values.
 *          
 */
Agency::Agency(const Agency& src)
{
   name = new char[30]; 
   zipcode = new int[5];
   inventory = new Car[15];
   char* tempName = name; 
   int* tempZip = zipcode; 
   Car* tempInventory = inventory; 
   char* srcTempName = src.name; 
   int* srcTempZip = src.zipcode;
   Car* srcTempInventory = src.inventory; 

   while( *srcTempName != '\0' )
   {
      *tempName = *srcTempName; 
      tempName++; 
      srcTempName++;
   }
   *tempName = '\0'; 

   for( int i = 0; i < 5; i++ )
   {
      *tempZip = *srcTempZip; 
      tempZip++; 
      srcTempZip++; 
   }

   for( int i = 0; i < 15; i++ )
   {
      (*tempInventory).copy(*srcTempInventory); 
      tempInventory++; 
      srcTempInventory++; 
   }

   tempName = NULL; 
   tempZip = NULL; 
   tempInventory = NULL; 
   srcTempName = NULL; 
   srcTempZip = NULL;
   srcTempInventory = NULL;
   
}

/**
 * @function Agency destructor.
 *
 * @details deallocate all data members 
 *          that has dynamic memory. 
 *          
 */
Agency::~Agency()
{
   delete[] name; 
   delete[] zipcode;
   delete[] inventory; 
   name = NULL; 
   zipcode = NULL; 
   inventory = NULL; 
}

/**
 * @function readInData function.
 *
 * @details reads car data from a file.
 *          
 */
void Agency::readInData(char *filename)
{
   ifstream fin;
   char* buffer = new char[30];
   char* tempBuffer = new char[6];
   int tempYear = 0; 
   float tempPrice = 0.0; 
   bool tempAvailable = false; 
   Car* home = inventory;
   int* zipHome = zipcode; 
   char* tempBuffHome = tempBuffer;

   fin.open(filename);
    
   fin >> name; 
   fin >> tempBuffer;
   
   
   for( int i = 0; i < 5; i++ )
   {  
      *zipcode = *tempBuffer - '0';
      zipcode++;
      tempBuffer++; 
   }  
   zipcode = zipHome; 
   tempBuffer = tempBuffHome;
   for( int i = 0; i < 15; i++ )
   {
        fin >> tempYear; 
        (*inventory).setYear( tempYear );    
        fin >> buffer; 
        (*inventory).setMake( buffer );    
        fin >> buffer; 
        (*inventory).setModel( buffer );      
        fin >> tempPrice; 
        (*inventory).setPrice( tempPrice );      
        fin >> tempAvailable; 
        (*inventory).setAvailable( tempAvailable ); 
        inventory++; 
   }
   inventory = home; 
   fin.close(); 

   delete[] buffer;
   delete[] tempBuffer;
   tempBuffer = NULL; 
   zipHome = NULL;
   tempBuffHome = NULL; 
   buffer = NULL; 
   home = NULL;
}

/**
 * @function print function.
 *
 * @details prints data from the array of structs.
 *          
 */
void Agency::print() const
{
   Car* tempPtr = inventory;
   int* tempZip = zipcode; 

   cout << "name: " << name << endl; 
   cout << "zipcode: ";
   for( int i = 0; i < 5; i++ )
   {
      cout << *tempZip;
      tempZip++;
   } 
   cout << endl;
   cout << endl; 

   for( int i = 0; i < 15; i++ )
   {
      (*tempPtr).print(); 
      tempPtr++;
   }
   
   tempPtr = NULL; 
   tempZip = NULL;
}

/**
 * @function printAvailableCars function.
 *
 * @details print only the available cars in 
 *          the array of structs.
 *          
 */
void Agency::printAvailableCars() const
{
   Car* tempPtr = inventory; 

   cout << "name: " << name << endl; 
   cout << "zipcode: " << zipcode << endl; 
   cout << "the available cars are: " << endl;
   cout << endl; 

   for( int i = 0; i < 15; i++ )
   {
      if( (*tempPtr).getAvailable() == true )
      {
         (*tempPtr).print();
      } 
      tempPtr++;
   }
   
   tempPtr = NULL; 
}

/**
 * @function findMostExpensive function.
 *
 * @details find the most expensive car 
 *          in the array of structs. 
 *          
 */
void Agency::findMostExpensive() const
{
   Car max; 
   Car* tempPtr = inventory; 

   for( int i = 0; i < 15; i++ )
   {
      if( (*tempPtr).getPrice() > max.getPrice() )
      {
         max.copy(*tempPtr); 
      }
      tempPtr++;
   }
   cout << "the most expensive car is: " << endl; 
   max.print(); 

   tempPtr = NULL;
}

/**
 * @function estimateCost function.
 *
 * @details estimate the cost of renting a car based
 *          on the user input. 
 *          
 */
float Agency::estimateCost(int carNum, int numOfDays) const
{
   Car* tempPtr = inventory; 
   int carCurrentNum = carNum - 1; 
   float totalCost = 0.0; 
 
   for( int i = 0; i < carCurrentNum; i++ )
   {
      tempPtr++; 
   }
   totalCost = (float ) ( (*tempPtr).getPrice() * numOfDays ); 
   tempPtr = NULL;
   return totalCost; 
}

/**
 * @function compare function.
 *
 * @details See if the two strings are 
 *          equal, greater than, or 
 *          less than.
 *          
 */
int compare(char* str1, char* str2)
{  
   char* temp = str1; 
   char* tempTwo = str2; 

   while( (*temp != '\0') && 
         (*tempTwo != '\0') )
   {
      if( *temp < *tempTwo )
      {
         return -1; 
      }
      else if( *temp > *tempTwo )
      {
         return 1;
      }
      temp++;
      tempTwo++;  
   }
   if( *temp != '\0' )
   {
      return 1; 
   }
   if( *tempTwo != '\0' )
   {
      return -1; 
   }
   return 0; 
}

/**
 * @function sortByMake function. 
 *
 * @details sort the inventory by the 
 *          maker's alphabatical order 
 *          using insertion sort. 
 *          
 */
void Agency::sortByMake()
{
   Car* tempPtr = inventory;
   Car tempCar; 
   int index, indexTwo = 0; 
   int length = 15; 
   int flag = 0;
   int maxBound = 100;
   
   for( int i = 0; i < maxBound; i++ )
   {
      for( index = 1; index < length; index++ )
      {
         tempCar.copy(*(tempPtr + index)); 
         indexTwo = index - 1; 
         flag = compare( tempCar.getMake( ), 
                     (*(tempPtr+indexTwo)).getMake( ) ); 
         while( ( flag < 0 ) && ( indexTwo >= 0 ) )
         {
            (*(tempPtr+(indexTwo+1))).copy(*(tempPtr+indexTwo)); 
            flag = compare( tempCar.getMake( ), 
                     (*(tempPtr+indexTwo)).getMake( ) ); 
            indexTwo--; 
         }
         (*(tempPtr+(indexTwo+1))).copy( tempCar ); 
      } 
   } 
   print( );
   tempPtr = NULL;   
}

/**
 * @function sortByPrice function.
 *
 * @details sort the inventory by the car's price
 *          using bubble sort. 
 *          
 */
void Agency::sortByPrice()
{
   Car* tempPtr = inventory; 
   Car temp; 
   int index, indexTwo = 0; 
   int length = 15; 

   for( index = 1; index < length; index++ )
   {
      for( indexTwo = 0; indexTwo < (length-index); indexTwo++ )
      {
         if( (*(tempPtr+indexTwo)).getPrice( ) < 
             (*(tempPtr+indexTwo+1)).getPrice( ) ) 
         {
            temp.copy(*(tempPtr+indexTwo));
            (*(tempPtr+indexTwo)).copy(*(tempPtr+indexTwo+1));
            (*(tempPtr+indexTwo+1)).copy(temp);
         } 
      }
   }
   print( );
   tempPtr = NULL; 
}

/**
 * @function searchByMake function.
 *
 * @details Prints out all the cars with the
 *          matching string that indicate its
 *          maker. 
 *          
 */
void Agency::searchByMake(char *matchPtr) const
{
   Car* tempPtr = inventory; 

   cout << "name: " << name << endl; 
   cout << "zipcode: " << zipcode << endl; 
   cout << "the matched cars are: " << endl;
   cout << endl; 

   for( int i = 0; i < 15; i++ )
   {
      if( compare((*tempPtr).getMake(), matchPtr) == 0 )
      {
         (*tempPtr).print();
      } 
      tempPtr++;
   }
   
   tempPtr = NULL; 
}







