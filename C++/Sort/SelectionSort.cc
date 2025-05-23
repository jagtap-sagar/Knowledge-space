#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

SelectionSort(vector<int> &v){
     for (int i =0;i<v.size()-1;++i){
       int min =i;
        //inter loop 
        for(int j=i+1;j<v.size();++j){
            if(v[j]<v[i]){
               // cout<<"----j="<<v[j]<<" i="<<v[i];
                min=j;
            }
            
        }
      //  cout<<"\n swap j="<<v[min]<<" i="<<v[i];
        std::swap(v[min],v[i]); //s
     } 
     /* int n = v.size();
    
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        
        // Swap the found minimum element with the first element
        std::swap(v[min_idx], v[i]);
    }*/
}

void PrintVector(vector<int> &v){
    cout<<"\n";
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

    PrintVector(v);
   
    cout<<"\n SelectionSort";
    SelectionSort(v);
    PrintVector(v);

    return 0;
}
