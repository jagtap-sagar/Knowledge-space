/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class X{
    
  public:
  X(int param){
      cout<<param;
  }
  
  
  void operator()( string str){
      cout<<"\nfuntor="<<str;
  }
  
  
  
};


int AddValue(int& param){
      return (param +=2);
  }


int main()
{
    std::cout<<"Hello World";
    X Obj(90);
    //Obj("Hello");
    X(9)("Hello");//functor
    
    std::vector<int> v {1,2,3,4,5} ;
    //functor
    for_each (v.begin(),v.end(),AddValue);
    
    for (auto i:v){
    cout<<" i="<<i;
    }
    
    cout<<"\n Lambda function \n";
    //Now Lambda function 
    for_each(v.begin(),v.end(),[](int& param){
        return param +=5;
    });
     for (auto i:v){
    cout<<" i="<<i;
    }
    
    
    unordered_map<int,int>m;
    m[1]=10;
    m[2]=20;
    m[3]=30;
   // auto result =m.try_emplace(2,400);
   auto result = m.emplace(2,400);
   
    //cout<<"\n result.first "<<result.first;
    cout<<"\n result.seond "<<result.second;
    cout<<"\n result find "<<(m.find(2) == m.end());
    //m[2]=400;
    
    cout<<" \nunorder map printing ";
    for (auto i:m){
    cout<<" m="<<i.first <<" "<<i.second;
    }
    return 0;
}
