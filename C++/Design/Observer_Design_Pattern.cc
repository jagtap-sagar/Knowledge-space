/*
This is Simple Design pattern for understanding .
  */

#include<iostream>
#include<vector>
#include <memory>
using namespace std;

class Observer {
    public :
   virtual void Notify()=0;
};

class ConcreteObserver1 :public Observer{
    public:
     void Notify() {
        cout<<"\n subject is update";
    }
};

class Subject {
    protected:
    vector<Observer*>obs;
    public:
    virtual void Update() {
        for (auto const mem :obs){
            mem->Notify();
        }
    }
    virtual void Register(Observer *ptr) =0;
};


class ConcreteSubject : public Subject {
    public:
    void Register(Observer *ptr){
        obs.push_back(ptr);
    }
};


int main (){
    ConcreteObserver1 Sagar, Sandeep,Anil,Sunil;
   // ConcreteSubject sub;
   unique_ptr<ConcreteSubject> sub(new ConcreteSubject);
    sub->Register(&Sagar);
    sub->Register(&Sandeep);
    sub->Register(&Anil);
    sub->Register(&Sunil);
    
    cout<<" Subject data changed";
    sub->Update();
    return 0;
}
