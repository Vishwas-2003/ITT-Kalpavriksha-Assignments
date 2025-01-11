#include<stdio.h>
#include<string.h>
int exists(int string_index,char* string,char* sub_string){
    int is_exists=1;
    for(int index=0;index<strlen(sub_string);index++){
        if(string[string_index++]!=sub_string[index]){
            is_exists=0;
            break;
        }
    }
    return is_exists;
}
void main(){
    char string[100],sub_string[100];
    fgets(string,sizeof(char)*100,stdin);
    string[strcspn(string,"\n")]='\0';

    fgets(sub_string,sizeof(char)*100,stdin);
    sub_string[strcspn(sub_string,"\n")]='\0';
    int result=-1;

    if(strlen(string)>=strlen(sub_string)){
        int string_index=0;
        for(;string_index<=strlen(string)-strlen(sub_string);string_index++){
            if(exists(string_index,string,sub_string)){
                result=string_index;
                break;
            }
        }
    }
    printf("Result:%d",result);


}