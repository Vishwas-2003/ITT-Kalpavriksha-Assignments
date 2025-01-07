#include<stdio.h>
#include<string.h>
void string_copy(char* longest_name,char* name){
    for(int index=0;index<strlen(name);index++){
        longest_name[index]=name[index];
    }
    longest_name[strlen(name)]='\0';
}
void main(){
    int rows,cols;
    printf("Enter number of rows:");
    scanf("%d",&rows);
    printf("Enter number of columns:");
    scanf("%d",&cols);

    int n_vowels_names=0;
    char longest_name[51];
    printf("Enter the names:\n");
    char student[rows][cols][51];
    getchar();
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            printf("Name at (%d,%d):",row,col);
            scanf("%[^\n]%*c",student[row][col]);
            if(student[row][col][0]=='a' || student[row][col][0]=='e' || student[row][col][0]=='i' || student[row][col][0]=='o' || student[row][col][0]=='u' || student[row][col][0]=='A' || student[row][col][0]=='E' || student[row][col][0]=='I' || student[row][col][0]=='O' || student[row][col][0]=='U'){
                n_vowels_names++;
            }
            if(strlen(longest_name)<strlen(student[row][col])){
                string_copy(longest_name,student[row][col]);
            }
        }
    }
    printf("\nThe 2D array of names is:\n");
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            printf("%s ",student[row][col]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Number of names starting with a vowel:%d\n",n_vowels_names);
    printf("The longest name:%s",longest_name);
}