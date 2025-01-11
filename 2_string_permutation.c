#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char* input,int start_index){
    for(int index=strlen(input)-1;index>start_index;index--){
        if(input[start_index]<input[index]){
            char temp=input[start_index];
            input[start_index]=input[index];
            input[index]=temp;
            break;
        }
    }
}
void sort(char* input,int index){
    for(int iterate_1=index;iterate_1<strlen(input)+index-1;iterate_1++){
        for(int iterate_2=index;iterate_2<strlen(input)+index-iterate_1-1;iterate_2++){
            if(input[iterate_2]>input[iterate_2+1]){
                char temp=input[iterate_2];
                input[iterate_2]=input[iterate_2+1];
                input[iterate_2+1]=temp;
            }
        }
    }
}
void permutation(char* input){
    int index;
    for(index=strlen(input)-1;index>0;index--){
        if(input[index]>input[index-1]){
            swap(input,index-1);
            sort(input,index);
            printf("%s ",input);
            permutation(input);
            break;
        }
    }
}
void main(){
    char input[100];
    fgets(input,sizeof(char)*100,stdin);
    input[strcspn(input,"\n")]='\0';
    sort(input,0);
    printf("%s ",input);
    permutation(input);
}