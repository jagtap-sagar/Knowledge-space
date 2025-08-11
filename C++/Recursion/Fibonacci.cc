#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
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
