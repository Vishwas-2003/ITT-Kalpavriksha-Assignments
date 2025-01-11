//Rotate matrix 90 degree
#include <stdio.h>
#include <stdlib.h>
void transpose(int n,int** matrix){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
}
void mirror(int n,int** matrix){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-j;j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[i][n-j-1];
            matrix[i][n-j-1]=temp;
        }
    }
}
int main(){
    int n;
    printf("enter d:");
    scanf("%d",&n);
    
    int** matrix=(int**)calloc(sizeof(int*),n);
    for(int i=0;i<n;i++){
        matrix[i]=(int*)calloc(sizeof(int),n);
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    
    transpose(n,matrix);
    mirror(n,matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
}