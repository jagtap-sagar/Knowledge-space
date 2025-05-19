/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;


struct SingleLinkList {
    int data;
    struct SingleLinkList *next;
    
    SingleLinkList(int param) {
        this->data=param;
        this->next =NULL;
    }
};

typedef  SingleLinkList node;
// ListNode Node;  // Now 'Node' can be used as an alias for 'ListNode'



void InsertAtFront(node*& head,int param) {
    if (head==NULL) {
        cout<<"Linked list is empty";
        return ;
    }
    node *newNode = new node(param);
    newNode->next = head;
    head = newNode;
}

void PrintNode(node *head) {
   node  *temp = head;
    while (temp != NULL){
        cout<<" "<<temp->data;
        temp=temp->next;
    }
}

void InsertInBetween(node*& head, int param, int pos){
    node *temp = head;
    while (temp->data != pos-1){
        temp=temp->next;
    }
    node *newNode = new node(param);
    
    newNode->next = temp->next;
    
    temp->next = newNode;
    
}

int main()
{
    node *head = new node(2);
    head->next = new node(3);
    head->next->next = new node(4);
    
    InsertAtFront(head,1);
     PrintNode(head);
     cout<<"\n";
    InsertInBetween(head,10,3);
    //print 
    PrintNode(head);
    std::cout<<"\nHello World";

    return 0;
}
