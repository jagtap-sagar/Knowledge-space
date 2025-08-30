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
