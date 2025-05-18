/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int k =2; //interval
    void FindUniquePair(int *arr,int len){
        //sort array 
        map<int,int>m;
        sort(arr,arr+len);
        
        for(int i=0;i<len;++i){
            if (arr[i]+k == arr[i+1]){
               m.insert({arr[i],arr[i+1]}) ;
            }
            
        }
        
        //print pair 
        for(auto i: m){
            cout<<"\n("<<i.first<<","<<i.second<<")";
        }
        
        
    }
    


int main()
{
    std::cout<<"Hello World";
    
    int arr[]={1,3,5,3,1};
    
    int len = sizeof(arr)/sizeof(arr[0]);
    
    FindUniquePair(arr,len);
    

    return 0;
}
