/*
Implement a Circular Queue using arrays with the operations:
 a.Insert elements into the queue
 b.Delete elements from the queue
 c.Display the contents of the queue after each operation
*/
#include <stdio.h>
#define size 3
#define invalid -999
int rear=-1,front=-1,cqueue[size];
void Enqueue(int item)
{
    if (front==(rear+1)%size)
    {
        printf("Queue Full\n");
    }
    else
    {
        if (front==-1)
        {
            front=0;
        }
        rear=(rear+1)%size;
        cqueue[rear]=item;
    }
}
int Dequeue()
{
    int item;
    if (front==-1)
    {
        printf("Queue is Empty\n");
        return invalid;
    }
    else
    {
        item=cqueue[front];
        front=(front+1)%size;
        if (front==(rear+1)%size)
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
        printf("Queue is Empty\n");
    }
    else if (front<=rear)
    {
        for (i=front;i<=rear;i++)
        {
            printf("%d ",cqueue[i]);
        }
    }
    else
    {
        for (i=front;i<size;i++)
        {
            printf("%d ",cqueue[i]);
        }
        for (i=0;i<=rear;i++)
        {
            printf("%d ",cqueue[i]);
        }
    }
}
void main()
{
    int value,item;
    char ch='y';
    while (ch=='y'||ch=='Y')
    {
        printf("1 : ENQUEUE\n2 : DEQUEUE\n3 : DISPLAY\n");
        printf("Enter your choice : ");
        scanf("%d",&value);
        switch(value)
        {
            case 1: printf("Enter the element to be inserted : ");
                    scanf("%d",&item);
                    Enqueue(item);
                    break;
            case 2: printf("%d\n",Dequeue());
                    break;
            case 3: display();
                    printf("\n");
                    break;
            default : printf("Invalid Choice!!!\n");
        }
        printf("Do you want to continue ?(y/n) : ");
        scanf(" %c",&ch);
    }
}