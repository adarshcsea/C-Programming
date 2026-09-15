//I will balance symbols using stack here.
#include<stdio.h>
#include<stdlib.h>

struct Node{
  char data;
  struct Node* next;
};

struct Node* head; //I declared head as a global variable.

void push(char x);
int Stack(char arr[]);
void pop();

void main(){
  head = NULL;
  char array[100];
  printf("Enter your equation - ");
  fgets(array, 100, stdin);
  
  int i=0;
  i = Stack(array);

  if(i == 0 && head == NULL){
    printf("Expression is balanced!");
  }
  else{
    printf("Expression is not balanced");
  }
}

void push(char x){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = head;
  head = temp;
}

int Stack(char arr[]){
  int i=0;
  while(arr[i] != '\0'){
    if(arr[i] == '(' || arr[i] == '[' || arr[i] == '{'){
      push(arr[i]);
    }
    else if( (arr[i] == ')' || arr[i] == ']' || arr[i] == '}' ) && head == NULL){
      return 1;
    }
    else if(arr[i] == ')' && head->data == '('){
      pop();
    }
    else if(arr[i] == ']' && head->data == '['){
      pop();
    }
    else if(arr[i] == '}' && head->data == '{'){
      pop();
    }
    else{
      i++;
      continue;
    }
    i++;
  }
  return 0;
}

void pop(){
  if(head==NULL){
    return;
  }
  
  struct Node* temp = head;
  head = head->next;
  free(temp);
  return;
}