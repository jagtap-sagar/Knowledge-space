/******************************************************************************
logic :  Two index read & write, both start from end ( reverse travelling). 
Write index igonore zero (non zero) and shift value to left.
*******************************************************************************/


10	0	60	50	20	0	0	0	10	9
									W R

0	0	0	0	10	60	50	20	10	9
R	R		W					W R	W R


#include<iostream>
using namespace std;

void move_zeros_to_left(int A[], int n) {
   
  if (n < 1) return;
  
  int write_index = n - 1;
  int read_index = n - 1;

  while(read_index >= 0) {
    if(A[read_index] != 0) {
   // if(A[read_index] == 0) {
      A[write_index] = A[read_index];
      cout<<"write_index="<<write_index;
      write_index--;
      
    }
    
    read_index--;
  }

 int zero =3;
  while(write_index >= 0) {
    A[write_index] = 0;
    write_index--;
  }
}
int main() {
  int v[] = {1, 10, 20, 0, 59, 63, 0, 88, 0};
  int n = sizeof(v) / sizeof(v[0]);

  cout << "Original Array" <<endl;
  
  for(int x=0 ; x<n; x++) {
    cout << v[x];
    cout << ", ";
  }  
  
  move_zeros_to_left(v, n);
  
  cout << endl<< "After Moving Zeroes to Left"<< endl;
  for(int i=0 ; i<n; i++) {
    cout << v[i];
    cout << ", ";
  }  
} 
