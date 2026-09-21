//I will find the postfix expression from infix expression using stack here.
#include<stdio.h>
#include<stdlib.h>

struct Node{
  char data;
  struct Node* next;
};

struct Node* head; //I declared head as a global variable.
int check_balance = 0;
char result [100];


//Functions used in this program-
void InfixToPostfix(char arr[]);
void push(char x);
char pop();
int precedence(char operator);

void main(){
  head = NULL;
  char array[100];
    printf("Enter your equation - \n");
    fgets(array, 100, stdin);
    
    InfixToPostfix(array);
    if(check_balance == 0){
    printf("The postfix expression: \n");
    puts(result);
    }
}

//To check the precedence of the operator.
int precedence(char operator){
  if(operator == '+' || operator == '-'){
    return 1;
  }
  if(operator == '*' || operator == '/' || operator == '%'){
    return 2;
  }
  if(operator == '^'){
    return 3;
  }
  return 0;
}

//To push the operator
void push(char x){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

  temp->data = x;
  temp->next = head;
  head = temp;
}

//To pop the operator and return it from the stack
char pop(){
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

//To check if the equation is balanced or not
int checkSymbol(char opening, char closing){
  if(opening == '(' && closing == ')'){
    return 0;
  }
  if(opening == '[' && closing == ']'){
    return 0;
  }
  if(opening == '{' && closing == '}'){
    return 0;
  }
  return 1;
}

//Actual function to convert the equation
void InfixToPostfix(char arr[]){
  int i=0;
  int j = 0;
  char tempVar[20];
  int tempIndex =0;

  
  while(arr[i] != '\0'){

    //We skip the unnecessary nextline and spaces
    if(arr[i] == ' ' || arr[i] =='\n'){
      i++;
      continue;
    }

    
    //Condition if the expression is not balanced
    if(((arr[i] == ')' || arr[i] == ']' || arr[i] == '}') && checkSymbol(tempVar[tempIndex-1], arr[i]) != 0) || ((arr[i] == ')' || arr[i] == ']' || arr[i] == '}') && head == NULL) ){
      check_balance = 1;
      printf("Error! The expression is not balanced! \n");
      return;
    }

    //If an opening symbol appears, we push to stack
    if(arr[i] == '(' || arr[i] == '[' || arr[i] == '{'){
      tempVar[tempIndex] = arr[i];
      push(arr[i]);
      tempIndex++;
    }
    //If a closing symbol comes and the expression is actually balanced, we pop all operators until we reach the opening symbol
    if((arr[i] == ')' || arr[i] == ']' || arr[i] == '}') && checkSymbol(tempVar[tempIndex-1], arr[i]) == 0){
      while(head->data != tempVar[tempIndex-1]){
        result[j] = pop();
        j++;
      }   
      //We have to pop the unnecessary opening symbol still left in the stack
      char pop_extra_Opening_symbol = pop();
      tempIndex--;
    }
 
    
    //To push to stack if an operator appears
    if(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '%' || arr[i] == '^'){

      //To pop from stack if top has higher precedence than the one we encounter
      if(head != NULL && (precedence(arr[i]) < precedence(head->data)) && precedence(head->data) != 0){

        //condition if there are no opening symbols in stack.
        if(tempIndex == 0){  
          while(head != NULL){
            result[j] = pop();
            j++;
          }
        }

        //condition if there are opening symbols in the stack 
        if(tempIndex != 0){  
          while(head->data != tempVar[tempIndex-1]){
            result[j] = pop();
            j++;
          }
        }
        //We push the operator after poping all operators
        push(arr[i]);
      }

      //To pop once if there are two different operators, but with same precedence
      else if(head != NULL && precedence(arr[i]) == precedence(head->data) && precedence(head->data) != 0 && arr[i] != head->data){
        result[j] = pop();
        push(arr[i]);
        j++;
      }//End of precedence checking

      //If precedence of top is lesser or the operator is same as the top, we simply push to stack
      else{
        push(arr[i]);
      }
    }

    //If there are no operators or symbols discovered, we have the operands, which we simply insert it to the result array
    if(arr[i] != '+' && arr[i] != '-' && arr[i] != '*' && arr[i] != '/' && arr[i] != '%' && arr[i] != '^' && arr[i] != '(' && arr[i] != '[' && arr[i] != '{' && arr[i] != ')' && arr[i] != ']' && arr[i] != '}'){
      result[j] = arr[i];
      j++;
    }

    //Incrementing i
    i++;
  }//End of the while loop

  //checking for balance
  if(tempIndex != 0){
    check_balance = 1;
    printf("Expression is not balanced!");
    return;
  }
  
  //Inserting the remaining elements to the resultant array
  while(head != NULL){
    result[j] = pop();
    j++;
  }
  result[j] = '\0';
}