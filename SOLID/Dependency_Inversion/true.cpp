#include <iostream>
using namespace std;

class Keyboard {
protected:
    bool connected;
    int key;

public:
    virtual void connect(bool isConnected) = 0;
    virtual void type(int k) = 0;
};

class WiredKeyboard : public Keyboard {
public:
    void connect(bool isConnected) override {
        this->connected = isConnected;
        cout << "Wired keyboard connected: " << connected << endl;
    }

    void type(int k) override {
        this->key = k;
        cout << "Wired keyboard typed key: " << key << endl;
    }
};

class WirelessKeyboard : public Keyboard {
public:
    void connect(bool isConnected) override {
        this->connected = isConnected;
        cout << "Wireless keyboard connected: " << connected << endl;
    }

    void type(int k) override {
        this->key = k;
        cout << "Wireless keyboard typed key: " << key << endl;
    }
};

class MacBook {
private:
    Keyboard* keyboard;

public:
    MacBook(Keyboard* kbd) : keyboard(kbd) {}

    void connectKeyboard(bool isConnected) {
        keyboard->connect(isConnected);
    }

    void typeOnKeyboard(int k) {
        keyboard->type(k);
    }
};

int main() {
    WiredKeyboard wiredKbd;
    WirelessKeyboard wirelessKbd;
    Keyboard *ptr1 = &wiredKbd;
    MacBook mac1(ptr1); 
    Keyboard *ptr2 = &wirelessKbd;
    MacBook mac2(ptr2);  

    mac1.connectKeyboard(true);
    mac1.typeOnKeyboard(5);

    mac2.connectKeyboard(true);
    mac2.typeOnKeyboard(8);

    return 0;
}
