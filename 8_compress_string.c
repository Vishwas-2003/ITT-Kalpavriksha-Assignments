#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(){
    char input[100];
    fgets(input,sizeof(char)*100,stdin);
    input[strcspn(input,"\n")]='\0';

    char result[100];
    int curr_letter_count=0;
    char curr_letter='\0';
    int result_index=0;

    for(int index=0;index<=strlen(input);index++){
        if(curr_letter=='\0'){
            curr_letter=input[index];
            curr_letter_count=1;
        }
        else{
            if(input[index]==curr_letter){
                curr_letter_count++;
            }
            else{
                result[result_index++]=curr_letter;
                result[result_index++]=(char)curr_letter_count+48;
                curr_letter_count=1;
                curr_letter=input[index];
            }
        }
    }
    result[result_index]='\0';
    if(strlen(result)>=strlen(input)){
        printf("%s",input);
    }
    else
        printf("%s",result);
}