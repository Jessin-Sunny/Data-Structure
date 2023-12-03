/*Converting an infix expression to prefix expression using stack*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define size 25

int top=-1;
char s[size];

void push(int c)
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

int pop()
{
    int item;
    item=s[top];
    top--;
    return item;
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

void infixtopostfix(char* infix,char* postfix)
{
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(top!=-1 && s[top]!='(')
            {
                postfix[j++]=pop();
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
                postfix[j++]=pop();
            }
            push(infix[i]);
        }
        else        //operand
        {
            postfix[j++]=infix[i];
        }
        i++;
    }
    while(top!=-1)      //remaining elements from stack
    {
        postfix[j++]=s[top--];
    }
    postfix[j++]='\0';
}

int post_eval(char* postfix)
{
    int i,a,b;
    for (i=0;i<strlen(postfix);i++)
    {

        if (postfix[i]>='0' && postfix[i]<='9')
        {
            //printf("%d\n",postfix[i]-'0');
            push(postfix[i]-'0');
        }
        else
        {
            a=pop();
            b=pop();
            //printf("%d\n%d\n",a,b);
            switch (postfix[i])
            {
                case '+':
                    push(b+a);
                    break;
                case '-':
                    push(b-a);
                    break;
                case '*':
                    push(b*a);
                    break;
                case '/':
                    push(b/a);
                    break;
                case '^':
                    push(pow(b,a));
                    break;
            }
        }
    }
    return pop();
}

void main()
{
    char infix[size],postfix[size];
    printf("Enter the infix expression : ");
    scanf("%[^\n]",infix);
    infixtopostfix(infix,postfix);
    printf("The Postfix expression : %s\n",postfix);
    printf("The Result : %d\n",post_eval(postfix));
}