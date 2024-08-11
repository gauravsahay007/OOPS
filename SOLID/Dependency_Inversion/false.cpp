#include <bits/stdc++.h>
using namespace std;
//class should depend on interface rather than concrete classes

class WiredKeyboard {
        bool connected;
        int key;
    public:
        WiredKeyboard(bool isConnected): connected(isConnected) {};
        void type (int k){
            this->key = k;
        }
};

class WirelessKeyboard {
        bool connected;
        int key;
    public:
        WirlessKeyboard(bool isConnected): connected(isConnected) {};
        void type (int k){
            this->key = k;
        }
};

class MacBook {
    private:
    final WiredKeyboard keyboard;

    public: 
    Macbook(){
        //assigning concrete class here so the problem is that, if we want to change keyboard type from wired to wireless then we cant to this is not foloowing principle of dependency inversion 
        keyboard = new WiredKeyboard();
    }
};

int main(){
    
    return 0;
}