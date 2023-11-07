/*Checking whether a string is palindrome or not using stack*/
#include <stdio.h>
#define size 25
int s[size],top=-1;
void push(char c)
{
    top=top+1;
    s[top]=c;
}
char pop()
{
    char c;
    {
        c=s[top];
        top=top-1;
        return c;
    }
}
void main()
{
    char str[25];
    int i,len,count=0;
    printf("Enter a string : ");
    scanf("%[^\n]",&str);
    for (i=0;str[i]!='\0';i++)
    {
        len=i;
        push(str[i]);
    }
    for (i=0;i<len;i++)
    {
        if (str[i]==pop())
        {
            count++;
        } 
    }
    if (count==len)
    {
        printf("%s is a PALINDROME\n",str);
    }
    else
    {
        printf("%s is NOT PALINDROME\n");
    }
}