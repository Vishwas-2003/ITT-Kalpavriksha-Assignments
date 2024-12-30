#include<stdio.h>
int calculateMod(int a,int b,int c){
    int result=1;
    a=a%c;
    while(b>0){
        if(b%2==1) 
            result=(result*a)%c;
        a=(a*a)%c;
        b=b/2;
    }
    return result;
}
void main(){
    int a,b,c;
    printf("Enter the value of a,b,c:");
    scanf("%d%d%d",&a,&b,&c);
    printf("Result of (a^b)mod c:%d",calculateMod(a,b,c));
}