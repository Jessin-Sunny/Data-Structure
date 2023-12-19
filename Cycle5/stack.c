/*Implementing stack using linked list*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* top=NULL;

void push(int item)
{
    struct node* new;
    new=malloc(sizeof(struct node));
    new->data=item;
    new->link=top;
    top=new;
}

int pop()
{
    struct node* temp;
    int item;
    temp=top;
    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return -9999;
    }
    item=temp->data;
    top=top->link;
    free(temp);
    return item;
}

void display()
{
    struct node* ptr;
    ptr=top;
    if(top==NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        while(ptr->link!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->link;
        }
    }
}

void main()
{
    int value,item;
    char ch='y';
    struct node* head;
    head=malloc(sizeof(struct node));
    top=malloc(sizeof(struct node));
    head->link=top;
    top->link=NULL;
    while(ch=='y'||ch=='Y')
    {
        printf("1 : PUSH\n2 : POP\n3 : DISPLAY\n");
        printf("Enter your choice : ");
        scanf("%d",&value);
        switch(value)
        {
            case 1: printf("Enter the element to be inserted : ");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2: item=pop();
                    if(item!=-9999)
                    {
                        printf("Element deleted is %d\n",item);
                    }
                    break;
            case 3: display();
                    break;
            default : printf("Invalid Choice\n");
        }
        printf("Do you want to continue ?(y/n) :  ");
        scanf(" %c",&ch);
    }
}