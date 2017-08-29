#include <iostream>
#include <fstream> 

using namespace std; 

class Polynomial
{
   public:
      Polynomial(); 
      Polynomial(int, int*);
      Polynomial(const Polynomial&);
      ~Polynomial(); 

      int solve(int); 
      
      Polynomial operator=(const Polynomial&); 
      bool operator==(const Polynomial&); 
      bool operator!=(const Polynomial&);
      Polynomial operator*(int); 
      Polynomial operator*(const Polynomial&); 
      Polynomial operator+(const Polynomial&); 
      Polynomial operator-(const Polynomial&); 
      
      friend ostream &operator<<(ostream &output, const Polynomial&); 
      friend istream &operator>>(istream &input, Polynomial&); 
      
   private:
      int* coefficients;
      int maxDegree;
};
