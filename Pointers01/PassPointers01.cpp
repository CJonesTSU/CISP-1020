/********************************************************
*   Name:           PassPointers01 
*   Author:         Chris Jones
*   Date due:       2014-02-05 
*   Description:    Request two ints from the user 
*                   pass the ints along with two float 
*                   pointer to a function. Usint the ints
*                   calculate the area and volume of a right
*                   cylinder characterized by the two ints 
*
**********************************************************/

/***************************
*     libraries
****************************/
#include <iostream>            // needed for Cin and Cout
#include <cstdlib>
using namespace std;

/************************************
*     defines
*************************************/

/************************************
*      global variables
*************************************/

/************************************
*       Function prototypes 
*************************************/

int main()
{

    /*********************************
    *    local variables
    *********************************/
    int inHeight = 0;       // used for our height
    int inRadius = 0;       // used for the radius  
    float* pArea;           // will be used to return the surface area
    float* pVolume;         // used to return the volume of the cylinder

    pArea = new float;
    pVolume = new float;
     

    // Get our input
    cout << "Please enter the height of your cylinder: ";
    inHeight << cin;
    cout << "Please enter the radius of your cylinder: ";
    inRadius << cin;

    // Generate out output

     system("pause");
     return 0;
}
