#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sum(int a);

int main() {
	
    int n;
    scanf("%d", &n);
    printf("%d", sum(n));
    return 0;
}

int sum(int a){
    int j = 0;
    int z = 1;
    int y = 10000;
    
    for(int i = 0; i<5; i++ ){
        int k = a/y;
        if(k>=10 && k<=100){
            k = (k%10);
        }
        else if(k>=100 && k<=1000){
             k = (k%100)%10;
        }
        else if(k>=1000 && k<=10000){
            k = ((k%1000)%100)%10;
        }
        else if(k>=10000 && k<=100000){
            k = (((k%10000)%1000)%100)%10;
        }
        
        j = j + k;
        y = y/10;
    }
    return j;
}