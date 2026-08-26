/******************************************************************************

*******************************************************************************/

#include <iostream>

#include <iostream>
#include <thread>
#include <condition_variable>

#include <queue>
using namespace std;

mutex mt;
condition_variable cv;
int MAX = 5;
queue<int> q;

void producer() {
    for(int i =0;i<10; i++)    {
        unique_lock<mutex> lock(mt);
        cv.wait(lock,[]{return q.size() < MAX;});
        
        q.push(i);
        cout<<" prod:"<<i;
        lock.unlock();
        cv.notify_one();
    }
}

void cosumer() {
    for(int i =0;i<10; i++)    {
        unique_lock<mutex> lock(mt);
        cv.wait(lock,[]{return !q.empty();});
        cout<<" cos:"<<q.front();

        q.pop();;
        
        lock.unlock();
        cv.notify_one();
    }
}


int main() {
    thread p(producer);
    
    thread c(cosumer);
    
    p.join();
    c.join();
}



==============================================================================
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

====================================================================

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

mutex m;
condition_variable cv;
queue<int> q;
bool finished = true;

void producer() {
    for (int i = 1; i <= 5; ++i) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [] { return finished; });

        q.push(i);
        cout << "producer :" << i << " ";

        finished = false;   // now consumer's turn
        cv.notify_one();
    }
}

void consumer() {
    for (int i = 1; i <= 5; ++i) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [] { return !finished; });

        int value = q.front();
        q.pop();
        cout << "consumer :" << value << " ";

        finished = true;    // now producer's turn
        cv.notify_one();
    }
}

int main() {
    thread prod(producer);
    thread cons(consumer);

    prod.join();
    cons.join();

    return 0;
}
