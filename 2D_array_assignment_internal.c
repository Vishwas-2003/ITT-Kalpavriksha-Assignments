#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int rows=0,cols=0;
    scanf("%d%d",&rows,&cols);
    
    char*** matrix=(char***)calloc(sizeof(char**),rows);
    for(int row=0;row<rows;row++){
        matrix[row]=(char**)calloc(sizeof(char*),cols);
        for(int col=0;col<cols;col++){
            matrix[row][col]=(char*)calloc(sizeof(char),50);
            scanf("%s",matrix[row][col]);
        }
    }
    int n_result=0;
    char** result=NULL;
    int* results_count=NULL;
    
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){

            if(result==NULL){
                n_result+=1;
                result=(char**)calloc(sizeof(char*),n_result);
                results_count=(int*)calloc(sizeof(int*),n_result);
                result[(n_result)-1]=(char*)calloc(sizeof(char),50);
                
                strcpy(result[n_result-1],matrix[row][col]);
                results_count[n_result-1]=1;
                continue;
            }
            
            int is_present=0;
            for(int result_index=0;result_index<n_result;result_index++){
                if(strcmp(result[result_index],matrix[row][col])==0){
                    results_count[result_index]++;
                    is_present=1;
                }
            }
            if(!is_present){
                n_result++;
                    result=(char**)realloc(result,sizeof(char*)*(n_result));
                    results_count=(int*)realloc(results_count,sizeof(int)*(n_result));
                    result[(n_result)-1]=(char*)calloc(sizeof(char),50);
                    
                    strcpy(result[n_result-1],matrix[row][col]);
                    results_count[n_result-1]=1;
            }
            
        }
    }
    
    printf("\nResult:\n");

    int no_duplicate=0;
    for(int index=0;index<n_result;index++){
        if(results_count[index]>1){
            printf("%s - %d\n",result[index],results_count[index]);
            no_duplicate=1;
        }
    }
    if(no_duplicate==0){
        printf("No Duplicate Found");
    }

    return 0;
}