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
--------------more optimized --------------------------------------

   #include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<iostream>
using namespace std;
 
pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var   = PTHREAD_COND_INITIALIZER;
 
void *functionCount1(void *temp);
void *functionCount2(void *temp);
int  count = 1;
#define COUNT_DONE  10
#define COUNT_HALT1  3
#define COUNT_HALT2  6
 
main()
{

 pthread_t thread1, thread2;
 pthread_create( &thread1, NULL, &functionCount1, NULL);

 pthread_create( &thread2, NULL, &functionCount2, NULL);

 pthread_join( thread1, NULL);

 pthread_join( thread2, NULL);
 printf("Final count: %d\n",count);
   exit(0);
}
 
// Write numbers 1-3 and 8-10 as permitted by functionCount2()
 
void *functionCount1(void *temp)
{
 for(;;)
 {
    // Lock mutex and then wait for signal to relase mutex

    pthread_mutex_lock( &count_mutex );
    // Wait while functionCount2() operates on count
    // mutex unlocked if condition varialbe in functionCount2() signaled.
    pthread_cond_wait( &condition_var, &count_mutex );
    //count++;
    printf("Counter value functionCount1: %d\n",count);
    count++;
    pthread_mutex_unlock( &count_mutex );
    if(count >= COUNT_DONE) return(NULL);
  }

}
 
// Write numbers 4-7
 //odd
void *functionCount2(void *temp)
{
  for(;;)
  {
     pthread_mutex_lock( &count_mutex );
     if( count %2 ==0 )
     {
        // Condition of if statement has been met.
        // Signal to free waiting thread by freeing the mutex.
        // Note: functionCount1() is now permitted to modify "count".
        //cout<<"-------------"<<count;
        pthread_cond_signal( &condition_var );
     }

     else
     {
        printf("Counter value functionCount=>2: %d\n",count);
        count++;
     }
     pthread_mutex_unlock( &count_mutex );
     if(count >= COUNT_DONE) return(NULL);
  }
   exit(0);
}

 
