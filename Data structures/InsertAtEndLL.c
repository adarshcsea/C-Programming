//I will insert nodes at the end of the linked list.

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* head;
struct node* traverse;

void InsertNodeAtEnd(int x){
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  (*temp).data = x;
  (*temp).next = NULL;
  
//The new node address is now used to connect new node at the end of the linked list :
  (*traverse).next = temp;

//I have now traversed the 'traverse' pointer to the new node, so when a new node is created, we can repeat the above process.
  traverse = (*traverse).next;
}

void PrintLinkedList(){

//we normally create a temporary pointer and traverse it. This will print all elements of a linked list normally.
  
  struct node* current = head;
  while(current != NULL){
    printf("%d \t", current->data);
    current = current->next;
  }
}

void main(){
  int n;
//I had to create an exception here in a way by creating the first node seperately, assigning head node to it, and creating a temporary pointer.
  printf("Enter the number of elements to store :");
  scanf("%d", &n);
  head = NULL;
  int x;
  printf("Enter the element :");
  scanf("%d", &x);
  head = (struct node*)malloc(sizeof(struct node));
  (*head).data = x;
  (*head).next = NULL;
  traverse = head;
  for(int i=0; i<n-1; i++){
    printf("Enter the element :");
    scanf("%d", &x);
    InsertNodeAtEnd(x);
  }
  PrintLinkedList();
}

