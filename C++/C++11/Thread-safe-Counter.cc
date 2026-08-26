
#include <iostream>

#include <iostream>
#include <thread>
#include <condition_variable>

#include <vector>
using namespace std;

int counter = 0;
mutex mt;
//mutex mt;

condition_variable cv;
bool finished = false;

void increment() {
    //unique_lock<mutex> lock(mt);
    //for (int i = 0; i < 100000; i++) {
    for (int i = 0; i < 100; i++) {
        lock_guard<mutex> lock(mt);
        counter++;  // race condition here
        cout<<" "<< counter;
    //lock.unlock();
    }
    cout<<"\n";
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; i++){
        cout<<"================"<<i+1<<"\n";   
        threads.push_back(std::thread(increment));
    }
    for (auto& t : threads)
        t.join();
    std::cout << counter << std::endl;  // should be 400000, but won't be
}
