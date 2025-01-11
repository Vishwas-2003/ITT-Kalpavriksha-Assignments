#include<stdio.h>
#include<string.h>
int main(){
    char str1[50],str2[50];

    scanf("%s",str1);
    scanf("%s",str2);

    int occur1[26]={0}; 
    int occur2[26]={0};

    
    for(int index=0;index<strlen(str1);index++){
        occur1[str1[index]-97]+=1;
    }
    for(int index=0;index<strlen(str1);index++){
        occur2[str2[index]-97]+=1;
    }
    int is_anagram=1;
    for(int index=0;index<26;index++){
        if(occur1[index]!=occur2[index]){
            is_anagram=0;
            break;
        }
    }
    if(is_anagram){
        printf("Yes");
    }
    else
        printf("No");


}