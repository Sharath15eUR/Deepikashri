#include<stdio.h>
int main()
{
    int count=0,n;
    printf("Enter a number: \n");
    scanf("%d",&n);
    while(n!=0)
    {
        if(n&1)
           count++;
        n=n>>1;
    }
    printf("The number of set bits: %d",count);
    return 0;
}