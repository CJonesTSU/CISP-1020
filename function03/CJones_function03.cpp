/********************************************************
*  Name:           function03
*  Author:         Chris Jones
*  Date due:       2014-01-27 
*  Description:    Write a function that takes no arguments and returns
*                  a value represent the acreage.
*
*                  In function grab two floats (length and 
*                  width).  Calculate the square footage and acreage,
*                  (by definition 1 acre = 43560.174 square feet).
*                  While in the function print the header, length and width
*                  
*                  Return the acreage to main and generate our remaining 
*                  output.
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
float noArgsHasRet();

/************************************
*      global variables
*************************************/


int main()
{
    /************************************
    *      local variables
    *************************************/
    float acres = 0.0;      // The acreage as calculated     

    
    acres = noArgsHasRet();
    cout << "contains " << acres << " acres" << "\n";   
    system("pause");
    return 0;
}

/************************************
*      functions
*************************************/
float noArgsHasRet()
{
    /************************************
    *      local variables
    *************************************/
    float length = 0.0;     // The length of the area as input by user
    float width = 0.0;      // The width of the area as input by user
    float sqFeet = 0.0;     // The square footage as calculated
    float acres = 0.0;      // The acreage as calculated    

    // Get our inputs
    cout << "Please enter the length of your plot: ";
    cin >> length;
    cout << "Please enter the width of your plot: ";
    cin >> width;
    cout << "\n\n";    

    // do our calculations
    sqFeet = length * width;
    acres = sqFeet / SQF_IN_ACRE;
    
    // Build our output
    cout << "A parcel of land with the dimensions of\n";
	cout << "\tlength\t" << length << "\n";
	cout << "\twidth\t" << width << "\n";
    
    //return
    return acres;
}
