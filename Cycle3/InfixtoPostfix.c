/*
Program for coverting an infix expression to postfix expression using stack
->Before starting operation append the string with ')' and push stack with '('
->Where ever pop operation done always check top!=-1 condition
*/

#include <stdio.h>
#include <string.h>
#define size 1000

char s[size];
int top=-1;

void push(char c)
{
    if(top==size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        s[top]=c;
    }
}

char pop()
{
    char c;
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return '0'; //indicating null value
    }
    else
    {
        c=s[top];
        top--;
        return c;
    }
}

/*function for operator priority*/
int priority(char c)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

char isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^') 
    {
        return c;
    }
    else
    {
        return '.';     //others
    }
}

void infixtopostfix(char infix[],char postfix[])
{
    int i=0,j=0;
    char x;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(top!=-1 && (x=pop())!='(')
            {
                postfix[j]=x;
                j++;
            }
        }
        else if(infix[i]==isOperator(infix[i])) //corrected area
        {
            while(top!=-1 && (priority(infix[i]) <= priority(s[top])))
            {
                postfix[j]=pop();
                j++;
            }
            push(infix[i]);
        }
        else
        {
            postfix[j]=infix[i];
            j++;
        }
        i++;
    }
    postfix[j]='\0';
}

void evalpostfix(char postfix[])
{

}
void main()
{
    char infix[size],postfix[size]; 
    int l;
    printf("Enter the infix epression : ");
    scanf("%[^\n]",infix);
    printf("Infix Expression : %s\n",infix);
    l=strlen(infix);
    infix[l]=')';
    infix[l+1]='\0';
    push('(');
    infixtopostfix(infix,postfix);
    printf("Postfix Expression : %s",postfix);
}