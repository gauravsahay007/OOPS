#include <bits/stdc++.h>
using namespace std;

//stack memory
class Singleton{
    private:
        Singleton(){}
        vector<int>logger;
    public:
        Singleton& operator=(const Singleton&) = delete;
        Singleton& operator=(const Singleton&&) = delete;

        Singleton(const Singleton&) = delete;
        Singleton(const Singleton&&) = delete;
        
        static Singleton& getInstance(){
            static Singleton s;
            return s;
        }

        void add(int i){
            logger.push_back(i);
        }

        int get(int i) const{
           return logger[i]; 
        }

        int size() const{
            return logger.size();
        }
};

int main(){
    Singleton& s = Singleton::getInstance();
    s.add(1);
    s.add(2);
    s.add(3);

    cout<<s.size()<<endl;
    cout<<s.get(0)<<" "<<s.get(1)<<" "<<s.get(2)<<endl;

    Singleton& t = Singleton::getInstance();
    t.add(4);
    cout<<t.size()<<endl;
    cout<<t.get(0)<<" "<<t.get(1)<<" "<<t.get(2)<<" "<<t.get(3)<<endl;

    return 0;
}