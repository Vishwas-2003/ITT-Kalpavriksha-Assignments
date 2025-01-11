#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
    char input[100];
    fgets(input,sizeof(char)*100,stdin);
    input[strcspn(input,"\n")]='\0';

    char remove_char;
    scanf("%c",&remove_char);

    char result[100];
    int result_index=0;

    for(int index=0;index<strlen(input);index++){
        if(input[index]!=remove_char){
            result[result_index++]=input[index];
        }
    }

    result[result_index]='\0';
    printf("%s",result);
}