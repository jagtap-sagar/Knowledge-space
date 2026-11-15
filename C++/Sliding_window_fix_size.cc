/*
first loop sum of arry upto k ;
second loop i = k ;  i -k = 0, 1,2  //for subtraction
                       i = k(3), 4,5, //for adding number

  */
#include <iostream>

int main()
{
    int k =3;
    int arr[] = {3, 5, -4, 9, 8}; //{ 3,8,-4,9,10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int WindowSum = 0, MaxSum =0;
    for(int i =0 ; i< k ; ++i){
        WindowSum += arr[i];
    }
    std::cout<<"\n MaxSum : "<<WindowSum;
    //sliding Window
    for(int i =k ; i< n ; ++i){
        WindowSum = WindowSum - arr[i- k];
        WindowSum = WindowSum + arr[i];
        MaxSum = std::max(MaxSum,WindowSum);
        std::cout<<"\n MaxSum : "<<MaxSum;
    }
    
    return 0;
}    
