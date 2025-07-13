// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
//selection sort 
void SelectionSort(int array[], int n){  
   for (int i=0;i < n-1;i++){
       int minIndex=i;
       for(int j=i+1; j<n; j++){
           if (array[j] < array[minIndex]){
               minIndex=j;
           }
       }
           
           if(minIndex != i) {
               //swap 
               int temp = array[i];
               array[i]=array[minIndex];
               array[minIndex]=temp;
               printArray(array,n);
            }
   }

    
}

int main() {
    // Write C++ code here
    int array[]={6,1,3,2,8,4};
    int size = sizeof(array)/sizeof(array[0]);
    cout<<"size="<<size;
    cout<<"\nbefore sort :";
    for(auto const i:array) {
        cout<<i<<" ";
    }
    SelectionSort(array,size);
    cout<<"\nAfter sort :";
    printArray(array,size);
    for(auto const i:array) {
        cout<<i<<" ";
    }

    return 0;
}
