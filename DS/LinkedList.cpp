

#include <iostream>

using namespace std;

struct node {
  int data;
  struct node *next;
};

void createNode(struct node **root, int *arr, int n){
    cout<<"\n--addr root"<<root;
    struct node *last= NULL;
    for (int i=0;i<n;++i) {
        struct node *t = new node();
        t->data=arr[i];
        t->next =NULL;
        if (*root == NULL) {
            *root =t;
            last=t;
        }
        else {
            last->next=t;
            last=t;
        }
    }//for
    cout<<"\n root"<<root;
}


void Display(struct node **root) {
    cout<<"Dispaly root"<<root;
    struct node *temp =*root;
    while(temp !=NULL)
    {
        cout<<" "<<temp->data;
        temp=temp->next;
    }
}

int main()
{
    cout<<"Hello World";
    int arr[] = {4,5,10,21,40};
    int size = (sizeof(arr)/arr[1]);
    cout<<"arr size="<<size;
    
    struct node *root =NULL;
    cout<<"addr root"<<&root;
    createNode(&root,arr,size);
    cout<<"**root**"<<&root<<"\n";
    Display(&root);
    return 0;
}
