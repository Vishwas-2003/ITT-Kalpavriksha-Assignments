#include<stdio.h>
#include<string.h>
void rotate(char* string){
    char temp_char=string[strlen(string)-1];
    for(int index=strlen(string)-1;index>0;index--){
        string[index]=string[index-1];
    }
    string[0]=temp_char;
}
void main(){
    char string_1[100],string_2[100];

    fgets(string_1,sizeof(char)*100,stdin);
    string_1[strcspn(string_1,"\n")]='\0';
    fgets(string_2,sizeof(char)*100,stdin);
    string_2[strcspn(string_2,"\n")]='\0';

    int result=0;
    if(strlen(string_1)==strlen(string_2)){
        for(int rotation=0;rotation<=strlen(string_1);rotation++){
            if(strcmp(string_1,string_2)==0){
                result=1;
                break;
            }
            else{
                rotate(string_1);
            }
        }
    }

    if(result)
        printf("True");
    else
        printf("False");
}