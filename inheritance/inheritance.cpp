/**************************************************i
*
*      program name:       Date07
*      Author:             Chris Jones
*      date due:           2014-04-07
*      remarks:            Basic Multiple inheritance
*                          Class Hybrid inherets from both
*                          Class gasCar and electricCar
*                          Also added class motorcycle
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
class RoadVehicle 
{
    int wheels;
    int passengers;

    public:
        //constructors
        RoadVehicle()
        {
            wheels = 0;     // default constructor, unknown wheelc ount
            passengers=0;   // unknown passenger capacity
        }
        RoadVehicle(int w, int p)
        {
            wheels = w;
            passengers = p;
        }
        ~RoadVehicle()
        {
            //nothing to do really
        }
    void set_wheels(int num) { wheels = num; }
    int  get_wheels()        { return wheels; }
    void set_pass(int num)   { passengers = num; }
    int  get_pass()          { return passengers; }
};

class Truck : public RoadVehicle 
{
    private: 
    int cargo;

    public:
    // constructors
    Truck()
    {
        cargo = 0;      // unknown cargo capacity
    }
    Truck(int c)
    {
        cargo = c;      // not really a useful constructor no wheels
    }
    Truck(int c, int wheels, int passengers) : RoadVehicle(wheels, passengers)
    {
        cargo = c;
        cout << endl << "in good truck constructor" << endl;
    }
    ~Truck()
    {
        //nothing to do here
    }
    void set_cargo(int size) { cargo = size; }
    int get_cargo()          { return cargo; }
    void show();
};

enum automobile_type { car, van, wagon, unknown_auto};


// Define an automoble.
class Automobile : public RoadVehicle 
{
    private: 
        enum automobile_type car_type;

    public:
        // constructors
        Automobile()
        {
            set_type(unknown_auto);
        }
        Automobile(automobile_type type)
        {
            set_type(type);
        }
        Automobile(automobile_type type, int w, int p) : RoadVehicle(w, p)
        {
            set_type(type);
            //cout << endl << "in full automobile constructor" << endl;
        }
        ~Automobile()
        {
            //nothing to do
        }
        
        void set_type(automobile_type t) { car_type = t; }
        enum automobile_type get_type()  { return car_type; }
        void show();
};

class GasCar : public virtual Automobile
{
    private: 
        int volGasTank;     // Gallons in a tank full
        int mpg;            // Miles per gallon
    
    public:
        //constructors
        GasCar()
        {
            volGasTank = 0;
            mpg = 0;            
        }
        GasCar(int v, int m)
        {
            volGasTank = v;
            mpg = m;
        }
        GasCar(int v, int m, automobile_type t, int w, int p) : Automobile(t,w,p)
        {
            volGasTank = v;
            mpg = m;
        }
        ~GasCar()
        {
            // nothing to do
        }
        // Getters
        int get_Vol()       { return volGasTank; }
        int get_mpg()       { return mpg; }
        
        // setters
        void set_Vol(int v)  { volGasTank = v; }
        void set_mpg(int m)  { mpg = m; }

        // member functions
        void show();


};

class ElectricCar : public virtual Automobile
{
    private: 
        int batteryChargeTime;      // time to fully charge the battery
        int milesBatteryCharge;     // miles one can drive on a full charge
    
    public:
        //constructors
        ElectricCar()
        {
            batteryChargeTime = 0;
            milesBatteryCharge = 0;            
        }
        ElectricCar(int ct, int mbc)
        {
            batteryChargeTime = ct;
            milesBatteryCharge = mbc;
        }
        ElectricCar(int ct, int mbc, automobile_type t, int w, int p): Automobile(t,w,p)
        {
            batteryChargeTime = ct;
            milesBatteryCharge = mbc;
        }
        ~ElectricCar()
        {
            // nothing to do
        }
        // Getters
        int get_batteryChargeTime()     { return batteryChargeTime; }
        int get_milesBatteryCharge()    { return milesBatteryCharge; }
        
        // setters
        void set_batteryChargeTime(int ct)      { batteryChargeTime = ct; }
        void set_milesBatteryCharge(int mbc)    { milesBatteryCharge = mbc; }

        // member functions
        void show();
};
class HybridCar : public GasCar, public ElectricCar
{
    public:
        //constructors
        HybridCar()
        {
        }
        HybridCar(int ct, int mpc, int v, int m, automobile_type t, int w, int p): GasCar(v, m, t, w, p), ElectricCar(ct, mpc, t, w, p)
        {
            cout << "in full hybrid constructor" << endl;
            cout << "type is: " << t;
            cout << "wheels is: " << w;
        }
        ~HybridCar()
        {
            // nothing to do
        }

        // member functions
        void show();
};



enum motorcycle_type {Harley, Honda, Indian, unknown_bike};

// Define a Motorcycle.
class Motorcycle : public RoadVehicle 
{
    enum motorcycle_type bike_type;

    public:
        // constructors
        Motorcycle()

        {
            set_type(unknown_bike);
        }
        Motorcycle(motorcycle_type type)
        {
            set_type(type);
        }
        Motorcycle(motorcycle_type type, int wheels, int passengers) : RoadVehicle(wheels, passengers)
        {
            set_type(type);
            //cout << endl << "in full motorcycle constructor" << endl;
        }
        ~Motorcycle()
        {
            //nothing to do
        }
        
        void set_type(motorcycle_type t) { bike_type = t; }
        enum motorcycle_type get_type()  { return bike_type; }
        void show();
};


void Truck::show()
{
    cout << "*** Truck ***" << endl;
     cout << "wheels: "     << get_wheels() << "\n";
     cout << "passengers: " << get_pass() << "\n";
     cout << "cargo capacity in cubic feet: " << cargo << "\n";
}

void Automobile::show()
{
     cout << "*** Automobile ***" << endl;
     cout << "wheels: "     << get_wheels() << "\n";
     cout << "passengers: " << get_pass() << "\n";
     cout << "type: ";
     switch(get_type()) 
     {
        case van: cout << "van\n";
                  break;
        case car: cout << "car\n";
                  break;
        case wagon: cout << "wagon\n";
                break;
        case unknown_auto: cout << "random 4 wheeled thing" << endl;
     }
}

void Motorcycle::show()
{
    cout << "*** Motorcycle ***" << endl;
     cout << "wheels: "     << get_wheels() << "\n";
     cout << "passengers: " << get_pass() << "\n";
     cout << "type: ";
     switch(get_type()) 
     {
        case Harley: cout << "Harley Davidson (rumble, rumble, roar)\n";
                break;
        case Honda: cout << "Honda Zip!\n";
                break;
        case Indian: cout << "Indian ZOOOM!\n";
                break;
        case unknown_bike: cout << "Random crotch rocket" << endl; 
     }
}

void GasCar::show()
{
    cout << "*** GasCar ***" << endl;
    cout << "wheels: "     << get_wheels() << "\n";
    cout << "passengers: " << get_pass() << "\n";
    cout << "tank volume: " << get_Vol() << endl;
    cout << "mpg: " << get_mpg() << endl;    
    cout << "type: ";
    switch(get_type()) 
    {
       case van: cout << "van\n";
                 break;
       case car: cout << "car\n";
                 break;
       case wagon: cout << "wagon\n";
                break;
        case unknown_auto: cout << "random 4 wheeled thing" << endl;
 


    }
}
void ElectricCar::show()
{
    cout << "*** ElectricCar ***" << endl;
    cout << "wheels: "     << get_wheels() << "\n";
    cout << "passengers: " << get_pass() << "\n";
    cout << "Battery Charege time: " << get_batteryChargeTime() << endl;
    cout << "Miles per Charge: " << get_milesBatteryCharge() << endl;    
    cout << "type: ";
    switch(get_type()) 
    {
       case van: cout << "van\n";
                 break;
       case car: cout << "car\n";
                 break;
       case wagon: cout << "wagon\n";
                 break;
        case unknown_auto: cout << "random 4 wheeled thing" << endl;
    }
}
void HybridCar::show()
{
    cout << "***** Hybrid Car *****" << endl;
    cout << "wheels: "     << get_wheels() << "\n";
    cout << "passengers: " << get_pass() << "\n";
    cout << "Tank Volume: " << get_Vol() << endl;
    cout << "mpg: " << get_mpg() << endl; 
    cout << "Battery Charge time: " << get_batteryChargeTime() << endl;
    cout << "Miles per Charge: " << get_milesBatteryCharge() << endl;    
    cout << "type: ";
    switch(get_type()) 
    {
       case van: cout << "van\n";
                 break;
       case car: cout << "car\n";
                 break;
       case wagon: cout << "wagon\n";
                 break;
        case unknown_auto: cout << "random 4 wheeled thing" << endl;
   }

}

/**********************************************************
*            Prototypes
**********************************************************/
void testTruck();
void testAuto();
void testBike();
void testGasCar();
void testElectricCar();
void testHybrid();

