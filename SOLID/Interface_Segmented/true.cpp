#include <bits/stdc++.h>
using namespace std;

// Interfaces should be such that the cient should not impement unnecessary functions they donot need

//Solution: Segment the interface until the above become true




class WaiterInterface {
    public:
        virtual void serveCustomer() = 0;
        virtual void takeOrder() = 0;
};

class CheckInterface {
    public:
        virtual void cookFood() = 0;
        virtual void decideMenu() = 0;
};

class Waiter: public WaiterInterface {
    public:
        
        void serveCustomer() override{
            cout<<"Serving customers..."<<endl;
        }

        void takeOrder() override{
            cout<<"Take order..."<<endl;
        }
};


int main(){
    
    WaiterInterface * ptr;
    Waiter W;
    ptr = &W;
    ptr->serveCustomer();
    return 0;
}