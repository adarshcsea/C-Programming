#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    int j;
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<n; i++){
        j = j+arr[i];
    }   
    printf("%d", j);
    free(arr);
    return 0;
}