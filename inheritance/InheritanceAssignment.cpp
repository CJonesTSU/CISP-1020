/**************************************************************
*
*     InheritanceDemo
*          this program demonstrates inheritance hierarchy 
*          using constructors
*          1.  RoadVehicle     base class
*          2.  Truck            derived class of RoadVehicle
*          3.  Automobile       derived class of RoadVehicle
*          4.  Motorcycle       derived class of RoadVehicle
*          5.  ElectricCar      derived class of Automobile
*          6.  GasCar           derived class of Automobile
*         add
*          7.  HybridCar        derived class of GasCar and ElectricCar
*
***************************************************************/
#include <iostream>
using namespace std;

/*****************************************
*
*       base class  RoadVehicle
*
****************************************/
class RoadVehicle 
{
      int wheels;
      int passengers;
  
  public:
      // constructor
      RoadVehicle()
      {
          cout << "in RoadVehicle constructor default\n";
          wheels     = 0;
          passengers = 0;
      }
      RoadVehicle(int w, int p)
      {
          cout << "in RoadVehicle constructor #1\n";                       
          wheels     = w;
          passengers = p;
      }     
      // destructor
      ~RoadVehicle()
      {
          cout << "in road_constructor destructor\n";                       
      }            
      // setters
      void set_wheels(int num) { wheels = num; }
      void set_pass(int num)   { passengers = num; }
      // getters
      int  get_wheels()        { return wheels; }      
      int  get_pass()          { return passengers; }
};



/*****************************************
*   lists types of Motorcycles and cars
*****************************************/
enum type {car, van, wagon, honda, harley, yamaha, volt, who_knows};



/*****************************************
*
*       derived class  Truck
*
*****************************************/
class Truck : public RoadVehicle 
{
      int cargo;
  
  public:
      // constructor
      Truck()
      {
          cout << "in Truck constructor default\n";             
          cargo = 0;
      }   
      Truck(int c)
      {
          cout << "in Truck constructor #1\n";                 
          cargo = c;
      } 
      // destructor
      ~Truck()
      {
          cout << "in Truck destructor\n";                       
      }                                
      // member functions
      void set_cargo(int size) { cargo = size; }
      int  get_cargo()         { return cargo; }
      void show();
};
/*****************************************
*      member functions for Truck
*****************************************/
void Truck::show()
{
      cout << "\n************ Truck ***********\n";
      cout << "wheels:                       "  << get_wheels() << "\n";
      cout << "passengers:                   "  << get_pass()   << "\n";
      cout << "cargo capacity in cubic feet: "  << cargo        << "\n";
      cout << "\n";
}




/*****************************************
*
*       derived class Motorcycle
*
*****************************************/
class Motorcycle : public RoadVehicle 
{
      enum type Motorcycle_type;
  
  public:
      //constructos
      Motorcycle()      
      { 
          cout << "in Motorcycle constructor default\n";                          
          Motorcycle_type = who_knows; 
      }       
      Motorcycle(type t)
      { 
          cout << "in Motorcycle constructor #1\n";  
          Motorcycle_type = t; 
      }
      Motorcycle(type t, int wheeles, int passengers) : RoadVehicle(wheeles, passengers)
      { 
          cout << "in Motorcycle constructor #2\n";  
          Motorcycle_type = t; 
      }      
      // destructor
      ~Motorcycle()
      {
          cout << "in Motorcycle destructor\n";                       
      }                 
      // member functions
      void set_type(type t)   { Motorcycle_type = t; }
      enum type get_type()    { return Motorcycle_type; }
      void show();
};
/*****************************************
*      member functions for Motorcycle
*****************************************/
void Motorcycle::show()
{
      cout << "\n****** Motorcycle ******\n";     
      cout << "wheels:     "  << get_wheels() << "\n";
      cout << "passengers: "  << get_pass() << "\n";
      cout << "type: ";
      switch(get_type()) 
      {
          case honda:      cout << "honda\n";
                           break;
          case harley:     cout << "harley\n";
                           break;
          case yamaha:     cout << "yamaha\n";
                           break;
          case who_knows:  cout << "who knows\n";    
      }
      cout << "\n";  
}





