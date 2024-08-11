#include <bits/stdc++.h>
using namespace std;

// Interfaces should be such that the cient should not impement unnecessary functions they donot need

//Solution: Segment the interface until the above become true


class RestaurantEmployee {
    public:
     virtual void washDish() = 0;
     virtual void serverCustomers() = 0;
     virtual void cookFood() = 0;
};

class Waiter: public RestaurantEmployee{
    public:
        void washDishes() override{
            //not my ob
        }

        void serveCustomerss() override{
            cout<<"Serving customers..."<<endl;
        }

        void cookFood() override{
            //not my job
        }
}
int main(){
    
     return 0;
}