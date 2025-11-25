/* 
Rotate the array by postion 
Arr = {1,2,3,4,5}
i/p = 2
o/p = {3,4,5,1,2} //left Rotate

//Right Rotate
o/p = {4,5,1,2,3} 
*/ 
#include <iostream>
using namespace std;

void LeftRotate(int* arr, int& size, int& pos) {
    // loop for position
    for (int i=0;i<pos;++i){
        int temp = arr[0];
        for(int j=0;j<size-1; ++j) {
            arr[j]=arr[j+1];
        }
        cout<<"arr[size]="<< arr[size]<<" temp="<<temp<<"\n";
        arr[size-1]=temp;
    }
}
void RightRotate(int* arr, int& size, int& pos) {
    for (int i=0;i<pos;++i){
        int temp = arr[size-1];
        for(int j=size-1;j>=0; --j) {
            arr[j]=arr[j-1];
        }
       cout<<" temp="<<temp<<"\n";
        arr[0]=temp;
    }
}
void Print(int* arr, int& size) {
     for(int j=0;j<size; ++j) {
            cout<<" "<<arr[j];
        }
}

int main(){
   int arr[5] ={1,2,3,4,5};
   int pos =2;
   int size = sizeof(arr)/sizeof(arr[0]);
   Print(arr, size);
   cout<<"\n Rotate ";
//LeftRotate(arr, size, pos);
   RightRotate(arr, size, pos);
   Print(arr, size);
}
