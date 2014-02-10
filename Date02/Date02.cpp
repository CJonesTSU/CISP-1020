/**************************************************
* 
*      program name:       Date02 
*      Author:             Chris Jones 
*      date due:           2014-02-10 
*      remarks:            Second iteration of the Date Class 
*                          Adding a couple of constructors 
*                          
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
        //Constructors
        Date();
        Date(int,int,int);

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
Date::Date()
{
    setYear(1900);
    setMonth(1);
    setDay(1);
}

Date::Date(int month, int day, int year)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

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
    cout << endl;
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
void testDate01();
void testDate02();

/*****************************************
*   main() - the function that executes
*****************************************/
int main()
{
    /*******************************
    *     local variables
    ******************************/
    testDate01();     
    testDate02();
 
    system("PAUSE");               // causes the program to pause
	return 0;
}  // end main

void testDate01()
{
    Date testDate;      // Out testing date object 
    // Banner head 
    cout << endl << "******************************" << endl;
    cout << "***        testDate01      ***" << endl;
    cout << "******************************" << endl;
  

    // test constructor
    cout << "testing contructor" << endl;
    testDate.display();

    // test setters
    cout << endl << "Testing setters" << endl;
    testDate.setYear(2014);
    testDate.setMonth(02);
    testDate.setDay(10);
    testDate.display();

    // test getters
    cout << endl << "Testing getters" << endl;
    cout << "Testing getMonth(): " << testDate.getMonth() << endl;
    cout << "Testing getDay(): " << testDate.getDay() << endl;
    cout << "Testing getYear(): " << testDate.getYear() << endl;

    // test calcLeapYear
    cout << endl << "Testing calcLeapYear():" << endl;
    testDate.setYear(1900);
    testDate.display();
    testDate.setYear(2000);
    testDate.display();
    testDate.setYear(1999);
    testDate.display();
    testDate.setYear(1996);
    testDate.display();
}     
     
void testDate02()
{
    
    Date testDefaultCon;                // test date with default constructor
    Date testThreeIntCon(02,10,2014);   // test date with three int constructor

    cout << endl << "******************************" << endl;
    cout << "***        testDate02      ***" << endl;
    cout << "******************************" << endl;
    cout << "Testing Default Constructor" << endl;
    testDefaultCon.display();

    cout << endl << "Testing the three int constructor Date(month, day, year)" << endl;
    testThreeIntCon.display();
}    











 

