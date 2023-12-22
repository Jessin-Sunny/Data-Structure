/*Quick Sort*/
#include <stdio.h>
void QuickSort(int arr[],int low,int high)
{
    int pivot,i,j,temp;
    if(low >= high)
    {
        return;
    }
    pivot=arr[low];
    i=low+1;
    j=high;
    while(i<=j)
    {
        while(arr[i] < pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        //interchange arr[i] and arr[j]
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    //interchange pivot and arr[j] and make first element of arr as arr[j]
    temp=arr[j];
    arr[j]=pivot;
    arr[low]=temp;
    QuickSort(arr,low,j-1); //sorting elements at the left side
    QuickSort(arr,j+1,high);    //sorting elements at the right side
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
    QuickSort(arr,0,n-1);
    printf("After Sorting : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}