/*
Leetcode
Example 1:

Input: nums = [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
Example 2:

Input: nums = [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
 
*/
class Foo {
   static int count;
   std::mutex mt;
   std::condition_variable cv;
public:
    Foo()  {
        count =1;
        /*thread t1(first);
        //thread prod(producer);
        thread t2(second);
        thread t3(third);
        */
    }/*
    ~Foo() {
        t1.join();
        t2.join();
        t3.join();
    }*/
    void first(function<void()> printFirst) {
        std::unique_lock<mutex> lock (mt);
        cv.wait(lock,[]{return (count==1);});
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++count;
        lock.unlock();
        //cv.notify_one();
        cv.notify_all();

    }

    void second(function<void()> printSecond) {
        std::unique_lock<mutex> lock (mt);
        cv.wait(lock,[]{return (count==2);});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++count;
        lock.unlock();
        //cv.notify_one();
         cv.notify_all();/* notify_one() works too since only one waiter can proceed next, but notify_all() is safer/more idiomatic here since you have multiple distinct waiters on the same cv */
    }

    void third(function<void()> printThird) {
        std::unique_lock<mutex> lock (mt);
        cv.wait(lock,[]{return (count==3);});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        ++count;
        lock.unlock();
        //cv.notify_one();
         cv.notify_all();
    }
};

int Foo :: count =0;
