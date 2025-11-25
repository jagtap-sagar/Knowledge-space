/*
lock mutex
wait until (i > N) OR (i has the parity I am responsible for)
if (i > N) break
print i and ++i
unlock mutex
wake the other thread
*/
#include<iostream>
#include<thread>
#include<condition_variable>
using namespace std;

mutex mt;
condition_variable cv;
int Cindex =0;
const int N =6;

void even() {
    while (true){
        unique_lock<mutex> lock (mt); 
        cv.wait(lock,[]{return Cindex> N || (Cindex%2)==0;});
        if(Cindex > N ) break;
        cout<<" even:"<<Cindex++;
        lock.unlock();
        cv.notify_all();
    }
}

void odd() {
    while (true){
        unique_lock<mutex> lock (mt); 
        cv.wait(lock,[]{return Cindex> N || (Cindex%2)==1;});
        if(Cindex > N ) break;
        cout<<" odd:"<<Cindex++;
        lock.unlock();
        cv.notify_all();
    }
}

int main(){
    thread e(even);
    thread o (odd);
    e.join();
    o.join();
    
}
//----------------------------- more optimized -----------------------------------------
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex
#include <condition_variable> // std::condition_variable

constexpr int MAX = 20;  // const int MAX =20   // highest number we want to print
std::mutex mtx;             // protects the predicate `turn`
std::condition_variable cv; // allows threads to sleep/wake efficiently
bool turn = false;          // false → even thread’s turn

void even_thread()
{
    for (int i = 0; i <= MAX; i += 2)   // 0 2 4 … 20
    {
        std::unique_lock<std::mutex> lock(mtx);   // lock the mutex
        cv.wait(lock, []{ return !turn; });       // !turn ****    **A**
        /* ---------- critical section ---------- */
        std::cout << "even:" << i << ' ';
        turn = true;                              // hand over to odd
        /* ---------------------------------------- */
        cv.notify_one();                          // **B**
    }                                             // mutex released here
}

void odd_thread()
{
    for (int i = 1; i <= MAX; i += 2)   // 1 3 5 … 19
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return turn; });        // sleep while turn==false
        std::cout << "odd:" << i << ' ';
        turn = false;                             // hand over to even
        cv.notify_one();
    }
}

int main()
{
    std::thread tEven(even_thread);   // spawn worker threads
    std::thread tOdd(odd_thread);

    tEven.join();   // wait until even_thread finishes
    tOdd.join();    // wait until odd_thread finishes
    std::cout << '\n';
}
