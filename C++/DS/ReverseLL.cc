// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct LinkList {
    int data;
    struct LinkList *next;
    LinkList(int v ) {
        this->data = v;
        this->next = NULL;
    } 
};
typedef LinkList Node;

void PrintNode(Node* &head){
    if ( head ==NULL) {
        return ;
    }
    Node *temp = head;
    while (temp) {
        cout << temp->data<< " ";
        temp = temp->next;
    }
}

void ReverseLinkList(Node*& head) {
    Node *Curr = head, *Next, *Prev=NULL;
    while(Curr ){
        Next = Curr->next;
        Curr->next = Prev;
        
        Prev=Curr;
        Curr=Next; // Move poniter to next;
    }
    // Shift head to last node
    head = Prev; /* Why prev, why Not Curr, As as see above code Curr is inside while loop . Once it reached last node in loop ,
                Curr= Next( which Curr->next,mean it point to NULL node ,So that why we need pass Prev , as till last node  */ 
}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    Node* head = new Node(1);
    
    Node *Second = new Node(2);
    head->next= Second;
    
    Node *Third = new Node(3);
    head->next->next =Third;
    //Node head->next->next = new Node(3);
    
    PrintNode(head);
    cout<<"\n Reverse LL: ";
    ReverseLinkList(head);
    PrintNode(head);
    
    return 0;
}



/*
Node* head = new Node(1);
    
    Node *Second = new Node(2);
    head->next= Second;
    
    Node *Third = new Node(3);
    head->next->next =Third;
    //Node head->next->next = new Node(3);

    how below code worked line 1, line 2 worked why line 3 not work
    Node* head = new Node(1);
    head->next = new Node(2);
    Node head->next->next = new Node(3);
    
    Line-by-line:
Node* head = new Node(1);
✔ valid declaration with an initialiser.
head is introduced as a variable of type Node*.
head->next = new Node(2);
✔ valid assignment-expression.
The object head already exists, so head->next is an l-value and can appear on the left of =.
Node head->next->next = new Node(3);
✗ syntax error.
The keyword Node starts a declaration, so the compiler expects an identifier (or a declarator such as *p, &r, a[10] …) to follow.
Instead it sees the expression head->next->next, which is not an identifier, and it gives up.
*/
