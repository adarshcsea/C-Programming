#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k);
int max_val(int n[], int a);


int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
} 

void calculate_the_maximum(int n , int k){
    int hi = 0;
    int m = n*n;
    int x[m] = {0};
    int y[m] = {0};
    int z[m] = {0};
    for(int h= 1; h<=n; h++){
    	int i = h+1;
        for(i; i<=n; i++){
            int x1 = h & i;
            if(x1<k){
                x[hi] = x1;
            }
            int y1 = h | i;
            if(y1<k){
                y[hi] = y1;
            }
            int z1 = h ^ i;
            if(z1<k){
                z[hi] = z1;
            }
            hi++;   
        }
    }
    printf("%d \n", max_val(x, m));
    printf("%d \n", max_val(y, m));
    printf("%d \n", max_val(z, m));
}


int max_val(int n[], int a){
    int max = n[0];
    for(int i = 0; i<a; i++){
        if(max<n[i]){
            max = n[i];
        }
    }
    return max;
}




