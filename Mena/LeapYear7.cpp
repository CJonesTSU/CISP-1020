/**************************************************
* 
*      program name:       Leap year using constructors and destructor
*      Author:             Mena Sergeyous
*      date due:            2/12/2014
*      remarks:           convert  a year to leap year by using constructors and destructor in class public
*                          
*
***************************************************/

/******************************************
*     library includes 
******************************************/
#include <iostream>                // needed for I/O
#include <cstdlib>                // needed for system pause
#include <ctime>                 // need for time 
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
        int* month;    // holds  month
        int* day;     // hold day
        int* year;   //  hold year
	
	

    public:
       	//copy constructor
		Date(const Date& d);
	   
	    // constructors
        Date(int month, int day ,int year);
		Date(int doy, int year);
		Date();
		~Date();
		// overload operator
		
		//Date operator>(const Date& d1, const Date& d2);
		//Date operator>(Date);
		bool operator>(const Date& d2);
		//Date operator<(Date);
	//	Date operator=(Date);
		// setters
        void setMonth(int x)     {*month = x;}
        void setDay(int x)       {*day = x;}
        void setYear(int x)      {*year = x;}

        // getters
        int  getMonth()const     {return *month;}
        int  getDay()const       {return *day;}       
        int  getYear()const      {return *year;}    
		
		
		
		bool calcLeapYear(); 
		
		void display();   
	
	
      	double getmonth() const ;                 
        
};

/****************************************
*         member functions
****************************************/
// constructor
//this is the default constructor
Date::Date()
{
      month = new int;  // it hold the new int month	
      day= new int;    //  it hold the  new int day
	  year= new int;  // it hold the new int year
	  
	  struct tm *ptr;     
      time_t lt;
      lt = time('\0');
      ptr = localtime (&lt);
      
      setMonth(ptr->tm_mon+1);
      setDay(ptr->tm_mday);
      setYear(ptr->tm_year+1900);
}//end default constructor



// constructor uses Day-Of-Year
Date::Date(int doy, int year)
{              
    int julianMonth[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
    int x;
    
	  
	setYear(year);
    
    for(x=1; x<13; x++)
    {
        // increment by 1 if a leap year and Feb ~ Dec
        if(calcLeapYear() && x>1)
        {
            julianMonth[x]++;
        }
        
        if(doy <= julianMonth[x])
        {
            setMonth(x);
            setDay(doy - julianMonth[x-1]);
            break;
        }
    } 
}   


// constructor
Date :: Date(int m, int d ,int y)
{
    month=new int;
    setMonth(m);
    day= new int;
	setDay(d);
    year=new int;
	setYear(y);
}
//destructor
Date :: ~Date()
{
	cout << "in destructor\n"; 
    delete month;
    delete day;
    delete year;
	
}
// copy Constructor
Date::Date(const Date &d)
{
	cout << " in copy constructor";
	setMonth(d.getMonth());
	setYear(d.getYear());
	setDay(d.getDay());

}


//Date  Date :: operator>(const Date& d1, const Date& d2)
bool   Date:: operator>(const Date& d2)
//Date  Date :: operator>( Date d2)

{
	bool tf ;
 if (getYear() > d2.getYear())
	{

	tf=true;


	}
 else if (getYear()< d2.getYear())
	{
		tf=false;
		
		
		
	}

else if (getMonth() > d2.getMonth())

	{
		
		tf =true;
	}
else if (getMonth() < d2.getMonth())

	{
		
		tf =false;	
	}


else if (getDay() >d2.getDay())
	{
		
		tf =true;
	}
else 

	{
		tf= false;
	}
	return (tf);
}
 
/*Date Date ::operator<(Date d2)
{
	bool tf ;
 if (getYear() < d2.getYear())
	{

	tf=true;

	}
 else if (getYear()> d2.getYear())
	{
		tf=true;
			
	}

else if (getMonth() < d2.getMonth())

	{
		
		tf =true;
	}
else if (getMonth() > d2.getMonth())

	{
		
		tf =true;	
	}


else if (getDay() <d2.getDay())
	{
		
		tf =true;
	}
else 

	{
		tf= false;
	}
	//return (tf);
}
 
Date Date:: operator=(Date d2)
{
 if (getYear() =d2.getYear())

	{
		tf= true;
	}

  
else if(getMonth()= d2.getMonth))

	{
		tf= true;
	}

else if(getDay()= d2.Day())

	{
		tf= true;
	}
else
  {
  
	
	tf= false;
}  

}*/
bool Date :: calcLeapYear()


{
   bool isLeapYear;
   
   if(getYear() % 400 == 0 ) 
   {
       isLeapYear = true;
   }
   else if( getYear() % 100 == 0) 
   { 
  		isLeapYear= false;
   } 
  
  else if ( getYear() %4==0) 
   {
 	isLeapYear=true;
   }
else 
   { 
	isLeapYear=false;

   }
     return isLeapYear;
} 
   

void Date :: display()
{ 
    cout<< "    "<<endl;
    cout<< " month is   " << getMonth()  << endl;
    cout<< " day is     " << getDay()    << endl;
    cout<< " year is    " << getYear()   << endl; 	
    if(calcLeapYear()== true )
	cout<< getYear() << " is leap year" <<endl;

	else
	cout<< getYear() << " year is not a leap year" <<endl;
}


/****************************************
*          function prototypes
****************************************/
void testing ();
void testDate05();
void testDate06(); 
void testDate07();
/*****************************************
*   main() - the function that executes
*****************************************/
int main()
{
//  display 
	/*Date d1;
	d1.display();
	Date d2(7,1,1992);
	d2.display();*/
	//testDate06();
	testDate07();
	//testDate05();
/***************************
    Date d1;   // hold d1 
    int mMonth; // hold month
    int dDay;  	// hold day
    int yYear;  // hold year
testDa
// outputs and inputs date from the user

cout << "Enter a month\n";
cin>> mMonth;
cout << "Enter a day\n";
cin>> dDay;
cout << "Enter a year\n";
cin>> yYear;

// inputs date in the setters
d1.setMonth(mMonth);
d1.setDay(dDay);
d1.setYear(yYear);
  
  // call the function
  d1.display();
***************/
   system("pause");
	return 0;
}  // end main

void testing ()
 {

  cout << "testing destructors" << endl;  
   Date  (1,1,2000)  ;                   
 
 
 }
 
 
 // testing function
void testDate05()  
{
     Date d01(1, 2000);
     d01.display();
     Date d02(1, 2001);
     d02.display();
     Date d03(59, 2000);
     d03.display();
     Date d04(59, 2001);
     d04.display();    
     Date d05(60, 2000);
     d05.display();
     Date d06(60, 2001);
     d06.display();     
     Date d07(61, 2000);
     d07.display();
     Date d08(61, 2001);
     d08.display();
     Date d09(366, 2000);
     d09.display();
     Date d10(365, 2001);
     d10.display();    
} 

// testing function2
void testDate06()
{
    
	 Date d01(1, 3, 2000);
     d01.display();
     Date d02(1,25 ,2001);
     d02.display();
     d02 = d01;  
     d02.display();
       	
}

void testDate07()
{
    bool testResult;
	Date d1(1,3,2000);
	Date d2(2,5,2001);
	if(d1>d2)
	{
	    cout << "date one is greater than date two\n"; 
	}
	else
	{
	    cout << "date one is not greater than date two\n";
	}
	
	
	
	
}





 

