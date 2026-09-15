//I will reverse a string with stack here.
#include<stdio.h>
#include<stdlib.h>

struct Node{
  char data;
  struct Node* next;
};

struct Node* head; //I declared head as a global variable.

void push(char x);
void CreateStack(char arr[]);
char pop();
void reverse(char arr[]);

void main(){
  head = NULL;
  char array[100];
  printf("Enter your string - ");
  fgets(array, 100, stdin);
  
  printf("Your string before reversing - ");
  puts(array);
  
  CreateStack(*array);
  reverse(*array);
  
  printf("Your string after reversing - ");
  puts(array);
}

void push(char x){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = head;
  head = temp;
}

void CreateStack(char arr[]){
  int i=0;
  while(arr[i] != '\0'){
    push(arr[i]);i++;
  }
}

char pop(){
  if(head==NULL){
    return '\0';
  }
  
  struct Node* temp = head;
  head = head->next;
  char a = temp->data;
  free(temp);
  return a;
}

void reverse(char arr[]){
  int i=0;
  while(arr[i] != '\0'){
    arr[i] = pop();
    i++;
  }
}