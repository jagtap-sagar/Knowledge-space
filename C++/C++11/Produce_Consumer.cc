// Online C++ compiler to run C++ program online
#include <iostream>
#include<thread>
#include<queue>
#include<condition_variable>
using namespace std;
//C++14 tread producer consumer problem

mutex mt;
condition_variable cv;
queue<int> q;
bool finished = false;

const int N=5;
void producer(){
 for (int i=0;i<N;++i){
     {
        lock_guard<mutex> lock(mt);
        q.push(i+1);
        cout<<" produced :"<<i+1;
     }
      cv.notify_one();
         //sleep
 } //for   
     //this is for finished flag set to true
     {
        lock_guard<mutex> lock(mt);
        finished =true;
     }
      cout<<"\n";
    cv.notify_one();
}

void consumer(){
   
    while(true){
      
        unique_lock<mutex> lock(mt);
        cv.wait(lock,[]{ return !q.empty() ||finished;  });
        if(q.empty() && finished) {break;}
        if(!q.empty()){
            cout<<" Consumed :"<<q.front();
            q.pop();
        }
        lock.unlock();
    }
}

int main() {
    thread prod(producer);
    thread consu(consumer);
    prod.join();
    consu.join();
    return 0;
}
