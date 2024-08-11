#include <bits/stdc++.h>
using namespace std;

//If class B is subtype of class , then we should be able to replace object of A with B without breaking the behaviour of the program

//subclass should extend the capability of parent class not narrow it down

class Bike {
    public:
     virtual void turnOnEngine() = 0;
};


class MotorCycle: public Bike{
    bool isEngineOn;
    int speed;

    public:
        void turnOnEngine()  override{
            isEngineOn = true;
        }

        void accelerate(){
            speed = speed + 10;
        }
};

class Cycle: public Bike {
    bool isEngineOn;
    int speed;

    public:
        void turnOnEngine()  override{
            throw runtime_error("No engine detected");
        }

        void accelerate(){
            speed = speed + 2;
        }
};



int main(){
    Bike* ptr;
    Cycle c;
    ptr = &c;
    ptr->turnOnEngine();
    
    return 0;
}