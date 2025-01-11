#include<stdio.h>
#include<string.h>
void main(){
    char input[100];
    fgets(input,sizeof(char)*100,stdin);
    input[strcspn(input,"\n")]='\0';
    int result=0;
    int is_negative=0;
    for(int index=0;index<strlen(input);index++){
        if(index==0 && input[index]=='-'){
            is_negative=1;
            continue;
        }
        else if(input[index]<'0' || input[index]>'9'){
            result=0;
            break;
        }

        result*=10;
        result+=input[index]-'0';
    }
    if(is_negative)
        result*=-1;
    printf("%d",result);
}