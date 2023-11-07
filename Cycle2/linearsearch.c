/*
Ex No1
Linear Search
Jessin Sunny
S3 CSE
38
*/

#include <stdio.h>
void main()
{
    int n,i,sno,a[10],p=0;
    printf("How many elements ? : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number to be searched : ");
    scanf("%d",&sno);
    for (i=0;i<n;i++)
    {
        if (sno==a[i])
        {
            printf("%d is PRESENT at location %d\n",sno,i+1);
            p=1;
            break;
        }
    }
    if (!p)
    {
        printf("%d NOT PRESENT\n",sno);
    }
}