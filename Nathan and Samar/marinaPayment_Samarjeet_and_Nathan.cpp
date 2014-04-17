/*******************************************
*  Marina Payment Program
*  Authors: Nathan Vasquez 
*           Samarjeet Rai
*******************************************/

#include <cstdlib>
#include <iostream>

using namespace std;

//****************************Payment class
class Payment
{
      private:
              double subTotal;
              double grandTotal;
              double tax;
      public:
             //constructor
             //Payment();
             
             //calculations
             double calcTax(double x);
             double calcGrand(double x, double y);
             double x, y, z;
             
             //setters
             void setSubTotal(double x)  {subTotal = x;}
             void setTax(double y)            {tax = y;}
             void setGrandTotal(double z)     {grandTotal = z;}
             
             //getters
             double getSubTotal()        {return subTotal;}
             double getTax()             {return tax;}
             double getGrandTotal()      {return grandTotal;}
             
             void displayPayment();
};

//calculate tax
double Payment :: calcTax(double x)
{
    double taxTotal;
    taxTotal = x * .0925;
    return taxTotal;
}
//calculate grand total
double Payment :: calcGrand(double x, double y)
{
    double grand;
    grand = x + y;
    return grand;
}

//**************************************Credit Card Class
class Credit_Card : public Payment
{
      private:
              long cardNum;
              int expireDate;
              char billingAddress[100];
      public:
             //constructor
             //Credit_Card();
             
             int num, expdate;
             
             //setters
             void setCardNum()         {cardNum = num;}
             void setExpireDate()      {expireDate = expdate;}
             
             //getters
             long getCardNum()         {return cardNum;}
             int getExpireDate()       {return expireDate;}

             //member functions
             char enterBillingAddress();
             void show();
};
//read in the billing address
char Credit_Card :: enterBillingAddress()
{           
    int count = 0;
    char billingAddress[100];
    cin.getline(billingAddress, 100);

    while (billingAddress[count] != '\0')
    {
          cout << billingAddress[count];
          count++;
    }
    
    return billingAddress[100];
}             

//Credit Card show function
void Credit_Card :: show()
{
       cout << "card number  :   "<<getCardNum()<<"\n";
       cout << "Expiration date:  "<<getExpireDate()<<"\n";
       cout << "Billing Address: "<<enterBillingAddress()<<"\n";
       

}
             
//**********************************************Check Class
class Check : public Payment
{
      private:
              long acctNum;
              int  rtNum;
              int  chNum;
      public:
             //Constructor
             Check();
             long aNum;
             int rNum, cNum;
             //setters
             void setAcctNum()          {acctNum = aNum;}
             void setRtNum()            {rtNum = rNum;}
             void setChNum()            {chNum = cNum;}
             
             //getters
             long getAcctNum()          {return acctNum;}
             int  getRtNum()            {return rtNum;}
             int  getChNum()            {return chNum;}
             
             //member functions
             void show();

};

//Check display function
void Check :: show()
{
               cout << "Acount number :  "<<getAcctNum()<<"\n";
               cout << "Routing number : "<<getRtNum()<<"\n";
               cout << "Check number :   "<<getChNum()<<"\n";
}

//************************************************Cash Class
class Cash : public Payment
{
      private:
              float amtRec; //amount received
              float change; //the change
      public:
             //Constructor
             Cash();
             float aRec;
             //setters
             void setAmtRec()     {amtRec = aRec;}
             
             //getters
             float getAmtRec()    {return amtRec;}
             
             //member functions
             float calcChange(int aRec, int z);
             void show();
      
};
//calculate the change
float Cash :: calcChange(int aRec, int z)
{
     float changeTotal;
     changeTotal = aRec - z;
     return changeTotal;
}

//Cash display function
void Cash :: show()
{
     cout << "Amount recieved :"<<getAmtRec()<<"\n";
 //    cout << "change :         "<<calcChange(int aRec, int z)<<"\n";
}

// display
void Payment :: displayPayment()
{
     
     cout << "*****Payment Information*****\n";
     cout << "Cost:      "<< getSubTotal()<<"\n";
     cout << "Tax :      "<< getTax() <<"\n";
     cout << "Total :    "<< getGrandTotal() <<"\n";
}
//*********************************************//
//~~~~~~~~main function~~~~~~~~~~+++++ 8:::::::D
//********************************************//
int main()
{
        Payment p1;
        p1.setSubTotal(150);
		p1.setTax(p1.calcTax(p1.getSubTotal()));
		p1.setGrandTotal(p1.calcGrand(p1.getSubTotal(),p1.getTax()));
        
        p1.displayPayment();
		/*Credit_Card b1;
        b1.setSubTotal(234);
        cout << "b1 set tax" << b1.setTax(345);
        b1.setTax(b1.calcTax(234, y));
        b1.setGrandTotal(b1.calcGrand(234, y));
        b1.setCardNum(1234567812345678);
        b1.setExpireDate(0717);
        b1.enterBillingAddress();
        b1.display();
        b1.show();

        Check b1;
        b1.setSubTotal(234);
        b1.setTax(calcTax(int x));
        b1.setGrandTotal(calcGrand(int x , int y));
        b1.setAcctNum(12345678912345);
        b1.setRtNum(450450450);
        b1.setChNum(120120310);
        b1.display();
        b1.show();

        Cash b1;
        b1.setSubTotal(234);
        b1.setTax(calcTax(int x));
        b1.setGrandTotal(calcGrand(int x , int y));
        b1.setAmtRec(300);
        b1.display();
        b1.show();
    }*/


/*  
    Payment marie;
    
    marie.setSubTotal(234);
    switch(t)
    {
             case credit :     marie.setCardNum();
                               marie.setExpireDate();
                               break;
             
             case check:       marie.setAcctNum();
                               marie.setRtNum();
                               marie.setChNum();
                               break;
                               
             case cash:        marie.setAmtRec();
                               break;
    }
*/

/*
    int count = 0;
    char billingAddress[100];
    cin.getline(billingAddress, 100);
    while (billingAddress[count] != '\0')
    {
          cout << billingAddress[count];
          count++;
    }
*/
    system("PAUSE");
    return EXIT_SUCCESS;
}
