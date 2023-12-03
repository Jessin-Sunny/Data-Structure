/*Converting an infix expression to prefix expression using stack*/
#include <stdio.h>
#include <string.h>
#define size 25

int top=-1;
char s[size];

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
    char item;
    item=s[top];
    top--;
    return item;
}

void reverse(char* str1,char* str2)
{
    int l,i=0;
    l=strlen(str1)-1;
    while(str1[i]!='\0')
    {
        str2[i++]=str1[l--];
    }
    str2[i]='\0';
}

int isOperator(char c)
{
    return(c=='+' || c=='-' || c=='*' || c=='/');
}

int precedence(char c)
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
    return 0;
}

void infixtoprefix(char* infix,char* prefix)
{
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(infix[i]==')')
        {
            push(infix[i]);
        }
        else if(infix[i]=='(')
        {
            while(top!=-1 && s[top]!=')')
            {
                prefix[j++]=pop();
            }
            if(top!=-1)     //removing ( from stack
            {
                pop();
            }
        }
        else if(isOperator(infix[i]))
        {
            while(top!=-1 && precedence(s[top])>=precedence(infix[i]))
            {
                prefix[j++]=pop();
            }
            push(infix[i]);
        }
        else        //operand
        {
            prefix[j++]=infix[i];
        }
        i++;
    }
    while(top!=-1)      //remaining elements from stack
    {
        prefix[j++]=s[top--];
    }
    prefix[j++]='\0';
}

void main()
{
    char infix[size],temp1[size],prefix[size],temp2[size];
    printf("Enter the infix expression : ");
    scanf("%[^\n]",temp1);
    reverse(temp1,infix);
    infixtoprefix(infix,prefix);
    reverse(prefix,temp2);
    printf("The Prefix expression : %s\n",temp2);
}
