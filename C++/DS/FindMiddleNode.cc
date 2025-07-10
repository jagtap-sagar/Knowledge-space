/*
Find middle node of LL with single pass ,
Ans :- used two pointer slow & fast ,
IMP : while(fast !=NULL && fast->next !=NULL) 
otherwise it give segmentation fault.

  */

#include<iostream>
#include<vector>
using namespace std;

struct LinkList {
    int val;
    struct LinkList *next;
    
    LinkList(int data) {
        val=data;
        next=NULL;
    }
    void add(const int data);
    void print();
    void findMiddleNode();
};
typedef  LinkList Node;


void Node::add(const int data){
     Node *temp =this;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    Node *newNode = new Node(data);
    temp->next=newNode;
}

void Node::print(){

  Node *temp =this;
  while (temp !=NULL){
      cout<<temp->val<<"->";
      temp=temp->next;
  }
  cout<<"NULL";
}

void Node::findMiddleNode(){
    cout<<" Middle node\n";
    Node *slow;
    Node *fast=slow=this;
    
    while(fast!=NULL && fast->next !=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"\nmiddle node="<<slow->val;
}

int main () {
    Node *head = new Node(5);
    head->add(10);
    head->add(20);
    head->add(30);
    head->add(40); 
    head->add(50); 
    head->print();
    
    head->findMiddleNode();
    
}
