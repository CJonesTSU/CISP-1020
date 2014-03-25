/**************************************************i
* 
*      program name:       Date07
*      Author:             Chris Jones 
*      date due:           2014-03-24 
*      remarks:            Seventh iteration of the Date Class 
*                          overriding "<",">" and "=" for the 
*                          date class
*
***************************************************/

/******************************************
*     library includes 
******************************************/
#include <iostream>             // needed for I/O
#include <cstdlib>              // needed for system call
#include <string>               // string functions
#include <string.h>             // c string functions
#include <ctime>                // time functions

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
        int *year;       // Contains the year
        int *month;      // Contains the month
        int *day;        // Contains the day
        int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
                         // holds the number of days in each month
        char* daysOfWeek[7] = { "Sunday",
                                "Monday",
                                "Tuesday",
                                "Wednesday",
                                "Thursday",
                                "Friday",
                                "Saturday"};
        string monthNames[12]={ "January",
                                "February",
                                "March",
                                "April",
                                "May",
                                "June",
                                "July",
                                "August",
                                "September",
                                "October",
                                "November",
                                "December"};
 
    public:
        //Constructors/Destructor
        Date();                 // returns current systme date
        Date(int,int,int);      // pass in year month and date
        Date(int, int);         // pass in day of year and year
        Date(const Date &d);    // copy constructor

        // Destructor
        ~Date();
        
        // overloaded operators
		bool operator>(const Date& rhs);
		bool operator<(const Date& rhs);
		bool operator==(const Date& rhs);

        // setters
        void setYear(int x)        {*year = x;} 
        void setMonth(int x)       {*month =x;}
        void setDay(int x)         {*day = x;}

        //gettters
        int getYear() const            {return *year;}
        int getMonth() const            {return *month;}
        int getDay() const              {return *day;}
 
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
    time_t t = time(0);
    struct tm * now = localtime(&t);
    
    year = new int; 
    month = new int;
    day = new int;
    
    setYear(now->tm_year + 1900);
    setMonth(now->tm_mon +1);
    setDay(now->tm_mday);
}

Date::Date(int m, int d, int y)
{
    year = new int;
    month = new int;
    day = new int;
 
    setYear(y);
    setMonth(m);
    setDay(d);
}

Date::Date(int doy, int yr)
{
    year = new int;
    month = new int;
    day = new int;
    int tmpDays;
 
    setYear(yr);
    for(int x=0;x<12;x++)
    {
        tmpDays = daysInMonth[x];
        if ((x==1) && calcLeapYear()==true)
        {
            tmpDays++;
        }
        if((doy - tmpDays) > 0 )
        {   
            doy = doy - tmpDays;
        }
        else
        {
            setMonth(x+1);
            break;
        }
        
    }
    setDay(doy);

}
Date::Date(const Date &originalDate)
{
    year = new int;
    month = new int;
    day = new int;

    setYear(originalDate.getYear()); 
    setMonth(originalDate.getMonth());
    setDay(originalDate.getDay());
}

Date::~Date()
{
delete year;
delete month;
delete day;
}
// Overloaded operators
bool Date :: operator>(const Date& rhs)
{
    bool isTrue = false;
    if(getYear() > rhs.getYear())
    {
        isTrue = true;
    }
    else if(getYear() < rhs.getYear())
    {
        isTrue = false;
    } 
    else if(getMonth() > rhs.getMonth())
    {
        isTrue = true;
    }
    else if(getMonth() < rhs.getMonth())
    {
        isTrue = false;
    } 
    else if(getDay() > rhs.getDay())
    {
        isTrue = true;
    }
    else  // this catches both less than days and equal dates
    {
        isTrue = false;
    } 
}

bool Date :: operator<(const Date& rhs)
{
}
bool Date :: operator==(const Date& rhs)
{
}
// Actual member functions
bool Date::calcLeapYear() 
{
    bool isLeapYear = false;    //holds our bool for leap year
    if ((getYear() % 400) == 0)
    {
        isLeapYear = true;
    }
    if (((getYear() % 4) == 0) && ((getYear() % 100) != 0))
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
    cout << "Month\t\t" << getMonthName() << endl;
    cout << "Day-of-week\t" << getDayOfWeek() << endl; 
}

int Date::calcDayOfYear()
{
    int totalDays = 0;

    totalDays += getDay();      // add the partial month (handles 02/29 too)
    
    // add the days in months that have already occurred
    for(int x=0; x<getMonth()-1; x++)
    {
        totalDays += daysInMonth[x];
    }
    
    // Add one day if leap year and today is Feb 29th or later.
    if(calcLeapYear()==true)
    {
        if((getMonth() > 2))
            {
                totalDays++;
            }                
    }
    return totalDays;
}