/*****************************************
*
*       derived class automible
*
*****************************************/
class Automobile : public RoadVehicle 
{
      enum type car_type;
  
  public:
      //constructos
      Automobile()      
      { 
          cout << "in autobible constructor default\n";                          
          car_type = who_knows; 
      }       
      Automobile(type t)
      { 
          cout << "in autobible constructor #1\n";                          
          car_type = t; 
      }     
      Automobile(type t, int w, int p) : RoadVehicle(w, p)
      { 
          cout << "in autobible constructor #1\n";                          
          car_type = t; 
      }        
      // destructor
      ~Automobile()
      {
          cout << "in Automobile destructor\n";                       
      }           
      // member functions
      void set_type(type t)   { car_type = t; }
      enum type get_type()    { return car_type; }
      void show();
};
/*****************************************
*      member functions for Motorcycle
*****************************************/
void Automobile::show()
{
      cout << "\n****** Automobile ******\n";     
      cout << "wheels:     "  << get_wheels() << "\n";
      cout << "passengers: "  << get_pass() << "\n";
      cout << "type: ";
      switch(get_type()) 
      {
           case van:        cout << "van\n";
                            break;
           case car:        cout << "car\n";
                            break;
           case wagon:      cout << "wagon\n";
                            break;
           case who_knows:  cout << "who knows\n";        
  }
  cout << "\n";  
}




/*****************************************
*
*       derived class GasCar
*
******************************************/
class GasCar : public virtual Automobile
{
      int volGasTank;
      int mpg;
  
  public:
      // constructors
      GasCar()
      {
          cout << "in GasCar constructor default\n";               
          volGasTank = 0;
          mpg        = 0;
      }      
      GasCar(int v, int m)
      {
          cout << "in GasCar constructor #1\n";       
          volGasTank = v;
          mpg        = m;
      }
      GasCar(int v, int m, type at, int w, int p) : Automobile(at, w, p)
      {
          cout << "in GasCar constructor #2\n";       
          volGasTank = v;
          mpg        = m;
      }
      // destructor
      ~GasCar()
      {
          cout << "in GasCar destructor\n";                       
      }                           
      // member functions
      void set_volGasTank(int t)   { volGasTank = t; }
      int  get_volGasTank()        { return volGasTank; }
      void set_mpg(int m)          { mpg = m; }
      int  get_mpg()               { return mpg; }
      void show();
};
/*****************************************
*      member functions for GasCar
*****************************************/
void GasCar::show()
{
      cout << "\n****** gas car ******\n";
      cout << "wheels:        "  << get_wheels() << "\n";
      cout << "passengers:    "  << get_pass()   << "\n";
      cout << "type: ";
      switch(get_type()) 
      {
           case van:        cout << "van\n";
                            break;
           case car:        cout << "car\n";
                            break;
           case wagon:      cout << "wagon\n";
                            break;
           case who_knows:  cout << "who knows\n";
  }
  cout << "gas tank volume:   "  << get_volGasTank()    << "\n"; 
  cout << "miles per gallon:  "  << get_mpg()           << "\n";  
  cout << "\n";  
}


/*****************************************
*
*       derived class ElectricCar

******************************************/
class ElectricCar : public virtual Automobile
{
      int timeBatteryCharge;
      int milesBatteryCharge;
  
  public:
      // constructors
      ElectricCar()
      {
         cout << "in ElectricCar constructor default\n";                    
         timeBatteryCharge  = 0;
         milesBatteryCharge = 0;
      }  
      ElectricCar(int t, int m)
      {
         cout << "in ElectricCar constructor #1\n";                       
         timeBatteryCharge  = t;
         milesBatteryCharge = m;
      }  
      // destructor
      ~ElectricCar()
      {
          cout << "in ElectricCar destructor\n";                       
      }                                         
      // member functions
      void set_timeBatteryCharge(int t)   { timeBatteryCharge = t; }
      int  get_timeBatteryCharge()        { return timeBatteryCharge; }
      void set_milesBatteryCharge(int m)  { milesBatteryCharge = m; }
      int  get_milesBatteryCharge()       { return milesBatteryCharge; }
      void show();
};
/*****************************************
*      member functions for ElectricCar
*****************************************/
void ElectricCar::show()
{
      cout << "\n****** electric car ******\n";     
      cout << "wheels:             "  << get_wheels() << "\n";
      cout << "passengers:         "  << get_pass()   << "\n";
      cout << "type: ";
      switch(get_type()) 
      {
           case van:        cout << "van\n";
                            break;
           case car:        cout << "car\n";
                            break;
           case wagon:      cout << "wagon\n";
                            break;
           case who_knows:  cout << "who knows\n";
  }
  cout << "battery charge time:      "  << get_timeBatteryCharge()  << "\n"; 
  cout << "miles per battery charge: "  << get_milesBatteryCharge() << "\n";  
  cout << "\n";  
}
/*****************************************
*
*       derived class HybridCar
*
******************************************/

