#include <bits/stdc++.h>
using namespace std;

class Vehicle{
     public:
          virtual void driveCapability()  = 0;
};

class SportyVehicle: public Vehicle {
     public:

     void driveCapability() override{
          cout<<"Fast Driving"<<endl;
     }
};

class PassengerVehicle: public Vehicle {
     public:

     void driveCapability() override{
          cout<<"Safe Driving"<<endl;
     }
};

class OffRoadVehicle: public Vehicle {
     public:

     void driveCapability() override{
          cout<<"OffRoad Driving"<<endl;
     }
};


int main(){
     Vehicle* vehicle ;
     SportyVehicle s;
     PassengerVehicle p;
     OffRoadVehicle o;
     vehicle = &s;
     vehicle->driveCapability();
     vehicle = &p;
     vehicle->driveCapability();
     vehicle = &o;
     vehicle->driveCapability();
     return 0;
}