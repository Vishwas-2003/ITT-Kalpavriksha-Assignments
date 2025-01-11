#include<stdio.h>
#include<string.h>
void main(){
    char sentence[100];
    fgets(sentence,sizeof(char)*100,stdin);
    sentence[strcspn(sentence,"\n")]='\0';

    int space_expected=0;
    int index=0;
    int word_count=0;
    while(sentence[index]!='\0'){
        if(space_expected==0 && sentence[index]!=' '){
            word_count++;
            space_expected=1;
        }
        else if(space_expected==1 && sentence[index]==' '){
            space_expected=0;
        }
        index++;
    }
    printf("Words:%d",word_count);
}