#include<stdio.h>
#include<string.h>
#include <stdbool.h>
bool error=false;//to check if nay error encountered
bool isOperator(char character){//function to check for an operator
    if(character=='+' || character=='*' || character=='/' || character=='-'){
        return true;
    }
    return false;
}
int precedence(char operator){//to check precedence of the operator
    if(operator=='/')
        return 4;
    else if(operator=='*')
        return 3;
    else if(operator=='+')
        return 2;
    else
        return 1;
}
int calculate(int value1,int value2,char operator){//to calculate the expression
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
            error=true;
            return 0;
        }
        tempResult=value1/value2;
    }
    else if(operator=='*'){
        tempResult=value1*value2;
    }
    return tempResult;
}

int evaluate(char expression[100]){//to evaluate complete expression
    int result=0;//by default result is zero
    int valueStack[100];
    char operatorStack[100];
    int topValueStack=-1;
    int topOperatorStack=-1;
    int value=0;
    bool startNegative=false;
    if(expression[0]=='-')//to check weather the first value is negative or not
        startNegative=true;

    for(int i=0;i<strlen(expression);i++){
        if(startNegative && i==0)//neglecting first element if startNegative is true
            continue;

        if((int)expression[i]>=48 && (int)expression[i]<=57){
            if(startNegative && i==1){
                value=(int)expression[i]-48;
                value*=-1;//converting first value to negative if startNegative is true
            }
            else
                value=value*10+((int)expression[i]-48);//for taking complete value between two operators
        }
        else if(isOperator(expression[i])){
            valueStack[++topValueStack]=value;//adding current value to the stack
            value=0;//again setting value=0 so that next value can be taken

            if(topOperatorStack==-1 || (precedence(operatorStack[topOperatorStack]) < precedence(expression[i]) )){ //high precedence operator can be add on the top of the stack
                operatorStack[++topOperatorStack]=expression[i];//adding current operator to operator stack
            }
            else{//if low precedence operator comes over the high precedence operator then pop last two values and insert them again into the values stack by the poped operator than insert the new operator
                int value2=valueStack[topValueStack--];
                int value1=valueStack[topValueStack--];
                char operator=operatorStack[topOperatorStack--];
                valueStack[++topValueStack]=calculate(value1,value2,operator);
                operatorStack[++topOperatorStack]=expression[i];
            }
        }
        else if(expression[i]=' '){
            continue;
        }
        else{
            printf("Error: Invalid expression\n");
            error=true;
            return result;
        }
    }
    valueStack[++topValueStack]=value;//adding the last encountered value
    while(topOperatorStack!=-1 && topValueStack!=0){//after adding all the values and operators to the stack, now evaluating every last two element of the valueStack and evaluating with the last operator and again pushing to the valueStack
        int value2=valueStack[topValueStack--];
        int value1=valueStack[topValueStack--];
        char operator=operatorStack[topOperatorStack--];
        valueStack[++topValueStack]=calculate(value1,value2,operator);
    }
    result=valueStack[topValueStack];//last left element is the final result
    return result;
}
void main(){
    printf("Calculator\n");
    printf("Provide the mathematical expression for evaluation-\n");
    char expression[100];//expression string roughly size of 100
    gets(expression);

    int result=evaluate(expression);
    if(!error)//if no error is present then print result
        printf("Result:%d",result);
}