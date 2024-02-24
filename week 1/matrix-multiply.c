#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,r,k,c,r1,c1,a[10][10],b[10][10],sum[5][5];
    printf("Enter the number of rows and columns for array 1: \n");
    scanf("%d %d",&r,&c);
    printf("Enter the number of rows and columns for array 2: \n");
    scanf("%d %d",&r1,&c1);
    printf("Enter the elements for the array 1 \n");
    
    if(c==r1)
    {
        
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements for the array 2 \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            sum[i][j]=0;
            for(k=0;k<r;k++)
            {
            sum[i][j]+=*(*(a+i)+k) *  *(*(b+k)+j);
        }
        }
    }
    printf("The result is: \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }

    }   
    else {
        exit(1);
    }
}

