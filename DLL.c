#include<stdio.h>
#include<stdlib.h>

struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it. 
struct Node* GetNewNode(int x) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(int x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head; 
	head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}
void insertPos(int x, int pos){ // 1   2   3   4   5
    struct Node* temp=GetNewNode(x);                  // 10  20  30  40  50
    struct Node* curr=head;                   // insert 5 at pos 4 ----> we have to run a loop till we reach pos 3 
    if(pos==1){                              // start @ 1 ...we need 2 jumps/iterations =>for(i=1;i<=pos-2;i++)
    temp->next=head;                         
    head=temp;
    return;
    }                    
    for (int i = 1; i <=pos-2 ; i++)
    {
        curr=curr->next;
        if (curr==NULL){
        printf("position does not exist returning initial LL : \n");
        return;
    }
    }
	
	if(curr->next==NULL){      //HANDLES INSERT AT END
		curr->next=temp;
		temp->prev=curr;
		return;
	}

    
    temp->next=curr->next; //temp->next =(curr.next)
    curr->next->prev=temp; //(curr.next)->prev = temp

    curr->next=temp;
    temp->prev=curr;
    return;

}
//Prints all the elements in linked list in forward traversal order
void Print() {
	struct Node* temp = head;
	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order. 
void ReversePrint() {
	struct Node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main() {

	//Driver code to test the implementation
	head = NULL; // empty list. set head as NULL. 
	
	// Calling an Insert and printing list both in forward as well as reverse direction. 
	InsertAtTail(2);
	InsertAtTail(4); 
    InsertAtTail(6);
    InsertAtTail(8);  
    insertPos(10,5);
    Print(); 
    ReversePrint();
}