#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

bool isOperator(char character){
    return(character=='+' || character=='*' || character=='/' || character=='-');
}

int getPrecedence(char operator){
    if(operator=='/')
        return 4;
    else if(operator=='*')
        return 3;
    else if(operator=='+')
        return 2;
    else
        return 1;
}

int calculate(int value1,int value2,char operator){
    int tempResult=0;
    if(operator=='+'){
        tempResult=value1+value2;
    }
    else if(operator=='-'){
        tempResult=value1-value2;
    }
    else if(operator=='/'){
        if(value2==0){
            printf("Error: Division by zero.\n");
            exit(1);
        }
        tempResult=value1/value2;
    }
    else if(operator=='*'){
        tempResult=value1*value2;
    }
    return tempResult;
}

int evaluate(char expression[100]){
    int result=0;
    int valueStack[100];
    char operatorStack[100];
    int topValueStack=-1;
    int topOperatorStack=-1;
    int value=0;
    bool startNegative=false,inputOperator=false;

    if(expression[0]=='-')
        startNegative=true;

    for(int i=0;i<strlen(expression);i++){
        if(startNegative && i==0)
            continue;

        if((int)expression[i]>=48 && (int)expression[i]<=57){
            if(startNegative && i==1){
                value=(int)expression[i]-48;
                value*=-1;
            }
            else
                value=value*10+((int)expression[i]-48);

            inputOperator=true;
        }
        else if(isOperator(expression[i])){
            if(!inputOperator){
                printf("Error: Invalid string\n");
                exit(1);
            }

            valueStack[++topValueStack]=value;
            value=0;

            if(topOperatorStack==-1 || (getPrecedence(operatorStack[topOperatorStack]) < getPrecedence(expression[i]) )){
                operatorStack[++topOperatorStack]=expression[i]; 
            }
            else{
                int value2=valueStack[topValueStack--];
                int value1=valueStack[topValueStack--];
                char operator=operatorStack[topOperatorStack--];
                valueStack[++topValueStack]=calculate(value1,value2,operator);
                operatorStack[++topOperatorStack]=expression[i];
            }
            inputOperator=false;
        }
        else if(expression[i]==' ' || expression[i]=='\n'){
            continue;
        }
        else{
            printf("Error: Invalid expression\n");
            exit(1);
        }
    }

    valueStack[++topValueStack]=value;
    while(topOperatorStack!=-1 && topValueStack!=0){
        int value2=valueStack[topValueStack--];
        int value1=valueStack[topValueStack--];
        char operator=operatorStack[topOperatorStack--];
        valueStack[++topValueStack]=calculate(value1,value2,operator);
    }
    result=valueStack[topValueStack];
    return result;
}

void main(){
    printf("Calculator\n");
    printf("Provide the mathematical expression for evaluation-\n");
    char expression[100];
    fgets(expression, sizeof(expression), stdin);
    int result=evaluate(expression);
    printf("Result:%d",result);
}