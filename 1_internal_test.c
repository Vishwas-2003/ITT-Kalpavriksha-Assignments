#include<stdio.h>
void print_matrix(int rows,int cols,int matrix[rows][cols]){
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            printf("%d ",matrix[row][col]);
        }
        printf("\n");
    }
}
void handle_input(int rows,int cols,int matrix[rows][cols]){
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            scanf("%d",&matrix[row][col]);
        }
    }
}
void main(){
    int rows,cols;
    scanf("%d",&rows);
    cols=rows;
    int matrix[rows][cols];

    handle_input(rows,cols,matrix);
    
    for(int row=0;row<rows;row++){
        for(int col=row;col<cols;col++){
            int temp=matrix[row][col];
            matrix[row][col]=matrix[col][row];
            matrix[col][row]=temp;
        }
    }

    print_matrix(rows,cols,matrix);
}