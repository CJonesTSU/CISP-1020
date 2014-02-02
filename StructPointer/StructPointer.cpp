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
    /*1.	declare a StarTrekPersonel struct named stpSample
     *2.	create (instantiate) the variable */

    /*********************************
    *    local variables
    *********************************/
    starTrekPersonel* stpPX = new  starTrekPersonel;
    
    // Get our input
    cout << "Welcome to the Star Fleet Entity Identification Portal" << endl;
    cout << endl;
    cout << "Please enter the ID of the entity: ";
    getline(cin, stpPX->ID);         
 


    // Generate out output
    cout << endl << endl;
    cout << "****  \"The Entity Entered\"  ****" << endl;
    cout << "ID\t\t" cout stpPX->ID << endl;
 
    stpPX->planet = "Mars";
    cout << stpPX->planet << endl;
     
     (*stpPX).name = "James T. Kirk";
     cout << (*stpPX).name << endl;
     
     cout << stpPX  << endl;
     
     cout << &stpPX->zip << endl;    
     
     //starTrekPersonel stp;
     //cout << stp.name << endl;
 /************************    
    //3.	using cin and cout to load in the values to the ID
     cout << "\n Enter the ID : ";
     //cin.ignore();     //to skip the remaining '\n' character 
     //getline (cin, stpSample.ID); 
     cin >> stpSample.ID;
     
    //3.	using cin and cout to load in the values to the name
     cout << "Enter the name : ";
     //rgcin.ignore();     //to skip the remaining '\n' character 
     cin.ignore();
     getline(cin, stpSample.name); 
     
    //3.	using cin and cout to load in the values to the address
     cout << "Enter the address : "; 
     getline(cin, stpSample.address);
    
   //3.	using cin and cout to load in the values to the city  
     cout << "Enter the city : ";
     cin >> stpSample.city; 
     //cin.ignore();     //to skip the remaining '\n' character 
     //getline(cin, stpSample.city); 
     
    //3.	using cin and cout to load in the values to the state
     cout << "Enter the state : ";
     cin >> stpSample.state; 
     
    //3.	using cin and cout to load in the values to the zip
      cout << "Enter the zip : ";
      cin >> stpSample.zip; 
           
    //3.	using cin and cout to load in the values to the planet
      cout << "Enter the planet : ";
      cin >> stpSample.planet;      

      
    //4.	using cout output your stpSample 
     cout << "\n \n *** *  \"the strSample field\" **** " << endl;
     cout << "     ID      " << stpSample.ID << endl;
     cout << "     name    " << stpSample.name << endl;
     cout << "     address " << stpSample.address << endl;
     cout << "     city    " << stpSample.city << endl;
     cout << "     state   " << stpSample.state << endl;
     cout << "     zipp    " << stpSample.zip << endl;
     cout << "     planet  " << stpSample.planet << endl;
 ************************/         
     system("pause");
     return 0;
}
