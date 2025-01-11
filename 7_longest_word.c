#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* get_word(char* input,int last_index,int word_size){
    char* word=(char*)calloc(sizeof(char),word_size);
    for(int index=0;index<word_size;index++){
        word[index]=input[last_index-word_size+index];
    }
    return word;
}
void main(){
    char input[100];
    fgets(input,sizeof(char)*100,stdin);
    input[strcspn(input,"\n")]='\0';

    int word_size=0;
    int largest_word_size=0;
    char* largest_word;

    for(int index=0;index<=strlen(input);index++){
        if(input[index]!=' ' && input[index]!='\0'){
            word_size++;
        }
        else{
            if(largest_word_size<=word_size){
                largest_word_size=word_size;
                largest_word=get_word(input,index,word_size);
            }
            word_size=0;
        }
    }

    printf("%s",largest_word);
}
