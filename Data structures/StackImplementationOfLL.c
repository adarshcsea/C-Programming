//I will implement a stack from linked list here.
#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head; //I declared head as a global variable.

void push(int x){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = head;
  head = temp;
}

void pushloop(){
  int a = 0;
  printf("\n");
  printf("Enter the elements now - \n");
  for(int i=0; i<1000; i++){
    scanf("%d", &a);
    if(a==0)break;
    push(a);
  }
  printf("\n As you entered 0, the push operation has been terminated. \n \n");
}

void pop(){
  struct Node* temp = head;
  if(head==NULL){
    printf("\n There are no elements to pop now! \n \n"); return;
  }
  head = head->next;
  free(temp);
  printf("The first element has been deleted. \n \n");
}

void top(){
  if(head == NULL){
    printf(" \n The stack is empty! \n \n"); return;
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

void printStack(){
  struct Node* temp = head;
  printf("\n");
  printf("The elements of stack now - ");
  while(temp != NULL){
    printf("%d \t", temp->data);
    temp = temp->next;
  }
  printf("\n \n");
}

char choice(){
  char code;
  printf("pop - P | view-top - V | stack-print - S | insert/push - I | terminate session - T \n");
  printf("Enter the code for the specific operation to be peformed : \n");
  scanf(" %c", &code);
  if(code == 'P'){
    pop();
  }
  else if(code == 'V'){
    top();
  }
  else if(code == 'S'){
    printStack();
  }
  else if(code == 'I'){
    pushloop();
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
  printf("Welcome to Adarsh Rai's Program! You can enter 0 to stop pushing in stack. Enter the numbers to push : \n");
  pushloop();
  char code;
  for(int i=0; i<1000; i++){
    code = choice();
    if(code == 'T')break;
  }
}