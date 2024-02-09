/*
Program for reversing the contents of the queue using stack
-> Dequeue element by element of queue and Push all the elements onto the stack
-> Then do pop operation on stack and enqueue it queue
-> This will be in reversed order 
*/

#include <stdio.h>
#define size 25
#define invalid -9999

int s[size],top=-1;
int queue[size],front=-1,rear=-1;

void push(int item)
{
    if (top==size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        s[top]=item;
    }
}
int pop()
{
    int item;
    if (top==-1)
    {
        printf("Stack Underflow\n");
        return invalid;
    }
    else
    {
        item=s[top];
        top--;
        return item;
    }
}

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

void reverse()
{
    while(front!=-1)
    {
        push(Dequeue());
    }
    while(top!=-1)
    {
        Enqueue(pop());
    }

    printf("After Reversal : ");
    display();
}

void main()
{
    int value,item;
    char ch='y';
    printf("1 : ENQUEUE\n2 : DEQUEUE\n3 : DISPLAY\n4 : REVERSE\n5 : EXIT\n");
    while (ch=='y'||ch=='Y')
    {
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
        
            case 3: printf("Queue Elements are : ");
                    display();
                    break;

            case 4: printf("Queue Elements are : ");
                    display();
                    reverse();
                    break;
            
            case 5: ch='N';
                    break;

            default : printf("Invalid Choice!!\n");
        }
    }
}
