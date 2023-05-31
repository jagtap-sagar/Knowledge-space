/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Queue {
    int size;
    int rear, front;
    int data[10];
};

void initlize_q(struct Queue *q) {
    q->size=10;
    q->rear=q->front=-1;
}

void display(struct Queue *q) {
    cout<<" rear="<<q->rear;
    cout<<" front="<<q->front;
}

void enqueue(int val,struct Queue *q) {

    if (q->rear==q->size-1){
     cout<<"q is full";
     return;
    }
    q->data[++(q->rear)]=val;
}

int dequeue(struct Queue *q) {

    if (q->rear==q->front){
     cout<<"\nq is empty";
     return -1;
    }
    return q->data[++(q->front)];
}

int main()
{
    struct Queue q;
    initlize_q(&q); // pass address
    display(&q);
    enqueue(5,&q);
    enqueue(15,&q);
    enqueue(7,&q);
    display(&q);
    cout<<"\ndeQ="<<dequeue(&q);
    cout<<"deQ="<<dequeue(&q);
    cout<<"deQ="<<dequeue(&q);
    cout<<"deQ="<<dequeue(&q);
    
    return 0;
}
