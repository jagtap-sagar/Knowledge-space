#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> &v){
    cout<<"\n";
    for_each(v.begin(),v.end(),[](int x){
        cout<<" "<<x;
    });
}

int Partition(vector<int>& v, int low, int high){
    int pivot=v[high];
    int i=low -1;
   // cout<<"\n";
    cout<<"\nPivot="<<pivot<<" low="<<low<<" "<<v[low]<<"\n";
    char ch =getchar();
    for (int k=low;k<high;k++){
        if(v[k]<pivot){
            i++;
            cout<<"swap="<<v[i]<<" k="<<v[k];
            std::swap(v[i],v[k]);
        }
    }
    cout<<"\n i="<<i<<" v[i+1]="<<v[i+1]<<"v[high]="<<v[high];
    
    std::swap(v[i+1],v[high]);
    PrintVector(v);
    ch =getchar();
 return i+1;   
    
}

void QuickSort(vector<int>& v, int low, int high){
    cout<<"\n1. Low="<<low<<" high="<<high;
    if (low < high){
        int pi = Partition(v,low,high);
        
        cout<<"\npi="<<pi;
        QuickSort(v,low,pi-1);
        PrintVector(v);
        cout<<"===============";
        cout<<"\n2. Low="<<low<<" high="<<high;
       char ch =getchar();
        QuickSort(v,pi+1,high);
    }
    
}


 void PrintArray(int* arr,int size){
     for_each(arr,arr+size,[](int x){
          cout<<" "<<x;
     });
 }
 
int main()
{
    //std::cout<<"Hello World";
    vector<int> v ={64, 34, 25, 12, 22, 11, 90};
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    QuickSort(v,0,v.size()-1);
    PrintVector(v);
    return 0;
}
