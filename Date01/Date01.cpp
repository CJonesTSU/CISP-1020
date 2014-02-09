/**************************************************
* 
*      program name:       Date01 
*      Author:             Chris Jones 
*      date due:           2014-02-10 
*      remarks:            Intial iteratioon of the Date Class 
*                          Only contains month, day and year
*                          along with a boolean function that
*                          tests the year for leap year status    
*
***************************************************/

/******************************************
*     library includes 
******************************************/
#include <iostream>             // needed for I/O
#include <cstdlib>              // needed for system call

/******************************************
*     pre-processor
******************************************/
using namespace std;

/****************************************
*         Class definitions
****************************************/
class Date
{
    private:
        int year;       // Contains the year
        int month;      // Contains the month
        int day;        // Contains the day
 
    public:
        // setters
        void setYear(int); 
        void setMonth(int);
        void setDay(int);

        //gettters
        int getYear() const;
        int getMonth() const; 
        int getDay() const; 
 
        bool isLeapYear() const; 


};

/****************************************
*         Member functions
****************************************/
void Date::setYear(int y)
{
    year = y;
}

void Date::setMonth(int m)
{

/****************************************
*          Function prototypes
****************************************/
void testDate01();

/*****************************************
*   main() - the function that executes
*****************************************/
int main()
{
    /*******************************
    *     local variables
    ******************************/
    testDate01();     
   
    system("PAUSE");               // causes the program to pause
	return 0;
}  // end main

void testDate01()
{
    int testDate = new Date()i;
}     
     
    











 

