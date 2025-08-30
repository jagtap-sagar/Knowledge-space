/*
Base is inherited ** non-virtually** by both A and B.
Derived inherits from both A and B.
Consequence: the object layout of Derived contains two independent Base sub-objects, one via A and one via B.
This leads to
a) ambiguities when you write d.someBaseMember or cast to Base*, and
b) possible redundancy (two copies of data).
  */

// Online C++ compiler to run C++ program online
#include <iostream>
//#include <vector>
//#include <algorithm>
using namespace std;
//diamond problem

class A {
    public:
    int val;
    A():val(10){}
    void Afoo() {
        cout<<"\n A foo";
    }
};

class B:virtual public A {
    public:
    void Bfoo() {
        cout<<"\n B foo";
    }
};

class C:virtual public A {
    public:
    void Cfoo() {
        cout<<"\n C foo";
    }
};

class D:public B, public C {
    public:
    void Dfoo() {
        cout<<"\n D foo";
    }
};

int main() {
    // Write C++ code here
    //D *ptr =new D();
   // ptr->foo();
   D obj;
   cout<<" "<<obj.val<<" ";
  // obj.Afoo();
    return 0;
}


//================= Another example =============
#include <iostream>

struct Base {
    int value = 42;
    void greet() { std::cout << "Hello from Base\n"; }
};

struct A : public Base {           // non-virtual
    void foo() { std::cout << "A\n"; }
};

struct B : public Base {           // non-virtual
    void bar() { std::cout << "B\n"; }
};

struct Derived : public A, public B {};

int main() {
    Derived d;
    // d.value = 10;          // ERROR: ambiguous – which Base::value?
    // d.greet();             // ERROR: ambiguous – which Base::greet?

    // Explicit disambiguation works but is ugly
    d.A::value = 1;
    d.B::value = 2;
    std::cout << d.A::value << " " << d.B::value << '\n'; // prints 1 2
}

//=========Solutions ===========

struct Base {
    int value = 42;
    void greet() { std::cout << "Hello from Base\n"; }
};

struct A : virtual public Base {   // <-- virtual
    void foo() { std::cout << "A\n"; }
};

struct B : virtual public Base {   // <-- virtual
    void bar() { std::cout << "B\n"; }
};

struct Derived : public A, public B {
    
};

int main() {
    Derived d;
    d.value = 10;      
    d.greet();         // call base call as, no virtual in base & in Derive no defination.
}
