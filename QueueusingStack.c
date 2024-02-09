/*
Program for implementing Queue using stack
->Queue is FIFO data structure
->Stack is LIFO data structure
->Two stacks s1 and s2 are used
->s1 enqueus elements and on pop operation on s1 and push it to s2 dequeue can be done on pop operation on s2
*/

#include <stdio.h>
#define size 25
#define invalid -9999

int s1[size],s2[size],top1=-1,top2=-1;

void push1(int data)
{
    if(top1==size-1)
    {
        printf("Stack1 Overflow\n");
    }
    else
    {
        top1++;
        s1[top1]=data;
    }
}

void push2(int data)
{
    if(top2==size-1)
    {
        printf("Stack1 Overflow\n");
    }
    else
    {
        top2++;
        s2[top2]=data;
    }
}

int pop1()
{
    int data;
    if(top1==-1)
    {
        printf("Stack Empty\n");
        return invalid;
    }
    else
    {
        data=s1[top1];
        top1--;
        return data;
    }
}

int pop2()
{
    int data;
    if(top2==-1)
    {
        printf("Stack Empty\n");
        return invalid;
    }
    else
    {
        data=s2[top2];
        top2--;
        return data;
    }
}

void enqueue()
{
    int data;
    printf("Enter the element : ");
    scanf("%d",&data);
    push1(data);
}

int dequeue()
{
    int data;
    while(top1!=-1)
    {
        push2(pop1());
    }
    data=pop2();
    return data;
}

void display()
{
    printf("Queue Elements : ");
    for(int i=0;i<=top1;i++)
    {
        printf("%d ",s1[i]);
    }
    printf("\n");
}

void main()
{
    char ch='y';
    int value;
    printf("1 : Enqueue\n");
    printf("2 : Dequeue\n");
    printf("3 : Display\n");
    printf("4 : Exit\n");
    while(ch=='y' || ch=='Y')
    {
        printf("Enter your choice : ");
        scanf("%d",&value);
        switch(value)
        {
            case 1: enqueue();
                    break;
            case 2: printf("Element dequeued : %d\n",dequeue());
                    break;
            case 3: display();
                    break;
            case 4: ch='N';
                    break;
            default: printf("Invalid Choice\n");
        }
    }
}