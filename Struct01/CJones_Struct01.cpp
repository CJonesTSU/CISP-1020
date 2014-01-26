/********************************************************
*  Name:           Struct01
*  Author:         Chris Jones
*  Date due:       2014-01-27 
*  Description:    Create a structure to hold personel info
*                  for the United Federation of Planets. NOT  
*                  for use in the Terran Empire! 
*                  (no mirror universe badies need apply!)
*                  
*                  Instantiate the structure
*
*                  Read input into each field in the structure 
*                  Then output that same date 
*
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


/*************************************
*     function prototype
*************************************/


/************************************
*      global variables
*************************************/


int main()
{
    /****************************
    *     Structure definition
    *****************************/
    struct StarTrekPersonel
    {
       string ID;          // contains the entity's ID
       string name;        // contains the entity's name
       string address;     // contains the entity's address
       string city;        // contains the entity's city
       string state;       // contains the entity's state
       string zip;         // contains the entity's zip code
       string planet;      // contains the entity's plant
    };
    
    /****************************
    *     local variables
    *****************************/
    StarTrekPersonel stpSample;
    
    //Get our input  
    cout << "Welcome to the Star Fleet Entity Identification Portal\n\n";
    cout << "Please enter the ID of the entity: ";
    cin >> stpSample.ID;
    cout << "Please enter the name of the entity: ";
    cin >> stpSample.name;
    cout << "Please enter the address of the entity: ";
    cin >> stpSample.address;
    cout << "Please enter the city of the entity: ";
    cin >> stpSample.city;
    cout << "Please enter the state of the entity: ";
    cin >> stpSample.state;
    cout << "Please enter the zip of the entity: ";
    cin >> stpSample.zip;
    cout << "Please enter the planet of the entity: ";
    cin >> stpSample.planet;
    cout << "\n\n";    
    cout << "****  \"the stpSample field\" ****\n";
    cout << "  ID\t\t" << stpSample.ID << "\n";
    cout << "  Name\t\t" << stpSample.name << "\n";
    cout << "  Address\t" << stpSample.address << "\n";
    cout << "  City\t\t" << stpSample.city << "\n";
    cout << "  State\t\t" << stpSample.state << "\n";
    cout << "  Zip\t\t" << stpSample.zip << "\n";
    cout << "  Planet\t" << stpSample.planet << "\n";    
    cout << "\n\n";
    system("pause");
    return 0;
}