class HybridCar : public ElectricCar, public GasCar
{
 
  public:
      // constructors
      HybridCar()
      {
         cout << "in HybridCar constructor default\n";                    
      }  
      HybridCar(int t, int m)
      {
         cout << "in HybridCar constructor #1\n";                       
      }  
      // destructor
      ~HybridCar()
      {
          cout << "in HybridCar destructor\n";                       
      }                                         
      // member functions
 
      void show();
};
/*****************************************
*      member functions for ElectricCar
*****************************************/
void HybridCar::show()
{
      cout << "\n****** HybridCar car ******\n";     
      cout << "wheels:                   "  << get_wheels() << "\n";
      cout << "passengers:               "  << get_pass()   << "\n";
      cout << "type:                     ";
      switch(get_type()) 
      {
           case van:        cout << "van\n";
                     break;
           case car:        cout << "car\n";
                     break;
           case wagon:      cout << "wagon\n";
                     break;
           case who_knows:  cout << "who knows\n";
      }
      cout << "battery charge time:      "  << get_timeBatteryCharge()  << "\n"; 
      cout << "miles per battery charge: "  << get_milesBatteryCharge() << "\n";  
      cout << "gas tank volume:          "  << get_volGasTank()         << "\n"; 
      cout << "miles per gallon:         "  << get_mpg()                << "\n";  
      cout << "\n";  
}

/***********************************
*    prototypes
***********************************/
void testTruck();
void testMotorcycle();
void testAutomobile();
void testElectricCar();
void testGasCar();
void testHybridCar();

int main()
{
  //testTruck();
  //testMotorcycle();
  //testAutomobile();
  //testElectricCar();
  //testGasCar();
  testHybridCar();
  
  system("pause");
  return 0;
}

void testTruck()
{
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
  cout << "\n";  
}

void testAutomobile()
{
  Automobile c;     
     
  c.set_wheels(4);
  c.set_pass(6);
  //c.set_type(van);
  c.show();
  cout << "\n";     
}
void testElectricCar()
{
  ElectricCar ec;  
       
  //ec.set_wheels(4);
  //ec.set_pass(4);
  //ec.set_type(car);
  //ec.set_timeBatteryCharge(6); 
  //ec.set_milesBatteryCharge(350);  
  ec.show();
  cout << "\n";     
}
void testGasCar()
{
  GasCar gc(20, 45, car, 4, 5);
  //ElectricCar ec;            
  //gc.set_wheels(4);
  //gc.set_pass(4);
  //gc.set_type(car);
  //gc.set_volGasTank(18); 
  //gc.set_mpg(22);  
  gc.show();
  cout << "\n";      
}

void testHybridCar()
{
     HybridCar h;
     cout << "\n\n\n\n\n\n";
     h.show();
}
void testMotorcycle()
{
  // use defaults
  Motorcycle mc1;
  mc1.show();
  cout << "\n";    
  
  // use defaults and sets
  //Motorcycle mc2;
  //mc2.set_wheels(2);
  //mc2.set_pass(2);
  //mc2.set_type(yamaha);
  //mc2.show();
  //cout << "\n";   
  
  Motorcycle mc3(honda);
  mc3.show();
  cout << "\n";  
  
  Motorcycle mc4(honda, 2, 2);
  mc4.show();
  cout << "\n";       
}









