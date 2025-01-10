
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int str_len(char* string){
    int index=0;
    while(string[index]!='\0'){
        index++;
    }
    return index;
}
int main(){
    char* input;
    input=(char*)calloc(sizeof(char),16);
    
    scanf("%s",input);
    int start_index=-1;
    int end_index=-1;
    int curr_num=-1;
    int valid=1;
    for(int index=0;index<str_len(input);index++){
        if(input[index]>='0' && input[index]<='9'){
            if(curr_num==0 && input[index]=='0'){
                valid=0;
                break;
            }
            if(curr_num==-1)
                curr_num=0;
            curr_num*=10;
            curr_num+=input[index]-48;
        }
        else if(input[index]=='.'){
            if(curr_num<0 || curr_num>255 || (index<str_len(input)-1 && input[index+1]=='.')){
                valid=0;
            }
            curr_num=-1;
        }
    }
    
    if(valid)
        printf("Valid");
    else
        printf("Invalid");
    

    return 0;
}