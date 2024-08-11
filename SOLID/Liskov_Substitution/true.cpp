#include <bits/stdc++.h>
using namespace std;

class Vehicle{
    public:
       virtual int getNumberOfWheels() = 0;
};

class Cycle: public Vehicle {
    public:
     int getNumberOfWheels() override {
            return 2;
      }
};

class EngineVehicle : public Vehicle {
    public:
      bool hasEngine(){
        return true;
      }
};

class Car : public EngineVehicle {
    public:
        int getNumberOfWheels() override {
            return 4;
        }
};

class Motorcycle : public EngineVehicle {
     int getNumberOfWheels() override {
            return 2;
        }
};

int main(){
    vector<Vehicle*> arr;
    Car c;
    Motorcycle m;
    Cycle cy;
    arr.push_back(&c);
    arr.push_back(&m);
    arr.push_back(&cy);

    for(int i=0; i<arr.size(); i++){
        cout<<"Number of wheels: "<<arr[i]->getNumberOfWheels()<<endl;
    }

    //if you run arr[i]->hasEngine() then it will throw compile time error now so you are safe

    //if you make array type EngineVehicle and you add cycle which is not of type EngineVehicle then you also get compile time error no runtime error
     return 0;
}