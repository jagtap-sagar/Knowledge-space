// Online C++ compiler to run C++ program online
#include <iostream>

#include <string>
#include <thread>
#include <queue>
#include <condition_variable>
using namespace std;

mutex mt;
condition_variable cv;
bool finished = false;

string str ="abcd";
string num = "1234";
string result = "";


void str_fun(){
    cout<<"\n inside str_fun ";
    for(auto ch : str){
        unique_lock<mutex> lock(mt);
        cv.wait(lock,[]{return !finished ;});
        result +=ch;
        //cout<<" result : "<<result;
        finished =true;
        lock.unlock();
        cv.notify_one();
    }
}

void int_fun(){
    cout<<"\n inside int_fun ";
    for(auto ch : num){
        unique_lock<mutex> lock(mt);
        cv.wait(lock,[]{return finished; });
        result +=ch;
        //cout<<" result : "<<result;
        finished =false;
        lock.unlock();
        cv.notify_one();
    }
}

int main() {
   
    thread tstr(str_fun);
    thread tnum(int_fun);
    //cout<<"\n Result="<<result;
    tstr.join();
    tnum.join();
    cout<<"\n Result="<<result;

    return 0;
}
