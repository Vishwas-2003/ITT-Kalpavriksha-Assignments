
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m;
    printf("enter n,m:");
    scanf("%d%d",&n,&m);
    
    int** matrix=(int**)calloc(sizeof(int*),n);
    for(int i=0;i<n;i++){
        matrix[i]=(int*)calloc(sizeof(int),m);
        for(int j=0;j<m;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    
    int t=0;
    printf("enter t:");
    scanf("%d",&t);
    
    
    for(int i=0;i<n;i++){
        int temp=0;
        for(int k=0;k<t;k++){
            temp=matrix[i][0];
            for(int j=0;j<m;j++){
                matrix[i][j]=matrix[i][j+1];
            }
            matrix[i][m-1]=temp;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    
}