#include <bits/stdc++.h>
using namespace std;

class BasePizza {
    public:
    virtual int cost() = 0;
};

class FarmHouse: public BasePizza {
    public:
    int cost() override{
        return 200;
    }
};

class VegDelight: public BasePizza {
    public:
    int cost() override{
        return 120;
    }
};

class Margherita: public BasePizza {
    public:
    int cost() override{
        return 100;
    }
};

class ToppingDecorator: public BasePizza {

};

class ExtraCheese:public ToppingDecorator {
    BasePizza* basePizza;

    public:
        ExtraCheese(BasePizza* pizza){
            this->basePizza = pizza;
        }

        int cost() override{
            return this->basePizza->cost() + 10;
        }
};

class Mushroom: public ToppingDecorator {
    BasePizza* basePizza;

    public:
        Mushroom(BasePizza* pizza){
            this->basePizza = pizza;
        }

        int cost() override{
            return this->basePizza->cost() + 10;
        }
};


int main(){
    BasePizza* pizza = new ExtraCheese(new Mushroom(new Margherita()));

    cout<<"Pizza cost is: "<<pizza->cost()<<endl;

    return 0;
}