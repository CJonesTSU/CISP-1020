/********************************************************
*  Name:           function01
*  Author:         Chris Jones
*  Date due:       2014-01-27 
*  Description:    Write a function that takes no arguments and returns
*                  nothing.
*
*                  In the function grab two floats (length and 
*                  width) use those to calculate the square footage 
*                  Then convert that to acres (by definition 
*                  1 acre = 43560.174 square feet).
*
*                  Output variables per the assignment
********************************************************/

/***************************
*     libraries
****************************/
#include <iostream>            // needed for Cin and Cout
using namespace std;

/************************************
*     defines
*************************************/
#define  PI  3.14159

/*************************************
*     function prototype
*************************************/
void noArgsNoRet() ;

/************************************
*      global variables
*************************************/

int main()
{
    /************************************
    *      local variables
    *************************************/
     int inNum;
     cout << "go Buffalo!!!!" << endl;
     cout << "the value of PI is " << PI << "\n";
     
     cout << "\nenter a number 0~2: ";
     cin >> inNum;
     
     cout << "you entered a " << inNum << "\n";
     
     // function call
     exampleOfFunction();
     
     system("pause");
     return 0;
}

/************************************
*      non-member functions
*************************************/
void exampleOfFunction()
{
    /************************************
    *      local variables
    *************************************/
    
    // your code
}
