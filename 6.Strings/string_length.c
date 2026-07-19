#include<stdio.h>
int length(char *str);
int main(){
	char name[100];
	printf("Enter the name:");
	fgets(name, 100, stdin);
	int j = length(name);
	printf("Length of the name: %d", j);
}

int length(char *str){
	int h = 0;
	for (int i=0; str[i] != '\0' ; i++){
		if(str[i] == 'z'){
			h++;
		}
	}
	return h;
}
