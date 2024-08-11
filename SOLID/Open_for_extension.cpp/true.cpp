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

class InvoicePrinter {
    Invoice invoice;

    public: 
        InvoicePrinter(Invoice invoice) : invoice(invoice) {};

        void print(){
        }

};

class InvoiceDAO{
   public:
    virtual void save () const =  0;
};

class DatabaseInvoiceDao : public InvoiceDAO {
    public:
        void save(Invoice invoice){
            cout<<"Saving invoice to DB"<<endl;
        }
};

class FileInvoiceDAO : public InvoiceDAO{
    public:
        void save(Invoice invoice){
            cout<<"Saving invoice to File"<<endl;
        }
};




int main(){
    
     return 0;
}