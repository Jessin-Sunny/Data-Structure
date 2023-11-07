/*Implenting Stack using Array*/
#include <stdio.h>
#define size 2
#define invalid -9999
int s[size],top=-1;
void push(int item)
{
    if (top==size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top=top+1;
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
        top=top-1;
        return item;
    }
}
void display()
{
    int i;
    for (i=0;i<=top;i++)
    {
        printf("%d\n",s[i]);
    }
}
void main()
{
    int val,item;
    char ch='y';
    while (ch=='y'||ch=='Y')
    {
        printf("1 : PUSH\n2 : POP\n3 : DISPLAY\n");
        printf("Enter your choice : ");
        scanf("%d",&val);
        switch(val)
        {
            case 1: printf("Enter the element to be inserted : ");
                    scanf("%d",&item);
                    push(item);
                    break;

            case 2: printf("%d\n",pop());
                    break;
        
            case 3: printf("Stack Elements are : \n");
                    display();
                    break;

            default : printf("Invalid Choice!!\n");
        }
        printf("Do you want to continue ?(y/n) : ");
        scanf(" %c",&ch);
    }

    
}