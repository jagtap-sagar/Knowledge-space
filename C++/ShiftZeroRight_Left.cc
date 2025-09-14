// Online C++ compiler to run C++ program online
#include <iostream>

void ShiftToRight(int *arr,int& len){
  int index =0;
  int zeros=0;
  for (int i=0;i<len;i++){
     if(arr[i] !=0){
         arr[zeros++]=arr[i];
     }
  }//
  for(;zeros<len;){
      arr[zeros++]=0;
  }
}

void ShiftToLeft(int *arr,int& len){
  int zeros=len-1;//*** array length is +1 , so start -1 
 
  for (int i=len-1;i>=0;i--){
      if(arr[i] !=0){
          //std::cout <<" "<<arr[i];
         //  std::cout <<"\nzeros: "<<arr[zeros]<<":"<<zeros;;
         arr[zeros]=arr[i];
         zeros--;
     } 
  }//for
  while(zeros >=0){
      arr[zeros--]=0;
  }
}
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    int arr[] = {9,0,1,2,3,4,0,5,0};
    int length = sizeof(arr)/sizeof(arr[0]);
   // ShiftToRight(arr,length);
    ShiftToLeft(arr,length);
    std::cout <<"\n";
    for (int i=0;i<length;i++){
         std::cout <<" "<<arr[i];
    }
    return 0;
}
