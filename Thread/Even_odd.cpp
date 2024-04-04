#include<iostream>
#include<mutex>
#include<pthread.h>
#include<cstdlib>
int count=0;
using namespace std;
mutex m;
void* printEven(void *a)
{
   while(1)
   {
       m.lock();
       if(count%2==0)
       {
          cout<<" I am Even"<<count<<endl;
          count++;
       }
       if(count==100)
           break;
       m.unlock();
   }
}
void* printOdd(void *b)
{
    while(1)
    {
       m.lock();
       if(count%2!=0)
       {
           cout<<"I am odd"<<count<<endl;
           count++;
       }
       if(count>100)
          break;
       m.unlock();
    }
 }
 int main()
 {
     int *ptr = new int();
     pthread_t thread1, thread2;
     pthread_attr_t attr;
     pthread_attr_init(&attr);
     pthread_create(&thread1,&attr,&printEven,NULL);
     pthread_create(&thread2,&attr,&printOdd, NULL);
     pthread_join(thread1,(void **)&ptr);
     pthread_join(thread2,(void **)&ptr);
     delete ptr;
 }
