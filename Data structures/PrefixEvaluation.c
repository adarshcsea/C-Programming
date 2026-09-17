//I will evaluate the prefix expression using stack here.
#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head; //I declared head as a global variable.

void push(int x);
int StackEvaluation(char arr[]);
int pop();

void main(){
  head = NULL;
  char array[100];
  printf("Enter your prefix equation - ");
  fgets(array, 100, stdin);
  
  int i = StackEvaluation(array);

  printf("The prefix evaluation result : %d ", i);
}

void push(int x){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

  temp->data = x;
  temp->next = head;
  head = temp;
}

int StackEvaluation(char arr[]){
  int i=0;
  while(arr[i] != '\0'){
    i++;
  }
  while(i >= 0){
    
    if(arr[i] == '(' || arr[i] == '[' || arr[i] == '{' || arr[i] == ')' || arr[i] == ']' || arr[i] == '}'){
      i--;
      continue;
    }
    
    int a = 0;
    int b = 0;
    switch(arr[i]){
      case '+' : a = pop(); b = pop(); push(a+b); break;
      case '-' : a = pop(); b = pop(); push(a-b); break;
      case '*' : a = pop(); b = pop(); push(a*b); break;
      case '/' : a = pop(); b = pop(); push(a/b); break;
      case '%' : a = pop(); b = pop(); push(a%b); break;
      case '\n' : break;
      case ' ' : break;
      
  //we have done explicit conversion with type casting. It is not required when converting from smaller data type to large data type because implicit conversion happens automatically. I have done it for my future self or anybody who is reading this code to understand.
  // if arr[i] = '2', then '2' - '0' = 2
  
      default : a = arr[i] - '0'; push(a);
    }
    i--;
  }
  return head->data;
}  
  
int pop(){
  if(head==NULL){
    printf("The expression has some errors! ");
    return 0;
  }
  
  struct Node* temp = head;
  head = head->next;
  int data = temp->data;
  free(temp);
  return data;
}