// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

//fact 5 = 1*2*3*4*5 =120
int fact (int n) {
    int sum =1;
    for(int i=1;i<=n;i++){
        sum *=i;
    }
    return sum;
}

//recursion 
int fact_rec (int n) {
if (n==0||n==1)
    return 1;
return n*fact_rec(n-1);
}

int main() {

cout<<"\nfact:"<<fact(5);
cout<<"\nby fact recursion:"<<fact_rec(3);
return 0;
}
