/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

int main(){
    int rows,cols;
    scanf("%d%d",&rows,&cols);
    
    int** matrix=(int**)calloc(sizeof(int*),rows);
    for(int row=0;row<rows;row++){
        matrix[row]=(int*)calloc(sizeof(int),cols);
        for(int col=0;col<cols;col++){
            scanf("%d",&matrix[row][col]);
        }
    }
    
    for(int row=0;row<rows+cols-1;row++){
        for(int col=0;row-col>=0 && col<cols;col++){
            if(row-col<rows)
                printf("%d ",matrix[row-col][col]);
        }
        printf("\n");
    }

    return 0;
}