#include<stdbool.h>
#include<string.h>
bool isPalindrome(int x) {
    int exception = x;
    int size = 0;
    int* y = NULL;
    for(int i=0; i<1000; i++){
        size++;
        y =  (int*)realloc(y, size*sizeof(int));
        int z = x%10;
        x = x/10;
        y[i] = z;
        if(x<0){
            x = x*(-1);
        }
        if(x == 0){
            break;
        }
    }
    size = size-1;
    bool truth1 = true;
    for(int i = 0; i<=size; i++){
        if(y[i]!=y[size]){
            truth1 = false;
            break;
        }
        if(i==size){
            break;
        }
        size--;
    }
    free(y);
    if(exception==-1){
        truth1 = false;
    }
    return truth1;
}