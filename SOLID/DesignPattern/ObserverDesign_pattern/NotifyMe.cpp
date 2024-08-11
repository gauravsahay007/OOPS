#include <bits/stdc++.h>
using namespace std;

// Abstract Observer
class NotificationAlertObserver {
public:
    virtual void update() = 0;
};

// Abstract Observable
class StockObservable {
public:
    virtual void add(NotificationAlertObserver* obs) = 0;
    virtual void remove(NotificationAlertObserver* obs) = 0;
    virtual void notify() = 0;
    virtual int getStockCount() = 0;
    virtual void setStockCount(int count) = 0;
    virtual ~StockObservable() {}
};

// Concrete Observable Implementation
class IphoneObservableImpl : public StockObservable {
private:
    set<NotificationAlertObserver*> observerList;
    int stockCount;

public:
    IphoneObservableImpl() : stockCount(0) {}

    void add(NotificationAlertObserver* obs) override {
        observerList.insert(obs);
    }

    void remove(NotificationAlertObserver* obs) override {
        observerList.erase(obs);
    }

    void notify() override {
        for (auto &it : observerList) {
            it->update();
        }
    }

    void setStockCount(int count) override {
        if (stockCount == 0 && count > 0) {
            notify();
        }
        stockCount += count;
    }

    int getStockCount() override {
        return stockCount;
    }
};

// Concrete Observer Implementation - Email Alerts
class EmailAlertObserverImpl : public NotificationAlertObserver {
private:
    string emailId;
    StockObservable* observable;

    void sendMail(const string& emailId) {
        cout << "Mail sent to: " << emailId << endl;
    }

public:
    EmailAlertObserverImpl(const string& emailId, StockObservable* obs) {
        this->emailId = emailId;
        this->observable = obs;
    }

    void update() override {
        sendMail(emailId);
    }
};

// Concrete Observer Implementation - Mobile Alerts
class MobileAlertObserverImpl : public NotificationAlertObserver {
private:
    string phoneNumber;
    StockObservable* observable;

    void sendText(const string& phoneNumber) {
        cout << "Text sent to: " << phoneNumber << endl;
    }

public:
    MobileAlertObserverImpl(const string& phoneNumber, StockObservable* obs) {
        this->phoneNumber = phoneNumber;
        this->observable = obs;
    }

    void update() override {
        sendText(phoneNumber);
    }
};

// Main function
int main() {
    StockObservable* iphoneStocksObservable = new IphoneObservableImpl();

    NotificationAlertObserver* obs1 = new EmailAlertObserverImpl("abc@gmail.com", iphoneStocksObservable);
    NotificationAlertObserver* obs2 = new EmailAlertObserverImpl("gauravsahay@gmail.com", iphoneStocksObservable);
    NotificationAlertObserver* obs3 = new MobileAlertObserverImpl("8957058981", iphoneStocksObservable);

    iphoneStocksObservable->add(obs1);
    iphoneStocksObservable->add(obs2);
    iphoneStocksObservable->add(obs3);

    iphoneStocksObservable->setStockCount(10);

    delete obs1;
    delete obs2;
    delete obs3;
    delete iphoneStocksObservable;

    return 0;
}
