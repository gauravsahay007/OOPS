#include <bits/stdc++.h>
using namespace std;
class Singleton{
    protected:
        static Singleton* instance;
        vector<int> logger;

        Singleton(){};

    public:
        Singleton(const Singleton&) = delete;
        Singleton(const Singleton&&) = delete;

        Singleton& operator=(const Singleton&) = delete;
        Singleton& operator=(const Singleton&&) = delete;
        static  Singleton* getInstance(){
            if(instance == NULL){
                //dynamic memory allocation
                instance = new Singleton();
            }

            return instance;
        }

        void add(int i){
            logger.push_back(i);
        }

        int get(int i){
            return logger[i];
        }

        int size() const{
            return logger.size();
        }
};

Singleton* Singleton::instance = NULL;

class FreeMemory : public Singleton{
    public:
    ~FreeMemory(){
        cout<<"Freeing up memory..."<<endl;
        delete instance;
    }
};

int main(){
    Singleton *p = Singleton::getInstance();
    p->add(8);
    p->add(1);
    p->add(2);
    p->add(4);

    cout<<p->size()<<endl;

    Singleton *q = Singleton::getInstance();

    cout<<"Memory Address of p: "<<p<<endl<<"Memory Address of q: "<<q<<endl;

    FreeMemory();

    return 0;
}