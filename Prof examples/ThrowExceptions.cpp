// This program demonstrates an exception being thrown and caught.
#include <iostream>
#include <string>
using namespace std;

// Function prototype
double divide(int, int);
void badAlloc();
int Fex02(int inNum01, int inNUm02);
void Fex01();
int Fex02A(int inNum01, int inNUm02);
void Fex01A();
int Fex03A(int inNum01, int inNUm02);

int main()
{
   int num1, num2;  // To hold two numbers
   double quotient; // To hold the quotient of the numbers

   // Get two numbers.
   cout << "Enter two numbers: ";
   cin >> num1 >> num2;

   // Divide num1 by num2 and catch any
   // potential exceptions.
   try
   {
      quotient = divide(num1, num2);
      cout << "The quotient is " << quotient << endl;
   }
   
   /*********************************/
   catch (string exceptionString)
   {
      cout << exceptionString;
   }
   /*********************************/
   
   /*******************************
   catch (int exceptionString)
   {
      cout << exceptionString;
   }
   /*******************************/
   
   /******************************
   catch (string exceptionString)
   {
      cout << exceptionString;
   }
   /******************************/
   
   
   cout << "End of the program.\n";
   // badAlloc();
   Fex01();
   Fex01A();
   system("pause");
   
   return 0;
}

//********************************************
// The divide function divides numerator by  *
// denominator. If denominator is zero, the  *
// function throws an exception.             *
//********************************************

double divide(int numerator, int denominator)
{
   if (denominator == 0)
   {
	  string exceptionString = "ERROR: Cannot divide by zero.\n";
      throw exceptionString;
   }

   return static_cast<double>(numerator) / denominator;
}

void badAlloc()
{
   double *ptr;   // Pointer to double
   cout << "******************************\n";
   cout << "*     calling a rpe          *\n";
   cout << "******************************\n\n";

   try
   {
      ptr = new double [1000000000];
      //ptr = new double [10000];
   }
   catch (bad_alloc)
   {
      cout << "Insufficient memory.\n";
   }
   cout << "end program\n";
}

void Fex01()
{
     int inNum01;
     int inNum02;
     
     cout << "enter the numerator:   ";
     cin >> inNum01;
     cout << "enter the denominator: ";
     cin >> inNum02;     
     
     try
     {
        Fex02(inNum01, inNum02);
     }
     catch (string exceptionString)
     {
        cout << exceptionString;
     }
    
}

int Fex02(int inNum01, int inNum02)
{
    if(inNum02 == 0)
    {
 	   string exceptionString = "ERROR: Cannot divide by zero.\n";
       throw exceptionString;
    }
}

void Fex01A()
{
     int inNum01;
     int inNum02;
     
     cout << "enter the numerator:   ";
     cin >> inNum01;
     cout << "enter the denominator: ";
     cin >> inNum02;     
     
     try
     {
        Fex02A(inNum01, inNum02);
     }
     catch (string exceptionString)
     {
        cout << exceptionString;
     }
    
}

int Fex02A(int inNum01, int inNum02)
{
    Fex03A(inNum01, inNum02);
}
int Fex03A(int inNum01, int inNum02)
{
    //try
    {
      if(inNum02 < 0 || inNum01 < 0)
      {
 	   string exceptionStringx = "ERROR: negative area.\n";
       throw exceptionStringx;
      }
    }
    cout << "end Fex03\n\n";
}
