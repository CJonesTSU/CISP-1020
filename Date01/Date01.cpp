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
#define VERBOSE true

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
        int getYear();
        int getMonth(); 
        int getDay(); 
 
        bool calcLeapYear(); 
        void display();
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
    month = m;
}

void Date::setDay(int d)
{
    day = d;
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

bool Date::calcLeapYear() 
{
    bool isLeapYear = false;    //holds our bool for leap year
    if ((year % 400) == 0)
    {
        isLeapYear = true;
    }
    if (((year % 4) == 0) && ((year % 100) != 0))
    {
        isLeapYear = true;
    }
    return isLeapYear;

}
void Date::display()
{
    cout << endl << endl;
    cout << "Month is\t" << getMonth() << endl;
    cout << "day is\t\t" << getDay() << endl;
    cout << "year is \t" << getYear() << endl;
    if (calcLeapYear())
    {
        cout << getYear() << " is a leap year." << endl;
    }
    else
    {
        cout << getYear() << " is not a leap year." << endl;
    }
}

/****************************************
*          Function prototypes
****************************************/
void testDate01(bool verbosity);

/*****************************************
*   main() - the function that executes
*****************************************/
int main()
{
    /*******************************
    *     local variables
    ******************************/
    testDate01(VERBOSE);     
   
    system("PAUSE");               // causes the program to pause
	return 0;
}  // end main

void testDate01(bool verbosity)
{
    // test constructor
    cout << "testing contructor";
    Date testDate;
    testDate.display();

    // test setters
    cout << endl << endl << "Testing setters";
    testDate.setYear(2014);
    testDate.setMonth(02);
    testDate.setDay(10);
    testDate.display();

    // test getters
    cout << endl << endl << "Testing getters" << endl;
    cout << "Testing getMonth(): " << testDate.getMonth() << endl;
    cout << "Testing getDay(): " << testDate.getDay() << endl;
    cout << "Testing getYear(): " << testDate.getYear() << endl;

    // test calcLeapYear
    cout << endl << endl << "Testing calcLeapYear():" << endl;
    testDate.setYear(1900);
    testDate.display();
    testDate.setYear(2000);
    testDate.display();
    testDate.setYear(1999);
    testDate.display();
    testDate.setYear(1996);
    testDate.display();

}     
     
    











 

