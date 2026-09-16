/*
LeetCode
Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.
Example 2:

Input: n = 5
Output: "0102030405"

  */

#include <iostream>
#include <thread>
#include <condition_variable>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    std::mutex mt;
    std::condition_variable cv;
    int turn;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        turn =0;  
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i =1; i <= n; ++i){
            unique_lock<mutex> lock(mt);
            cv.wait(lock,[this](){return turn==0;});
            //std::cout<<0 <<std::flush;
            printNumber(0);
            turn = (i % 2 ==1)? 1: 2;
            
            lock.unlock();
            cv.notify_all();
    
        }//for
        
    }
    
    void even(function<void(int)> printNumber) {
        for (int i=2; i <= n; i +=2){
            unique_lock<mutex> lock(mt);
            cv.wait(lock,[this](){return turn==2;});
            printNumber(i);
            //std::cout<<i<<std::flush;
            turn =0;
            lock.unlock();
            cv.notify_all();
        }//for
    }

    void odd(function<void(int)> printNumber) {        
        for (int i =1; i <= n; i +=2){
            unique_lock<mutex> lock(mt);
            cv.wait(lock,[this](){return turn==1;});
            //std::cout<<i<<std::flush;
            printNumber(i);

            turn =0;
            lock.unlock();
            cv.notify_all();
        }//for
    }
   
};
