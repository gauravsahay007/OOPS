#include <bits/stdc++.h>
using namespace std;

class DriveStrategy {
    public:
    virtual void drive() = 0;
};

class NormalDrive : public DriveStrategy {
    public:
    void drive() override{
        cout<<"Normal drive"<<endl;
    }
};

class SpecialDrive : public DriveStrategy {
    public:
    void drive() override{
        cout<<"Special drive"<<endl;
    }
};

class Vehicle: public DriveStrategy {
    DriveStrategy* strategy;
     public:
          Vehicle(DriveStrategy* s){
            this->strategy = s;
          }

          void drive() {
            strategy->drive();
          }
};

class SportyVehicle: public Vehicle {
     public:

     SportyVehicle(): Vehicle((new SpecialDrive())){

     };


};

class PassengerVehicle: public Vehicle {
     public:

    PassengerVehicle(): Vehicle((new NormalDrive())){

     };
    
};

class OffRoadVehicle: public Vehicle {
     public:

    OffRoadVehicle(): Vehicle((new SpecialDrive())){

     };
     
};


int main(){
     SportyVehicle s;
     PassengerVehicle p;
     OffRoadVehicle o;

     s.drive();
     p.drive();
     o.drive();
     return 0;
}