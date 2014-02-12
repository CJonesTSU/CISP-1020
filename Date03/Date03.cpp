/**************************************************
* 
*      program name:       Date03 
*      Author:             Chris Jones 
*      date due:           2014-02-12 
*      remarks:            Third iteration of the Date Class 
*                          added day of year, day of week and
*                          month name funcitons
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
        int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
                        // holds the number of days in each month
        char dayOfWeek[7][10] = {"Sunday",
                                "Monday",
                                "Tuesday",
                                "Wednesday",
                                "Thursday",
                                "Friday",
                                "Saturday"};
 
    public:
        //Constructors
        Date();
        Date(int,int,int);

        // setters
        void setYear(int x)        {year = x;} 
        void setMonth(int x)       {month =x;}
        void setDay(int x)         {day = x;}

        //gettters
        int getYear()              {return year;}
        int getMonth()             {return month;}
        int getDay()               {return day;}
 
        bool calcLeapYear(); 
        void display();
        int calcDayOfYear();
        char* getDayOfWeek();
        string getMonthName();
};

/****************************************
*         Member functions
****************************************/
// Constructors
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

// Actual member functions
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
    cout << "day of year\t" << calcDayOfYear() << endl;
    if (calcLeapYear())
    {
        cout << getYear() << " is a leap year." << endl;
    }
    else
    {
        cout << getYear() << " is not a leap year." << endl;
    }
}

int Date::calcDayOfYear()
{
    int totalDays = 0;

    totalDays += getDay();      // add the partial month
    
    // add the days in months that have already occurred
    for(int x=0; x<getMonth()-1; x++)
    {
        totalDays += daysInMonth[x];
    }
    
    // Add one day if leap year and today is Feb 29th or later.
    if(calcLeapYear()==true)
    {
        if((getMonth() > 2) || (getMonth() == 2 && getDay() == 29))
            {
                totalDays++;
            }                
    }
    return totalDays;
}
/****************************************
*          Function prototypes
****************************************/
void testDate01();
void testDate02();
void testDate03();
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
    testDate03();
 
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
    testDate.setMonth(2);
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
    Date testThreeIntCon(2,10,2014);   // test date with three int constructor

    cout << endl << "******************************" << endl;
    cout << "***        testDate02      ***" << endl;
    cout << "******************************" << endl;
    cout << "Testing Default Constructor" << endl;
    testDefaultCon.display();

    cout << endl << "Testing the three int constructor Date(month, day, year)" << endl;
    testThreeIntCon.display();
}    


void testDate03()
{
    Date testDate;      // Out testing date object 

    // Banner head 
    cout << endl << "******************************" << endl;
    cout << "***        testDate03      ***" << endl;
    cout << "******************************" << endl;

    // set 1/1/1900 basic test
    testDate.setYear(1900);
    testDate.setMonth(1);
    testDate.setDay(1);
    testDate.display();
}
  










 

