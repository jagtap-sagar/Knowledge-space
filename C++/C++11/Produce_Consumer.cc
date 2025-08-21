// Online C++ compiler to run C++ program online
#include <iostream>
#include <thread>
#include <queue>
#include <condition_variable>
using namespace std;

mutex mt;
condition_variable cv;
bool finished = false;
queue<int> q;

void producer(){
    for(int i=0;i<5;i++){
        {// for define scope for lock
            lock_guard<mutex> lock(mt);
            q.push(i+1);
            cout<< "producer :"<<i+1;
        }
         cv.notify_one();
         std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }//for
    // for finished flag
    {// for define scope for lock
        lock_guard<mutex> lock(mt);
        //cv.notify_one();
        finished= true;
    }
    cout<<"\n";
    cv.notify_one();
}

void consumer() {
   
    while(true){
        unique_lock<mutex> lock(mt);// this used manually release lock
        cv.wait(lock,[]{return !q.empty() || finished ;});
        if (q.empty() && finished ){break;}
        if (!q.empty()){
            cout<<" consumer :"<<q.front();
            q.pop();
        } 
        lock.unlock();
    }//while
    
}
int main() {
    // Write C++ code here
    //std::cout << "Try programiz.pro";
    thread prod(producer);
    thread consu(consumer);
    
    prod.join();
    consu.join();
    return 0;
}
