#include<stdio.h>
#include<string.h>
void check_occurances(char* input,int * occurance){
    for(int index=0;index<strlen(input);index++){
        if(input[index]-'A'<27){
            occurance[input[index]-'A']++;
        }
        else if(input[index]-'a'<27){
            occurance[input[index]-'a'+26]++;
        }
    }
}
int main(){
    char input[100];
    fgets(input,sizeof(char)*100,stdin);
    input[strcspn(input,"\n")]='\0';

    char replacing_char;
    scanf("%c",&replacing_char);
    getchar();

    int occurance[52]={0};
    check_occurances(input,occurance);

    for(int index=0;index<strlen(input);index++){
        if(input[index]-65<27){
            if(occurance[input[index]-65]==1){
                input[index]=replacing_char;
                break;
            }
        }
        else if(input[index]-'a'<27){
            if(occurance[input[index]-'a'+26]==1){
                input[index]=replacing_char;
                break;
            }
        }
    }
    printf("%s",input);
    return 0;
}