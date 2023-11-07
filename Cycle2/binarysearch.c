/*Binary Search*/
#include <stdio.h>
void main()
{
    int i,j,n,a[20],temp,top,bottom,mid,sno;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("After Sorting :  ");
    for (i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    printf("Enter the number to be searched : ");
    scanf("%d",&sno);
    top=0;
    bottom=n-1;
    mid=(top+bottom)/2;
    while (top<=bottom)
    {
        if (sno==a[mid])
        {
            printf("%d is PRESENT at %d\n",sno,mid+1);
            break;
        }
        if (sno<a[mid])
        {
            bottom=mid-1;
            mid=(top+bottom)/2;
        }
        if (sno>a[mid])
        {
            top=mid+1;
            mid=(top+bottom)/2;
        }
    }
    if (top>bottom)
    {
        printf("%d is NOT PRESENT\n",sno);
    }
}