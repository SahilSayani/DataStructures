#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x){
    data=x;
    next=NULL;
    }
};

// CALL BY REF HERE (&head) as we are modifying LL
void insertEnd(Node* &head , int x){
    Node* temp=new Node(x);
    if(head==NULL){
    head=temp;
    return;
    }
    //traverse to end of LL
    Node*curr=head;
    while (curr->next!=NULL)
    {
    curr=curr->next;
    }
    curr->next=temp;  
    
}

void insertHead(Node* &head , int x){
    Node* temp=new Node(x);
    temp->next=head;
    head=temp;
}

void insertPos(Node* &head, int x, int pos){ // 1   2   3   4   5
    Node* temp=new Node(x);                  // 10  20  30  40  50
    Node* curr=head;                         // insert 5 at pos 4 ----> we have to run a loop till we reach pos 3 
    if(pos==1){                              // start @ 1 ...we need 2 jumps/iterations =>for(i=1;i<=pos-2;i++)
    temp->next=head;                         
    head=temp;
    return;
    }                    
    for (int i = 1; i <=pos-2 ; i++)
    {
        curr=curr->next;
        if (curr==NULL){
        cout<<"position does not exist returning initial LL : \n";
        return;
    }
    }
    
    temp->next=curr->next;
    curr->next=temp;
    return;

}
void deletePos(Node* &head,int pos){
Node* curr=head; 
if(pos==1){
    delete head;
    head=curr->next;
    return;
}
for (int i = 1; i <=pos-2 && curr!=NULL; i++)
{
    curr=curr->next;
}
Node* temp=curr->next;
curr->next=temp->next;
delete temp;
}

void printList(Node* head){
    Node*curr=head;
    while (curr!=NULL)
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    }
    cout<<"\n";
}

int main(){
    Node *head=NULL;
    //creation of LL
    int n;
    cout<<"enter nodes"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int p;
        cout<<"enter data:"<<endl;
        cin>>p;
        insertEnd(head,p);
    }
    // print LL
    printList(head);
    insertHead(head,5);
    cout<<"\nLL after insertion at head is \n";
    printList(head);
    
    // ADD node at nth position
    int pos,dat;
    cout<<"\nenter data and position to ADD new node\n"<<endl;
    cin>>dat>>pos;
    insertPos(head,dat,pos);
    // print LL
    printList(head);
    
    // DELETE node at nth position
    deletePos(head,pos);
    printList(head);

}

