#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: \n");
    scanf("%d",&n);
    (n&1)?printf("It is an odd number"):printf("It is an even numnber");
    return 0;
}