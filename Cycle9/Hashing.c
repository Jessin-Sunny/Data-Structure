/*Program for implementing Hash Table and using linear probing for collision resolution*/
// Hash function f(x)=key%size

#include <stdio.h>
#define size 10
#define initial -999
int htable[size];

void initialize()
{
    for(int i=0;i<size;i++)
    {
        htable[i]=initial;
    }
}

void insert(int key)
{
    int hkey,index;
    hkey=key%size;
    for(int i=0;i<size;i++)
    {
        index=(hkey+i)%size;
        if(htable[index]==initial)
        {
            htable[index]=key;
            break;
        }
        if(index==size-1)
        {
            printf("%d cannot be inserted\n",key);
        }
    }
}

void display()
{
    printf("Hash Table\n");
    for(int i=0;i<size;i++)
    {
        if(htable[i]==initial)
        {
            printf(" \n");
        }
        else
        {
            printf("%d\n",htable[i]);
        }
        printf("-----------\n");
    }
}

void main()
{
    int key;
    char ch='y';
    initialize();
    while (ch == 'y' || ch == 'Y')
    {
        printf("Enter the element to be inserted : ");
        scanf("%d", &key);
        insert(key);
        printf("Do you want to enter more elements(y/n) : ");
        scanf(" %c",&ch);
    }

    display();
}