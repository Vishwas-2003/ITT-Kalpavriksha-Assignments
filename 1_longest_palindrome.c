#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int is_palindrome(char* string,int left,int right){
    int is_palin=1;
    while(left<right){
        if(string[left]!=string[right]){
            is_palin=0;
        }
        left++;
        right--;
    }
    return is_palin;
}
char* get_string(char* string,int left,int right){
    char* palin_string=(char*)calloc(sizeof(char),100);
    int result_index=0;
    for(int index=left;index<=right;index++){
        palin_string[result_index++]=string[index];
    }
    palin_string=(char*)realloc(palin_string,sizeof(char)*strlen(palin_string)+1);
    return palin_string;
}
char* longest_palindrome(char* string,int left,int right){
    if(is_palindrome(string,left,right-1)){
        return get_string(string,left,right-1);
    }
    char* left_string=longest_palindrome(string,left,right-1);
    char* right_string=longest_palindrome(string,left+1,right);

    if(strlen(left_string)<strlen(right_string)){
        return right_string;
    }
    else    
        return left_string;

}
void main(){
    char input[100];
    fgets(input,sizeof(char)*100,stdin);
    input[strcspn(input,"\n")]='\0';

    printf("%s",longest_palindrome(input,0,strlen(input)));
}