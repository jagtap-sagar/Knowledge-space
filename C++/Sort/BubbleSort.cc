/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BubbleSort(vector<int> &v){
    
    //outloop size of array ;
    
    for (int i =0;i<v.size()-1;++i){
        bool swapflag = false;
        //inter loop 
        for(int j=0;j<v.size()-1;++j){
            if(v[j]>v[j+1]){
                std::swap(v[j],v[j+1]); //std
                swapflag=true;
            }
        }
        if(!swapflag){ // all array is already sorted;
            break;
        }
    }
}

void PrintVector(vector<int> &v){
    for_each(v.begin(),v.end(),[](int x){
        cout<<" "<<x;
    });
}

 void PrintArray(int* arr,int size){
     for_each(arr,arr+size,[](int x){
          cout<<" "<<x;
     });
 }
 
int main()
{
    std::cout<<"Hello World";
    vector<int> v ={64, 34, 25, 12, 22, 11, 90};
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);

    BubbleSort(v);
    PrintVector(v);
    cout<<"\n";
    PrintArray(arr,size);
    return 0;
}
