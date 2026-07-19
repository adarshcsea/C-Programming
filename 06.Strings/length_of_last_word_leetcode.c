#include<string.h>
#include<stdio.h>
int lengthOfLastWord(char* s) {
    int x = strlen(s)-1;
    int count = 0;
    for(int i=x; i>=0; i--){
        if(s[i] == ' ' && count==0){
            continue;
        }
        if(s[i] != ' '){
            count +=1;
        }
        if(s[i] == ' ' && count!= 0){
            break;
        }
    }
    return count;
}