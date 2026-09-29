//I will implement a queue from linked list here.
#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head; //I declared head as a global variable.

struct Node* tail; //I declared tail as a global variable.

void enqueue(int x){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  if(head == NULL){
    temp->data = x;
    head = temp;
    tail = head;
    return;
  }
  temp->data = x;
  tail->next = temp;
  tail = tail->next;
}

void EnqueueLoop(){
  int a = 0;
  printf("\n");
  printf("Enter the elements now - \n");
  for(int i=0; i<1000; i++){
    scanf("%d", &a);
    if(a==0){
      tail->next = NULL;
      break;
    }
    enqueue(a);
  }
  printf("\n As you entered 0, the enqueue operation has been terminated. \n \n");
}

void dequeue(){
  struct Node* temp = head;
  if(head==NULL){
    printf("\n There are no elements to dequeue now! \n \n");
    return;
  }
  head = head->next;
  free(temp);
  printf("The dequeue was done. \n \n");
}

void front(){
  if(head == NULL){
    printf(" \n The queue is empty! \n \n"); return;
  }
  printf("The first element : ");
  printf("%d \n \n",head->data);
  
}

void IsEmpty(){
  if(head == NULL){
    printf("Empty \n \n"); return;
  }
  printf("Not empty \n \n");
}

void printQueue(){
  struct Node* temp = head;
  printf("\n");
  printf("The elements of queue now - ");
  while(temp != NULL){
    printf("%d \t", temp->data);
    temp = temp->next;
  }
  printf("\n \n");
}

char choice(){
  char code;
  printf("Enqueue - E | view front -F | queue-print - Q | dequeue - D | terminate session - T \n");
  printf("Enter the code for the specific operation to be peformed : \n");
  scanf(" %c", &code);
  if(code == 'D'){
    dequeue();
  }
  else if(code == 'F'){
    front();
  }
  else if(code == 'Q'){
    printQueue();
  }
  else if(code == 'E'){
    EnqueueLoop();
  }
  else if(code == 'T'){
    printf(" \nThe session has been terminated at your request. \n \n");
  }
  else{
  printf("\n The code given is not correct. Please try again \n \n");
  }
  return code;
}

void main(){
  head = NULL;
  tail = NULL;
  printf("Welcome to Adarsh Rai's Program! You can enter 0 to stop enqueing in the queue. Enter the numbers to enqueue : \n");
  EnqueueLoop();
  char code;
  while(code != 'T'){
    code = choice();
  }
}