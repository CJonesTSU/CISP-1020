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
#include <cstdlib>             // need for call to system()
using namespace std;

/************************************
*     defines
*************************************/
#define SQF_IN_ACRE 43560.174; // the number of square feet in an acre

/*************************************
*     function prototype
*************************************/
void noArgsNoRet() ;

/************************************
*      global variables
*************************************/


int main()
{
     noArgsNoRet();

     system("pause");
     return 0;
}

/************************************
*      non-member functions
*************************************/
void noArgsNoRet()
{
    /************************************
    *      local variables
    *************************************/
    
    float length = 0.0;     // The length of the area as input by user
    float width = 0.0;      // The width of the area as input by user
    float sqFeet = 0.0;     // The square footage as calculated
    float acres = 0.0;      // The acreage as calculated
    
    // Get out inputs
    cout << "Please enter the length of your plot: ";
    cin >> length;
    cout << "Please enter the width of your plot: ";
    cin >> width;
    cout << "\n\n";
    
    // do our calculations
    sqFeet = length * width;
    acres = sqFeet / SQF_IN_ACRE;
}
