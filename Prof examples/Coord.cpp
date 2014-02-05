/**************************************************
* 
*      program name:       Skeleton
*      Author:             Captain Kirk
*      date due:            
*      remarks:            Skeleton C code 
*                          Start with this format    
*
***************************************************/

/******************************************
*     library includes 
******************************************/
#include <iostream>                // needed for I/O

/******************************************
*     pre-processor
******************************************/
#define PI 3.14159
using namespace std;
/****************************************
*         Class definitions
****************************************/
class Coord
{
    private:
        int xCoord;
        int yCoord;
        int zCoord;
    public:
        // setters
        void setXCoord(int x)     {xCoord = x;}
        void setYCoord(int x)     {yCoord = x;}
        void setZCoord(int x)     {zCoord = x;}

        // getters
        int  getXCoord(int x)     {return xCoord;}
        int  getYCoord(int x)     {return yCoord;}       
        int  getZCoord(int x)     {return zCoord;}        
                        
        void display();     
};

/****************************************
*         member functions
****************************************/
void Coord :: display()
{
     cout << "\n";
     cout << "*** co-ordinate object ***\n";
     cout << "xCoord    " << xCoord << endl;
     cout << "yCoord    " << yCoord << endl;
     cout << "zCoord    " << zCoord << endl;
     cout << "\n";     
}

/****************************************
*          function prototypes
****************************************/
void display();

/*****************************************
*   main() - the function that executes
*****************************************/
int main()
{
    /*******************************
    *     local variables
    ******************************/
    Coord c1;   
    
   
    //display();    
    //c1.xCoord = 44;   error - cannot access a provate data item
    c1.display();
    c1.setXCoord(44);
    c1.display();
   
    system("PAUSE");               // causes the program to pause
	return 0;
}  // end main
void display()
{
     cout << "in regular function display\n\n";
}

     
     
    











 

