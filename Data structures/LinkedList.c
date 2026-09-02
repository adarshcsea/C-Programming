#include<stdio.h>

struct node{
  int data;
  struct node* next;
};

int main(){

  struct node n1, n2, n3, n4, n5;
  
  struct node* head = &n1;
  struct node* tail = &n5;
  
  n1.data = 1;
  n1.next = NULL;

  n2.data = 2;
  n1.next = &n2;
  n2.next = NULL;
  
  n3.data = 3;
  n2.next = &n3;
  n3.next = NULL;

  n4.data = 4;
  n3.next = &n4;
  n4.next = NULL;

  
  n5.data = 5;
  n4.next = &n5;
  n5.next = NULL;

 for( struct node* current = head; current != NULL; current = (*current).next){
   printf( " %d \t", (*current).data);
 }
   
}