char* Date::getDayOfWeek()
{
    // only works for dates after 1/1/1900
    int totalDays = 0;
    Date tmpDate;
    char* tmpDOfW; 
    totalDays = calcDayOfYear();

    tmpDate.setMonth(12);
    tmpDate.setDay(31);
    
    if (getYear() >= 1900)
    {
        for(int x=1900;x<getYear();x++)
        {
            // loop through years since 1900 adding total days
            tmpDate.setYear(x);
            totalDays += tmpDate.calcDayOfYear();
        }
        // totalDays should now have days since 1/1/1900
        // calc that value mod 7 and grab appropriate string
        tmpDOfW = &daysOfWeek[totalDays%7][0];
    }
    return tmpDOfW;
}

string Date::getMonthName()
{
    return monthNames[getMonth()-1];
}

/****************************************
*          Function prototypes
****************************************/
void testDate01();
void testDate02();
void testDate03();
void testDate05();
void testDate06();
void sendDateToFunction(Date theDate);
/*****************************************
*   main() - the function that executes
*****************************************/
int main()
{
    /*******************************
    *     local variables
    ******************************/
    //testDate01();     
    //testDate02();
    //testDate03();
    //testDate05();
    //testDate06();
    testDate07();
 
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

    
    cout << "**** testing dayOfYear ****" << endl;
    // set 1/1/1900 basic test
    testDate.setYear(1900);
    testDate.setMonth(1);
    testDate.setDay(1);
    testDate.display();

    // set to 12/31/1900 (should give 365)
    testDate.setYear(1900);
    testDate.setMonth(12);
    testDate.setDay(31);
    testDate.display();

    // set to 02/29/2000 (should give 60)
    testDate.setYear(2000); 
    testDate.setMonth(2);
    testDate.setDay(29);
    testDate.display();

    // set to 12/31/2000 (should give 366)
    testDate.setYear(2000); 
    testDate.setMonth(12);
    testDate.setDay(31);
    testDate.display();


    cout << "**** testing day of week ****" << endl;
    // set date to 01/01/1900 (day of week should be Sunday)
    testDate.setYear(1900);
    testDate.setMonth(1);
    testDate.setDay(1);
    testDate.display();

    // set date to 02/12/2014 (day of week should be Wednesday)
    testDate.setYear(2014);
    testDate.setMonth(2);
    testDate.setDay(12);
    testDate.display();

    cout << "**** testing month names ****" << endl;
    // should give us January
    testDate.setMonth(1);
    testDate.display();

    // Should be December
    testDate.setMonth(12);
    testDate.display();

}

void testDate05()
{
    
    Date testDefaultCon;                // test date with default constructor
    Date testDOYYearCon(1,1900);     // test date with DOY/Yearconstructor
    Date testDOYYearCon2(31,1900);     // test date with DOY/Yearconstructor
    Date testDOYYearCon3(32,1900);     // test date with DOY/Yearconstructor
    Date testDOYYearCon4(366,2000);     // test date with DOY/Yearconstructor




    cout << endl << "******************************" << endl;
    cout << "***        testDate05      ***" << endl;
    cout << "******************************" << endl;
    cout << "Testing Default Constructor" << endl;
    testDefaultCon.display();

    cout << endl << "Testing the DOY/Year constructor" << endl;
    testDOYYearCon.display();           // should give 01/01/1900
    testDOYYearCon2.display();          // should give 01/31/1900
    testDOYYearCon3.display();          // should give 02/01/1900
    testDOYYearCon4.display();          // should give 12/31/2000
}
void testDate06()
{
    cout << endl << "******************************" << endl;
    cout << "***        testDate06      ***" << endl;
    cout << "******************************" << endl;
    cout << "Testing Copy Constructor" << endl;
    cout << "Assigning existing date as value for new date" << endl;
    Date date1(1,2,1944);                  // create a date with a date in it
    cout << "First date is:"<< endl;
    date1.display();
    Date date2 = date1;                            // no values should be today's info
    cout << "New date is:"<< endl;
    date2.display();
    cout << endl << endl << "Passing Date one to a function" << endl;
    cout << "values before are:" << endl;
    date1.display();
    sendDateToFunction(d1);
    cout << "Back from function, original date's values are: " << endl;
    date1.display();
    

}
void testDate07()
{
    Date testDate(7,4,1976);     // The date we will test against
    Date equalDate(7,4,1976);    // An equivalent date
    Date dayBefore(7,3,1976);    // The day before the test date
    Date dayAfter(7,5,1976);     // The day after the test date
    Date monthBefore(6,4,1976);    // The day before the test date
    Date monthAfter(8,4,1976);     // The day after the test date
    Date yearBefore(7,4,1975);    // The day before the test date
    Date yearAfter(7,4,1977);     // The day after the test date
    
    cout << endl << "******************************" << endl;
    cout << "***        testDate07      ***" << endl;
    cout << "******************************" << endl;
    cout << "Testing overridden >" << endl;   
}

void sendDateToFunction(Date theDate)
{
    cout << "in function date is: " << endl;
    theDate.display();
    cout << "changing date to 07/04/1976" << endl;
    theDate.setYear(1976);
    theDate.setMonth(7);
    theDate.setDay(4);
    cout << "date is now" << endl;
    theDate.display();
}










 

