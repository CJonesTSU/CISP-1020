/**************************************************
* 
*      program name:       classDate
*      Author:             Rachel Chapman
*      date due:           2-5-2014
*      remarks:            Create a class using getters and setters to 
							calculate leap year.    
*
***************************************************/

/******************************************
*     library includes 
******************************************/
#include <iostream>            // needed for Cin and Cout
#include <stdlib.h>
#include <math.h>
using namespace std;

/******************************************
*     pre-processor
******************************************/
#define PI 3.14159
using namespace std;
/****************************************
*         Class definitions
****************************************/
class Date
{
    private:
        int month;
        int day;
        int year;
    public:
        // setters
        void setMonth(int x)     {month = x;}
        void setDay(int x)       {day = x;}
        void setYear(int x)      {year = x;}

        // getters
        int  getMonth()          {return month;}
        int  getDay()            {return day;}       
        int  getYear()           {return year;}        
        
		bool isLeapYear();
		                      
       	void display();
	
};
/****************************************
*         member functions
****************************************/
bool Date :: isLeapYear()
{
           	
	   {
	    if (getYear() %400 == 0)
		   	return true;
	   
	     else if (getYear()%100 == 0)
	 	  	return false;
	 	  	
	     else if (getYear()%4 == 0)
	 	 	return true;
	 
	     else 
	 	   	return false;

	 		return isLeapYear();
       }
     
     
	 
}
void Date :: display()
{
     cout << "\n";
     cout << "Month is   " << getMonth() << endl;
     cout << "Day is     " << getDay() << endl;
     cout << "Year is    " << getYear() << endl;
     cout << getYear() << " is a leap year." << endl;
	 cout << "\n";
}
/****************************************
*          function prototypes
****************************************/
bool isLeapYear();
void display();

/*****************************************
*   main() - the function that executes
*****************************************/
int main()
{
    /*******************************
    *     local variables
    ******************************/
    Date leapYear;
    
	leapYear.getMonth();
	leapYear.setMonth(03);
       
	leapYear.getDay();
	leapYear.setDay(25);
	
	leapYear.getYear();
	leapYear.setYear(2010);
   
    leapYear.isLeapYear();
    leapYear.display();
   // display();
    
      
   
    system("PAUSE");               // causes the program to pause
	return 0;
}  // end main

