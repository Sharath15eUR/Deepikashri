#include<stdio.h>
int swap(int *a,int *b)
{
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}
int main()
{
    int n,m;
    printf("Enter two numbers: \n");
    scanf("%d %d",&n,&m);
    int (*ptr)(int*,int*)=&swap;
    ptr(&n,&m);
    printf("%d %d",n,m);
    return 0;
}