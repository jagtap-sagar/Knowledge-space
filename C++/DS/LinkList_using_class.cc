/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

//struct LinkedList{
class LinkedList{
    int data;
    class LinkedList *next;
public:
   // int data;
    //struct LinkedList *next;
    LinkedList(int param) {
        data=param;
        next=NULL;
    }
    
   // void PrintNode(LinkedList*& head);
void PrintNode();
    void AddNode(LinkedList*& head, int data);
    void AddAtBegin(LinkedList*& head,int data);

};
typedef LinkedList Node;

//void Node::PrintNode(Node*& head){
void Node::PrintNode(){
    
    Node *temp =this;
    while(temp !=NULL){
        cout<<" "<<temp->data;
        temp=temp->next;
    }
}

void Node::AddNode(Node*& head, int data){
    Node *temp =head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    Node *newNode = new Node(data);
    temp->next=newNode;
}

void    Node:: AddAtBegin(Node*& head,int data){
        Node *newNode = new Node(data);
        newNode->next =head ;
        head = newNode;
        
}

int main()
{
    std::cout<<"Hello World";
    Node *head = new Node(5);
    head->AddNode(head,10);
    head->AddNode(head,20);
    head->AddAtBegin(head,1);
    head->AddNode(head,2);
    //head->PrintNode(head);
    head->PrintNode();// why head call again pass as argument. used "this" pointer.

    return 0;
}
