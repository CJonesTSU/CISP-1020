/********************************************************
*   Name:           StructPointer
*   Author:         Chris Jones
*   Date due:       2014-02-03
*   Description:    Modify the program provided to use
*                   pointers to access the structure
*                   members
*
*
**********************************************************/

/********************************************************
*  Name:           Struct01
*  Author:         Debra Bone
*  Date due:       01/23/14
*  Description:    Assignment #1 - create a Struct
**********************************************************/

/***************************
*     libraries
****************************/
#include <iostream>            // needed for Cin and Cout
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

/************************************
*     defines
*************************************/
/************************************
*      global variables
*************************************/
struct starTrekPersonel     //Create a struct with the following data items:
{
       string ID;          //a.	String	ID
       string name;        //b.	String 	name
       string address;     //c.	String	address
       string city;        //d.	String	city
       string state;       //e.	String	state
       string zip;         //f.	String	zip
       string planet;      //g.	String	planet
};


int main()
{

    /*********************************
    *    local variables
    *********************************/
    starTrekPersonel* stpPX = new  starTrekPersonel;
    
    // Get our input
    cout << "Welcome to the Star Fleet Entity Identification Portal" << endl;
    cout << endl;
    cout << "Please enter the ID of the entity: ";
    getline(cin, stpPX->ID);         
    cout << "Please enter the Name of the entity: ";
    getline(cin, stpPX->name);
    cout << "Please enter the Address of the entity: ";
    getline(cin, stpPX->address);
    cout << "Please enter the City of the entity: ";
    getline(cin, stpPX->city);
    cout << "Please enter the State of the entity: ";
    getline(cin, stpPX->state);
    cout << "Please enter the Zip of the entity: ";
    getline(cin, stpPX->zip);
    cout << "Please enter the Planet of the entity: ";
    getline(cin, (*stpPX).planet);  // just did this with the *deref so you knew I could


    // Generate out output
    cout << endl << endl;
    cout << "*******  \"The Entity Entered\"  *******" << endl;
    cout << "   ID:\t\t\t"<< stpPX->ID << endl;
    cout << "   Name:\t\t"<< stpPX->name<< endl;
    cout << "   Address:\t\t"<< stpPX->address << endl;
    cout << "   City:\t\t"<< stpPX->city<< endl;
    cout << "   State:\t\t"<< stpPX->state<< endl;
    cout << "   Zip:\t\t\t"<< stpPX->zip << endl;
    cout << "   Planet:\t\t"<< (*stpPX).planet << endl;

     system("pause");
     return 0;
}
