/*
Program for coverting an infix expression to prefix expression using stack
->Logic is somewhat similar to conversion from infix to postfix but we need 
  to give the reversed infix expression
->Before starting operation, there is no need to append the string with '(' and push stack with ')'
->Where ever pop operation done always check top!=-1 condition
->Finally we need to reverse the expression obtained for getting prefix expression
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

void infixtoprefix(char revinfix[],char prefix[])
{
    int i=0,j=0;
    char x;
    while(revinfix[i]!='\0')
    {
        if(revinfix[i]==')')
        {
            push(revinfix[i]);
        }
        else if(revinfix[i]=='(')
        {
            while(top!=-1 && (x=pop())!=')')
            {
                prefix[j]=x;
                j++;
            }
        }
        else if(revinfix[i]==isOperator(revinfix[i])) //corrected area
        {
            while(top!=-1 && (priority(revinfix[i]) <= priority(s[top])))
            {
                prefix[j]=pop();
                j++;
            }
            push(revinfix[i]);
        }
        else
        {
            prefix[j]=revinfix[i];
            j++;
        }
        i++;
    }

    //remaining elements in stack
    while(top!=-1)
    {
        prefix[j]=pop();
        j++;
    }
    prefix[j]='\0';
}

void reverse(char str1[],char str2[])
{
    int len,i=0;
    int r;
    len=strlen(str1);
    r=len-1;
    while(str1[i]!='\0')
    {
        str2[i]=str1[r];
        i++;
        r--;
    }
    str2[i]='\0';
}
void main()
{
    char infix[size],revinfix[size],prefix[size],revprefix[size]; 
    int l,e,i=0;
    printf("Enter the infix epression : ");
    scanf("%[^\n]",infix);
    printf("Infix Expression : %s\n",infix);
    reverse(infix,revinfix);
    //printf("Reversed Infix Expression : %s\n",revinfix);
    infixtoprefix(revinfix,prefix);
    reverse(prefix,revprefix);
    printf("Prefix Expression : %s",revprefix);
}