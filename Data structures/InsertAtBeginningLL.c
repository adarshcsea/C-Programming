//I will insert nodes at the beginning of the linked list.

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* head;

void InsertNodeAtBeginning(int x){
  struct node* temp = head;
  head = (struct node*)malloc(sizeof(struct node));
  (*head).data = x;
  (*head).next = temp;
}

void PrintLinkedList(){
  struct node* current = head;
  while(current != NULL){
    printf("%d \t", current->data);
    current = current->next;
  }
}

void main(){
  int n;
  printf("Enter the number of elements to store :");
  scanf("%d", &n);
  head = NULL;
  int x;
  for(int i=0; i<n; i++){
    printf("Enter the element :");
    scanf("%d", &x);
    InsertNodeAtBeginning(x);
  }
  PrintLinkedList();
}

