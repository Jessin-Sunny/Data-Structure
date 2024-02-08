/*
Reversing a number using linked list stack
1)Defining Stack as linked list
2)Each Node as structure
3)Two stacks are used
4)First stack(topn) and second stack(topr)
5)Two top pointers are declared globally and assigned NULL
6)Flag is used to identify which stack top pointer is to be updated
7)Flag=1 updates first stack and Flag=2 updates second stack
8)From the last digit onwards push operation is done onto first stack
9)First stack inserts digits in correct order O(1)
10)Pop operation on the first stack is pushed onto the second stack
11)Pop operation on second stack will give elements in reverse order
*/

#include <stdio.h>
#include <stdlib.h>
#define invalid -999

struct node
{
    int digit;
    struct node* link;
};

struct node* topn=NULL,*topr=NULL;

void push(int digit,struct node* top,int flag)
{
    struct node* new;
    new=malloc(sizeof(struct node));
    new->digit=digit;
    if(top==NULL)
    {
        new->link=NULL;
    }
    else
    {
        new->link=top;
    }
    if(flag==1)
    {
        topn=new;
    }
    else if(flag==2)
    {
        topr=new;
    }
}

int pop(struct node* top,int flag)
{
    int d;
    if(top==NULL)
    {
        return invalid;
    }
    else
    {
        d=top->digit;
        if(flag==1)
        {
            topn=topn->link;
        }
        else if(flag ==2)
        {
            topr=topr->link;
        }
        return d;
    }
}

void main()
{
    int num,tnum;
    printf("Enter a number : ");
    scanf("%d",&num);
    tnum=num;
    while(tnum)
    {
        push(tnum%10,topn,1);
        tnum=tnum/10;
    }

    while(topn!=NULL)
    {
        push(pop(topn,1),topr,2);
    }
    printf("Reverse of %d is : ",num);
    while(topr!=NULL)
    {
        printf("%d",pop(topr,2));
    }
}
