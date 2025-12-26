/******************************************************************************         
Singleton design pattern
*******************************************************************************/
#include<iostream>
using namespace std;

class Singleton {
	static Singleton* m_ptr;
	public :
       /*static Singleton* getInstance() {
		if (m_ptr ==NULL ) {
		  m_ptr = new Singleton() ;
	    } 
	    return m_ptr;
       }*/
/*
Below code is thread safe.
For local static, Since C++11 the compiler automatically injects a guard variable and mutex-like logic around the function-local static.
*/
       static Singleton& getInstance() {
         static Singleton obj;
		 return obj ;
       }
       
       void Show() {
           cout<<"\n Show";
       }
 private : 
   Singleton(const Singleton& ref ) =delete;// copy constr
  Singleton& operator = (const Singleton& ref ) =delete ; //assing
   Singleton() = default;
};

Singleton* Singleton:: m_ptr =NULL;
//int* Singleton::var=Null;
//int A::i = 10;

int main() {
 Singleton* ptr = Singleton:: getInstance();
 ptr->Show();

}
