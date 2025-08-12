#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    //Also can due below code
    if (n<=1) return n; // n is less than equal to one
    return fib(n-1) + fib(n-2);
}

int main() {
    int n = 4;
    //cout << "Fib(4) = " << fib(n) << endl;
    for (int i=0;i<n;i++){
      cout<<" " << fib(i);
    }
    return 0;
}
//Time Complexity is O(2^n)
                         fib(5)
              ┌────────────┴────────────┐
            fib(4)                    fib(3)
        ┌──────┴──────┐            ┌─────┴─────┐
      fib(3)        fib(2)       fib(2)       fib(1)
    ┌───┴───┐      ┌──┴──┐      ┌──┴──┐        │
  fib(2)  fib(1) fib(1) fib(0) fib(1) fib(0)    1
 ┌──┴──┐     │     │      │      │      │
fib(1) fib(0) 1     1      0      1      0
  │      │
  1      0

// Alternative method is memoization.
//  Time Complexity is O(n).
 #include <iostream>
#include <unordered_map>
using namespace std;

int fib(int n){
   static unordered_map<int,int> cache{{0,0},{1,1}};
    auto temp=cache.find(n);
    if (temp !=cache.end()){
        return temp->second;
    } 
    int val =fib(n-1)+fib(n-2);
    cache[n]=val; // add value 
    return val;
}

int main() {
  int n =7;
  for (int i=0;i<n;++i){
      cout<<" "<<fib(i);
  }
 return 0;
}
