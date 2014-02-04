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
#define PI 3.141592


/************************************
*      global variables
*************************************/

/************************************
*       Function prototypes 
*************************************/
void arithmetic(int, int, float*, float*);


int main()
{

    /*********************************
    *    local variables
    *********************************/
    int inHeight = 0;       // used for our height
    int inRadius = 0;       // used for the radius  
    float* pArea;           // will be used to return the surface area
    float* pVolume;         // used to return the volume of the cylinder

    // grab memory for our return values
    pArea = new float;
    pVolume = new float;
     
    // Get our input
    cout << "Please enter the radius of your cylinder: ";
    cin >> inRadius;
    cout << "Please enter the height of your cylinder: ";
    cin >> inHeight;

    // function call
    arithmetic(inHeight, inRadius, pArea, pVolume); 

    // Generate output
    cout << endl << endl;
    cout << "*** Using the pointers ***\n";
    cout << "  area:\t\t" << *pArea << "\n";
    cout << "  volume:\t" << *pVolume << "\n";    

    // clean up
    delete pArea;
    delete pVolume;
    pArea = 0;
    pVolume = 0;

    // pause for user
    system("pause");
    return 0;
}

void arithmetic(int inHeight, int inRadius, float* pArea, float* pVolume)
{
    *pArea = (2 * PI * inRadius * inRadius) + (2 * PI * inRadius * inHeight);
    *pVolume = PI * inRadius * inRadius *  inHeight;    
}
