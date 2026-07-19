#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int m = n+1;
   
    for(int i = 0; i<(2*n-1); i++ ){
    	int x = n;
  		int y = n;
        if(i<=(2*n-1)/2){
            m--;
        }
        else{
            m++;
        }
        printf("\n");
        for(int i = 0; i<(2*n-1); i++){
        	//left side of the pattern
            if(	i < (((2*n)-1)/2)    ){
                if(x>m){
                    printf("%d", x);
                    x--;
                }
                else{
                    printf("%d",m);
                }
            }
            //right side of the pattern
            else if(	i >= (((2*n)-1)/2)    ){
            	int d = y-x;
            	int g = ((2*n)-2)-d;
                if(i>=g){
                    printf("%d", x);
                    x++;
                }
                else{
                    printf("%d",m);
                }
            }
        } 
    }
    return 0;
}