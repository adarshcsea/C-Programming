//sun of n natural numbers with recursion
#include<stdio.h>
int natural(int a);
int main(){
	int a;
	printf("Enter a natural number: ");
	scanf("%d", &a);
	printf("Factorial : %d \n",natural(a));
}
int natural(int x){
	if (x == 1){      
		return 1;        
	}
	int z = natural(x-1);
	int y = x*z;
	return y;
}                      

/* o\p           
Enter a natural number: 5 
9        
12
14
15*/
       