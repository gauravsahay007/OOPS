#include <bits/stdc++.h>
using namespace std;
//Class should have only one reason to change

class Marker {
    public:
        string name;
        string color;
        int year;
        int price;

    public :
     Marker(string name, string color, int year, int price) : name(name), color(color), year(year), price(price) {};

};

class Invoice {
    private:
    Marker marker;
    int quantity;

    public:
     Invoice(Marker marker, int quantity) : marker(marker) , quantity(quantity) {};

    //first reason to change if we want to change
    // calculation logic
     int calculateTotal(){
        int price = ((marker.price)*this->quantity);
        return price;
    }

    //second reason to change if we want to change print format
     void printInvoice(){
        //print the invoice
     }
    
    //third reason to change if we want to change saving to DB to saving to file
     void saveToDB(){
        //save to DB
     }
};

//Three reasons to change in a single class => S principle is not followed

int main(){
    
     return 0;
}