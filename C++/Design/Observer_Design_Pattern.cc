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

===========================================================================================================

 // Observer Interface
class Observer {
public:
    virtual void update() = 0; // Or with specific data: virtual void update(Subject* subject) = 0;
    virtual ~Observer() = default;
};

// Subject Interface
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
    virtual ~Subject() = default;
};

// Concrete Subject
class ConcreteSubject : public Subject {
private:
    std::vector<Observer*> observers;
    int state; // Example state
public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }
    void detach(Observer* observer) override {
        // Remove observer from the vector
        // (Careful with iterators and potential memory issues if raw pointers are used)
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }
    void notify() override {
        for (Observer* observer : observers) {
            observer->update(); // Or observer->update(this);
        }
    }
    void setState(int newState) {
        state = newState;
        notify(); // Notify observers when state changes
    }
    int getState() const {
        return state;
    }
};

// Concrete Observer
class ConcreteObserver : public Observer {
private:
    ConcreteSubject* subject;
    // Potentially store a copy of the subject's state or a reference
public:
    ConcreteObserver(ConcreteSubject* s) : subject(s) {}
    void update() override {
        // React to the subject's state change
        // Example: access subject's state if update(Subject* subject) was used
        // int subjectState = subject->getState();
        // std::cout << "Observer updated. Subject state: " << subjectState << std::endl;
    }
};
