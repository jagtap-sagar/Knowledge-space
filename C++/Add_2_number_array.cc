# Add two numbers represented by two arrays
/******************************************************************************

Input : n = 3, m = 3
  >      a[] = { 1, 2, 3 }
  >     b[] = { 2, 1, 4 }
Output : 337

123 + 214 = 337
Input : n = 4, m = 3
        a[] = { 9, 5, 4, 9 }
        b[] = { 2, 1, 4 }
Output : 9763
*******************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

void addTwoArr(int* A,int* B, int An, int Bn){
   int sum=0, carry=0;
   //vector<int> result;
   string  result=" ";
   int i=An-1,j = Bn-1;
   
   while(i>=0||j>=0||carry){
       sum=carry;
       if(i>=0) sum +=A[i--];
       if(j>=0) sum +=B[j--];
       carry =sum/10;
       sum=sum%10;
       
       result +=to_string(sum);
   }
   if (carry){
       result +=to_string(carry);
   }
   reverse(result.begin(),result.end());
   cout<<"Result:"<<stoi(result);
   
}

int main() {
    int A[]= {1,2,3} ,B[]={1,4,5,6};
    int n1=sizeof(A)/sizeof(A[0]);
    int n2=sizeof(B)/sizeof(B[0]);
    addTwoArr(A,B,n1,n2);
    return 0;
}
