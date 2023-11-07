/*Implementing QUEUE using stack*/
#include <stdio.h>
#define size 25
int queue[size],front=-1,rear=-1;
void Enqueue(int item)
{
    if (rear==size-1)
    {
        printf("Queue Full\n");
    }
    else
    {
        if (front==-1)
        {
            front=0;
        }
        rear=rear+1;
        queue[rear]=item;
    }
}
int Dequeue()
{
    int item;
    if (front==-1)
    {
        printf("Queue Empty\n");
    }
    else
    {
        item=queue[front];
        front=front+1;
        if (front==rear+1)
        {
            front=rear=-1;
        }
        return item;
    }
}
void display()
{
    int i;
    if (front==-1)
    {
        printf("Empty Queue\n");
    }
    else
    {
        for (i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

void main()
{
    int val,item;
    char ch='y';
    while (ch=='y'||ch=='Y')
    {
        printf("1 : ENQUEUE\n2 : DEQUEUE\n3 : DISPLAY\n");
        printf("Enter your choice : ");
        scanf("%d",&val);
        switch(val)
        {
            case 1: printf("Enter the element to be inserted : ");
                    scanf("%d",&item);
                    Enqueue(item);
                    break;

            case 2: printf("%d\n",Dequeue());
                    break;
        
            case 3: printf("Queue Elements are : ");
                    display();
                    break;

            default : printf("Invalid Choice!!\n");
        }
        printf("Do you want to continue ?(y/n) : ");
        scanf(" %c",&ch);
    }
}