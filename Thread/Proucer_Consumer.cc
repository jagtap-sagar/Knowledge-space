/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <pthread.h>
using namespace std;


const int  SIZE =10; //buffer size
int buffer[SIZE];
int in =0;
int out =0;
int count =0;

pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_producer = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_consumer = PTHREAD_COND_INITIALIZER;


void* producer(void*argc ){
    int item=0;
    for (int i=0;i<5;++i){
        item=rand()%10;
        
        pthread_mutex_lock(&mutex);
        //TODO , why this loop, why Not if block -> if dummy thread wakeup/mutiple 
        //proucer is there
        //Not go below statment 
        while(count==SIZE){
            pthread_cond_wait(&cond_producer,&mutex); //producer thread to wait 
        }
        
        //increament counter
        count++;
        buffer[in]=item;
        in = (in+1)%SIZE; //CIRCULAR 
        cout<<"\n ---producer="<<item;
        
        //buffer is not empty, send signal to consumer
        pthread_cond_signal(&cond_consumer);
        pthread_mutex_unlock(&mutex);

    }//for
    return 0;
    
}

void* consumer(void*argc ){
    int item=0;
    for (int i=0;i<5;++i){
        pthread_mutex_lock(&mutex);
        
        //wait for buffer to fill
        while(count==0){
            pthread_cond_wait(&cond_consumer,&mutex);
        }
        
        //Now something is written
        item =buffer[out];
        count--;
        out=(out+1)%SIZE;
        cout<<"\n consumer="<<item;
        
        //Now signal to producer & unlock mutex
        pthread_cond_signal(&cond_producer);
        pthread_mutex_unlock(&mutex);
    }
        
    return 0;
}


int main()
{
    std::cout<<"Hello World";
    pthread_t produder_id, consumer_id;
    
    int ret1=pthread_create(&produder_id,NULL,producer,NULL);
    int ret2=pthread_create(&consumer_id,NULL,consumer,NULL);
    
    pthread_join(produder_id,NULL);//wait 
    pthread_join(consumer_id,NULL);
    

    return 0;
}
