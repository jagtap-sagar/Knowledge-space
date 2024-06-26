/*
   Function1 is normal 1 to 10 number , 
   function2  is if( count < 3 || count > 6 )
                 { 
                   signal(&condition) // this is skip 4,5,6,7
                 }

 */ 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<iostream>
using namespace std;
 
pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var   = PTHREAD_COND_INITIALIZER;
 
void *functionCount1(void *temp);
void *functionCount2(void *temp);
int  count = 0;
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
   // This like normal 1 to 10 ;
    pthread_cond_wait( &condition_var, &count_mutex );
    count++;
    printf("Counter value functionCount1: %d\n",count);
    pthread_mutex_unlock( &count_mutex );
    if(count >= COUNT_DONE) return(NULL);

  }

}
 
// Write numbers 4-7
 
void *functionCount2(void *temp)
{

  for(;;)
  {
     pthread_mutex_lock( &count_mutex );
     if( count < 3 || count > 6 )

     {

        // Condition of if statement has been met.

        // Signal to free waiting thread by freeing the mutex.

        // Note: functionCount1() is now permitted to modify "count".
        //cout<<"-------------"<<count;
        pthread_cond_signal( &condition_var );
     }

     else
     {
        count++;
        printf("Counter value functionCount=>2: %d\n",count);
     }

     pthread_mutex_unlock( &count_mutex );
     if(count >= COUNT_DONE) return(NULL);
  }
   exit(0);
}
