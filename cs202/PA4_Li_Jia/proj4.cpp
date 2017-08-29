// Program Information ////////////////////////////////////////////////////////
/**
 * @file proj4.cpp
 * 
 * @details decodes a cipher into a readable quote.
 *
 * @version 1.20 
 *          Jia Li (14 Oct. 2016)
 *          Updated with all functions
 *
 *
 * @Note N/A
 */

#include <iostream>
#include <fstream>

using namespace std;
 
struct Pieces
{
   char* word;
   int jump; 
};

int strLen(char* str);
void strConcat(char* strOne, char* strTwo, char* strThree); 
void strCopy(char* to, char* from);
void read(Pieces* cipher, int* keys, int &numOfWords, int &numOfKeys);
void decode(Pieces* cipher, int* keys, char* message, int numOfWords, int numOfKeys ); 

/**
 * @function Main Function
 *
 * @details read in a cipher file and converts it into a quote message.
 *          
 */
int main( )
{

   int* keys = new int[100]; 
   Pieces* cipher = new Pieces[100]; 
   char* message = new char[100]; 
   int numOfWords = 0;
   int numOfKeys = 0;
   int index = 0;
   Pieces* home = cipher;

   read(cipher, keys, numOfWords, numOfKeys);
   decode(cipher, keys, message, numOfWords, numOfKeys); 
   cout << endl << "Your decoded message: " << endl;
   cout << message << endl << endl; 
   
   for( index = 0; index < numOfWords; index++ )
   {
      delete[] (*cipher).word; 
      (*cipher).word = NULL;
      cipher++;
   }
   cipher = home;
   delete[] keys; 
   delete[] cipher; 
   delete[] message; 
   keys = NULL; 
   cipher = NULL; 
   message = NULL; 
   
   return 0;
}

/**
 * @function decode Function
 *
 * @details decode the cipher based on the key into the message.
 *          
 */
void decode(Pieces* cipher, int* keys, char* message, int numOfWords, int numOfKeys )
{
   Pieces* homePtr = cipher; 
   char* buffer = new char[20];
   int numOfJumps = 0;
   int jumpIndex = 0;
   char* cHome = buffer;
   char* messageHome = message; 

   while( numOfKeys > 0 ) 
   {
      for( int i = 0; i < *keys; i++ ) 
      {
         cipher++; 
         jumpIndex++;
      }
      numOfJumps = (*cipher).jump;
      while(numOfJumps != 0)
      {
         for( int i = 0; i < numOfJumps; i++ )
         {
            if( jumpIndex == ( numOfWords - 1 ) )
            {
               cipher = homePtr;
               jumpIndex = 0; 
            }
            else 
            {
               jumpIndex++;
               cipher++;
            } 
         }
         numOfJumps = (*cipher).jump;
      }
      if( (*cipher).jump == 0 )
      {
         strCopy(buffer, (*cipher).word);
         while( *buffer != '\0' )
         {
            *message = *buffer;
            message++; 
            buffer++; 
         }
         *message = ' '; 
         message++;
      }
      jumpIndex = 0;
      buffer = cHome;
      cipher = homePtr;
      numOfKeys--; 
      keys++;
   }
   *message = '\0'; 
   message = messageHome; 
   delete[] buffer; 
   buffer = NULL; 
   cipher = NULL;
   keys = NULL; 
   message = NULL; 
   homePtr = NULL; 
   cHome = NULL;  
   messageHome = NULL; 
}

/**
 * @function read Function
 *
 * @details read the cipher and the keys into the struct and int array.
 *          
 */
void read(Pieces* cipher, int* keys, int &numOfWords, int &numOfKeys)
{
   char* buffer = new char[20]; 
   int length = 0;  
   ifstream fin;
   int index = 0;  
   
   cout << "please enter the filename: ";
   cin >> buffer; 
   fin.open(buffer);
   fin >> numOfWords; 
   fin >> numOfKeys; 
   
   for( index = 0; index < numOfWords; index++ )
   {
      fin >> buffer; 
      length = strLen(buffer) + 1; 
      (*cipher).word = new char[length]; 
      strCopy( (*cipher).word, buffer ); 
      fin >> (*cipher).jump; 
      cipher++; 
   }
   index = 0;
  
   for( index = 0; index < numOfKeys; index++ )
   {
      fin >> *keys; 
      keys++; 
   }
	 
   fin.close(); 

   delete[] buffer;
   cipher = NULL;
   keys = NULL; 
   buffer = NULL; 
}

/**
 * @function strCopy Function
 *
 * @details copies from one string into another.
 *          
 */
void strCopy(char* to, char* from)
{
   while( *from != '\0' )
   {
      *to = *from; 
      from++;
      to++; 
   }
   *to = '\0'; 
}

/**
 * @function strLen Function
 *
 * @details returns the length of an string.
 *          
 */
int strLen(char* str)
{
   int length = 0; 
   while( *str != '\0' )
   {
      str++; 
      length++;
   }
   str = NULL; 
   return length;
}

/**
 * @function strConcat Function
 *
 * @details combines two strings into one.
 *          
 */
void strConcat(char* strOne, char* strTwo, char* strThree)
{
   int lengthOne = strLen(strOne); 
   int lengthTwo = strLen(strTwo); 
   int lengthThree = lengthOne + lengthTwo + 1; 
   char* homePtr; 

   homePtr = strThree;
   
   while( *strOne != '\0' )
   {
      *strThree = *strOne; 
      strThree++; 
      strOne++; 
   }
   while( *strTwo != '\0' )
   {
      *strThree = *strTwo; 
      *strThree++;
      *strTwo++; 
   }
   *strThree = '\0';
   strThree = homePtr; 
   strOne = strTwo = NULL; 
}
