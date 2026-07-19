#include<stdio.h>
int fibonacci(int arr [], int m);
int main(){
	int n; 
	printf("Enter a number:");
	scanf("%d", &n);
	int arr[n];
	printf("The fibonacci sequence of %d is : \n", n);
	fibonacci(arr, n);
	return 0;	
}

int fibonacci( int arr [], int m){
	arr[0] = 0;
	arr[1] = 1;
	printf("%d \t %d \t", arr[0], arr[1]);
	int h = 2;
	for(int i = 2; i<m; i++){
		arr[h] = arr[h-1] + arr[h-2];
		printf("%d \t", arr[h]);
		h++;
	}
	return 0;
}