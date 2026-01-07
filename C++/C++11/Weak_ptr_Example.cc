#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Person {
     public:
 // shared_ptr<Person>partner;
 weak_ptr<Person>partner;
  Person() {cout<<" \ncreated";}
  ~Person(){cout<<"\n Deleted";}
};

int main() {
   
    shared_ptr<Person> p1 = make_shared<Person> ();
    shared_ptr<Person> p2 = make_shared<Person> ();
    p1->partner=p2;
    p2->partner=p1;
    std::cout << "End of main\n";
    return 0;
}
