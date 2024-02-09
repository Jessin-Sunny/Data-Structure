/*Program for implementing Double Ended Queue using Circular Arrays*/

#include <stdio.h>
#define N 5
#define invalid -9999

int dq[N],f=-1,r=-1;

void insertFront(int data)
{
    /*Checking the queue full condition*/
    if((f==0 && r==N-1) || (f==r+1))
    {
        printf("Queue Full\n");
    }
    else if(f==-1 && r==-1)     //queue is initially empty
    {
        f=0;r=0;
        dq[f]=data;
    }
    else if(f==0)               //[10(f),20,50(r),__,__]
    {
        f=N-1;
        dq[f]=data;
    }
    else
    {
        f--;
        dq[f]=data;
    }
}

void insertRear(int data)
{
    /*Checking the queue full condition*/
    if((f==0 && r==N-1) || (f==r+1))
    {
        printf("Queue Full\n");
    }
    else if(f==-1 && r==-1)     //queue is initially empty
    {
        f=0;r=0;
        dq[r]=data;
    }
    else if(r==N-1)             //[__,__,11(f),21,37(r)]
    {
        r=0;
        dq[r]=data;
    }
    else
    {
        r++;
        dq[r]=data;
    }
}

int remFront()
{
    int data;
    /*Checking whether the queue is Empty*/
    if(f==-1 && r==-1)
    {
        printf("Queue is Empty\n");
        return invalid;
    }
    else if(f==r)           //only single element left
    {
        data=dq[f];
        f=r=-1;
    }
    else if(f==N-1)           //[10(f),21,37,54,98(r)]
    {
        data=dq[f];
        f=0;
    }
    else
    {
        data=dq[f];
        f++;
    }
    return data;
}

int remRear()
{
    int data;
    /*Checking whether the queue is Empty*/
    if(f==-1 && r==-1)
    {
        printf("Queue is Empty\n");
        return invalid;
    }
    else if(f==r)           //only single element left
    {
        data=dq[r];
        f=r=-1;
    }
    else if(r==0)         //[10,74,14,5(f),11(r)]
    {
        data=dq[r];
        r=N-1;
    }
    else
    {
        data=dq[r];
        r--;
    }
    return data;
}

void display()
{
    if(f==-1 && r==-1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int i=f;
        while(i!=r)                 //circular when i reaches N-1 it should go to 0 till finding rear
        {
            printf("%d ",dq[i]);
            i=(i+1)%N;          
        }
        printf("%d\n",dq[r]);     //rear is not printed
    }
}

void main()
{
    int value,item;
    char ch='y';
    printf("1 : ENQUEUE through Front\n2 : ENQUEUE through Rear\n3 : DEQUEUE through Front\n4 : DEQUEUE through Rear\n5 : DISPLAY\n6 : EXIT\n");
    while (ch=='y'||ch=='Y')
    {
        printf("Enter your choice : ");
        scanf("%d",&value);
        switch(value)
        {
            case 1: printf("Enter the element to be inserted : ");
                    scanf("%d",&item);
                    insertFront(item);
                    break;
            case 2: printf("Enter the element to be inserted : ");
                    scanf("%d",&item);
                    insertRear(item);
                    break;
            case 3: printf("Element dequed : %d\n",remFront());
                    break;
            case 4: printf("Element dequed : %d\n",remRear());
                    break;
            case 5: display();
                    break;
            case 6: ch='N';
                    break;

            default : printf("Invalid Choice!!\n");
        }
    }
}