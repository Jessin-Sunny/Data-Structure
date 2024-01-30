/*Program for finding the second smallest element in an array*/

public class SecondSmallest 
{
    public static void main(String args[])
    {
        int arr[]={300,210,100,250,200};
        int small,secsmall;
        small=secsmall=arr[0];
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]<secsmall && arr[i]>small)
            {
                secsmall=arr[i];
            }
            else if(arr[i]<small)
            {
                small=arr[i];
            }
        }
        System.out.println("Smallest Element : "+small);
        System.out.println("Second Smallest Element : "+secsmall);
    }
}
