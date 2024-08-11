#include <bits/stdc++.h>
using namespace std;

class Shape{
    public:
    virtual void draw() = 0;
};

class Rectangle: public Shape {
    public :
    void draw() override {
        cout<<"Rectangle"<<endl;
    }
};

class Circle: public Shape {
    public :
    void draw() override {
        cout<<"Circle"<<endl;
    }
};

class ShapeFactory {
    public:
    Shape* getShape(string input){
        if(input ==  "CIRCLE"){
                return new Circle();
        }
        else if(input == "RECTANGLE"){
                return new Rectangle();
        }
        else return NULL;
    }
};
int main(){
     ShapeFactory* factory = new ShapeFactory();
     Shape* shape = factory->getShape("CIRCLE");
     shape->draw();
    return 0;
}