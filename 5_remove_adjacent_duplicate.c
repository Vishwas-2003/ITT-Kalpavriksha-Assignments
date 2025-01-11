#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* get_string(char* input,int index){
    char* result=(char*)calloc(sizeof(char),strlen(input));
    int result_index=0;
    for(int input_index=0;input_index<strlen(input);input_index++){
        if(input_index==index || input_index==index+1){
            continue;
        }
        result[result_index++]=input[input_index];
    }
    result[result_index]='\0';
    return result;
}
char* remove_adjacent_duplicate(char* input){
    char* result=input;
    for(int index=0;index<strlen(input)-1;index++){
        if(input[index]==input[index+1]){
            result=get_string(input,index);
            break;
        }
    }

    if(strlen(result)==0)
        return " ";
    if(strlen(result)==strlen(input)){
        return input;
    }
    return remove_adjacent_duplicate(result);
}
void main(){
    char input[100];
    fgets(input,sizeof(char)*100,stdin);
    input[strcspn(input,"\n")]='\0';

    printf("%s",remove_adjacent_duplicate(input));
}