int main()
{
    testTruck();
    testAuto();
    testBike();
    testGasCar();
    testElectricCar();
    testHybrid();
    system("pause");
    return 0;
}
void testTruck()
{
    cout << "*******************************" << endl;
    cout << "*    testing truck class      *" << endl;
    cout << "*******************************" << endl;
    Truck t1, t2;
    t1.set_wheels(18);
    t1.set_pass(2);
    t1.set_cargo(3200);
    t2.set_wheels(6);
    t2.set_pass(3);
    t2.set_cargo(1200);
    t1.show();
    cout << "\n";
    t2.show();
    cout << endl;
    Truck t3(50000,100,1);  // Mammoth TRUCK!
    t3.show();
    cout << endl;
}
void testAuto()
{

    cout << "*******************************" << endl;
    cout << "*    testing auto class       *" << endl;
    cout << "*******************************" << endl;
    
    Automobile c;
    c.set_wheels(4);
    c.set_pass(6);
    c.set_type(van);
    cout << endl;
    c.show();
    Automobile c1(wagon,4, 7);
    cout << endl;
    c1.show();
    cout << endl;
}
void testBike()
{
    cout << "*******************************" << endl;
    cout << "*    testing bike class       *" << endl;
    cout << "*******************************" << endl;
    Motorcycle m;
    m.set_wheels(3);
    m.set_pass(1);
    m.set_type(Harley);
    m.show();
    Motorcycle m1(Honda,2, 1);
    m1.show();
    cout << endl;
}
void testGasCar()
{

    cout << "*******************************" << endl;
    cout << "*    testing GasCar class     *" << endl;
    cout << "*******************************" << endl;
    
    GasCar gc;
    gc.set_wheels(4);
    gc.set_pass(6);
    gc.set_type(van);
    gc.set_Vol(10);
    gc.set_mpg(23);
    cout << endl;
    gc.show();
    GasCar gc1(15,18,wagon,4, 7);
    cout << endl;
    gc1.show();
    cout << endl;
}
void testElectricCar()
{

    cout << "*******************************" << endl;
    cout << "*  testing ElectricCar class  *" << endl;
    cout << "*******************************" << endl;
    
    ElectricCar ec;
    ec.set_wheels(4);
    ec.set_pass(6);
    ec.set_type(van);
    ec.set_batteryChargeTime(7);
    ec.set_milesBatteryCharge(230);
    cout << endl;
    ec.show();
    ElectricCar ec1(6,130,wagon,4, 7);
    cout << endl;
    ec1.show();
    cout << endl;
}
void testHybrid()
{
    cout << "*******************************" << endl;
    cout << "*   testing hybridCar class   *" << endl;
    cout << "*******************************" << endl;
    
    HybridCar hc;
    hc.set_wheels(4);
    hc.set_pass(6);
    hc.set_type(van);
    hc.set_batteryChargeTime(7);
    hc.set_milesBatteryCharge(230);
    hc.set_Vol(5);
    hc.set_mpg(30);
    cout << endl;
    hc.show();
    cout << endl;
//  HybridCar(int ct, int mpc, int v, int m, automobile_type t, int w, int p): ElectricCar(ct, mpc), GasCar(v, m, t, w, p)
    cout << "in hybrid test van is: " << van  << endl;   
    HybridCar hc1(3, 230, 6, 32, van ,4, 7);
    cout << endl;
    hc1.show();
    cout << endl;
}

