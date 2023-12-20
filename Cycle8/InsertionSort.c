#include <stdio.h>

void Insetion_Sort(int arr[],int n)
{
    int j,key;
    for(int i=1;i<n;i++)
    {
        //key
        //storing element from unsorted array to check with sorting array for swap or not
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)    //inside sorted array and key is smaller
        {
            arr[j+1]=arr[j];    //moving element from sorted array towards right
            j=j-1;              //for checking with other elements in the sorted array
        }
        arr[j+1]=key;
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
    Insetion_Sort(arr,n);
    printf("After Sorting : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}