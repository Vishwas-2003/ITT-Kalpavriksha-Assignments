#include<stdio.h>
#include<string.h>
int main(){
    char input[50];
    printf("Enter string:");
    fgets(input,sizeof(char)*50,stdin);
    input[strcspn(input,"\n")]='\0';
    int occurance[26]={0};
    int index=0;
    while(input[index]!='\0'){
        if(input[index]-65<27)
            occurance[input[index]-65]++;
        else
            occurance[input[index]-97]++;

        index++;
    }
    index=0;
    char result[50];
    int result_index=0;
    while(input[index]!='\0'){
        int occurance_index=0;
        if(input[index]-65<27)
            occurance_index=input[index]-65;
        else
            occurance_index=input[index]-97;

        if(occurance[occurance_index]==1){
            result[result_index]=input[index];
            occurance[occurance_index]=-1;
        }
        else if(occurance[occurance_index]>1){
            result[result_index]=input[index];
            occurance[occurance_index]=-1;
        }
        else{
            index++;
            continue;
        }
        result_index++;
        index++;
    }
    result[result_index]='\0';
    printf("Result: %s",result);

    return 0;
}