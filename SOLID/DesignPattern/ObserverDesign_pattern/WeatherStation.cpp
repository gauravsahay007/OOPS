#include <bits/stdc++.h>
using namespace std;

// Abstract Observer
class DisplayObserver {
public:
    virtual void update() = 0;
    virtual ~DisplayObserver() {}
};

// Abstract Observable (Subject)
class WeatherStationObservable {
public:
    virtual void add(DisplayObserver* obs) = 0;
    virtual void remove(DisplayObserver* obs) = 0;
    virtual void notify() = 0;
    virtual void setTemp(int temp) = 0;
    virtual int getTemp() const = 0;
    virtual ~WeatherStationObservable() {}
};

// Concrete Observable (Weather Station)
class WSObservableImplement : public WeatherStationObservable {
private:
    vector<DisplayObserver*> displayList; // List of observers
    int temp; // Temperature data

public:
    void add(DisplayObserver* obs) override {
        displayList.push_back(obs);
    }

    void remove(DisplayObserver* obs) override {
        displayList.erase(std::remove(displayList.begin(), displayList.end(), obs), displayList.end());
    }

    void notify() override {
        for (auto const &it : displayList) {
            it->update();
        }
    }

    void setTemp(int newTemp) override {
        this->temp = newTemp;
        notify(); // Notify all observers when the temperature changes
    }

    int getTemp() const override {
        return temp;
    }
};

// Concrete Observer (Mobile Display)
class MobileDisplayObserver : public DisplayObserver {
private:
    WeatherStationObservable* observable;

public:
    MobileDisplayObserver(WeatherStationObservable* obs) {
        this->observable = obs;
        observable->add(this); // Automatically register itself with the observable
    }

    void update() override {
        int updatedTemp = observable->getTemp();
        cout << "Mobile Display: Current temperature is " << updatedTemp << " degrees." << endl;
    }
};

// Main function
int main() {
    WSObservableImplement weatherStation; // Create observable

    MobileDisplayObserver mobileDisplay(&weatherStation); // Create observer and register it

    weatherStation.setTemp(25); // Set new temperature, observers should be notified
    weatherStation.setTemp(30); // Set another temperature, observers should be notified again

    weatherStation.remove(&mobileDisplay); // Remove observer

    weatherStation.setTemp(35); // No output since observer is removed

    return 0;
}
