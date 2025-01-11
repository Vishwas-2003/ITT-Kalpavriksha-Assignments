#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int is_present(char* string_1,char* string_2,int left,int right){
    int present=1;
    int present_1[27]={0},present_2[27]={0};
    for(int index=0;index<strlen(string_2);index++){
        if(string_2[index]==' ')
            present_2[26]++;
        else if(string_2[index]-65<26){
            present_2[string_2[index]-65]++;

        }
        else
            present_2[string_2[index]-97]++;
    }
    for(int index=left;index<=right;index++){ 
        if(string_1[index]==' ')
            present_1[26]++;
        else if(string_1[index]-65<26){
            present_1[string_1[index]-65]++;
        }
        else
            present_1[string_1[index]-97]++;
    }
    for(int index=0;index<27;index++){
        if(present_2[index]!=0 && present_1[index]<present_2[index]){
            present=0;
            break;
        }
    }
    return present;
}
char* generate_string(char* string,int left,int right){
    char* result=(char*)calloc(sizeof(char),right-left+2);
    int result_index=0;
    for(int index=left;index<right+1;index++){
        result[result_index++]=string[index];
    }
    return result;
}
char* find_smallest_window(char* string_1,char* string_2){
    int window_left=0,window_right=strlen(string_1);
    for(int left=0;left<=strlen(string_1)-strlen(string_2);left++){
        for(int right=strlen(string_2)+left-1;right<strlen(string_1);right++){
            if(is_present(string_1,string_2,left,right)){
                if(right-left<window_right-window_left){
                    window_right=right;
                    window_left=left;
                }
            }
        }
    }
    return generate_string(string_1,window_left,window_right);
}
void main(){
    char string_1[100];
    fgets(string_1,sizeof(char)*100,stdin);
    string_1[strcspn(string_1,"\n")]='\0';

    char string_2[100];
    fgets(string_2,sizeof(char)*100,stdin);
    string_2[strcspn(string_2,"\n")]='\0';

    printf("%s",find_smallest_window(string_1,string_2));
}