#include <bits/stdc++.h>
using namespace std;
//Open for extension but closed for modification


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
};

class InvoiceDAO{
    Invoice invoice;

    public:
        InvoiceDAO(Invoice Invoice) : invoice(Invoice) {};

        //first reason to change if we want to change DB saving ogic logic
        void saveToDB(){
            //Save to DB
        }

        //Added another method of save to file so the given class i
        void saveToFile(string FileName){

        }
};

class InvoicePrinter {
    Invoice invoice;

    public: 
        InvoicePrinter(Invoice invoice) : invoice(invoice) {};

        //first reason to change if we want to change printing logic
        void print(){
            //print the invoice
        }

};

int main(){
    
     return 0;
}