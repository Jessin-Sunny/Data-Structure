/*Function for selection sort*/
#include <stdio.h>

void Selection_Sort(int arr[25],int n)
{
    int i,j,minIndex,temp;
    for(i=0;i<n-1;i++)
    {
        minIndex=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex=j;
            }
        }
        if(minIndex!=i)
        {
            temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
}

void main()
{
    int n,arr[25];
    printf("How many elements in array ? : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Selection_Sort(arr,n);
    printf("After Sorting : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
