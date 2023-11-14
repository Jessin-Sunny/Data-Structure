#include <stdio.h>
#define size 25
int front=-1,rear=-1;
struct PQ
{
    int item,priority;
}pq[size];
void Enqueue(int ITEM,int PRIORITY)
{
    int i,loc;
    if(front==0 && rear==size-1)
    {
        printf("Priority Queue Full\n");
    }
    else if(front==-1)
    {
        front=0;
        rear=0;
        pq[rear].item=ITEM;
        pq[rear].priority=PRIORITY;
    }
    else
    {
        if(rear==size-1)
        {
            for(i=front;i<=rear;i++)    //shifting towards left
            {
                pq[i-1]=pq[i];
            }
            front--;                    //front and rear decremented after shifting
            rear--;
        }
        for(i=rear;i>=front;i--)    //for getting the location where element to be added
        {
            if(pq[i].priority<PRIORITY)
            {
                break;
            }
        }
        loc=i+1;
        for(i=rear;i>=loc;i--)  //for making p[loc] free
        {
            pq[i+1]=pq[i];
        }
        pq[loc].item=ITEM;
        pq[loc].priority=PRIORITY;
        rear++;
    }   
}
void Dequeue()
{
    if(front==-1)
    {
        printf("Priority Queue Empty\n");
    }
    else if(front==rear)
    {
        printf("Element Removed : %d\n",pq[front].item);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("Element Removed : %d\n",pq[front].item);
        front++;
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("Priority Queue Empty\n");
    }
    else
    {
        printf("Elements in Priority Queue : ");
        for(i=front;i<=rear;i++)
        {
            printf("%d ",pq[i].item);
        }
        printf("\n");
    }
}


void main()
{
    int value,item,prio;
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
                    printf("Enter its priority : ");
                    scanf("%d",&prio);
                    Enqueue(item,prio);
                    break;

            case 2: Dequeue();
                    break;
        
            case 3: display();
                    break;

            default : printf("Invalid Choice!!\n");
        }
        printf("Do you want to continue ?(y/n) : ");
        scanf(" %c",&ch);
    }
}
