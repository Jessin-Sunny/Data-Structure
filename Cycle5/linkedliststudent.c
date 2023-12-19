/*
The details of students (number, name and total mark) are to be stored in a linked list. Write functions for 
the following operations. 
1. Insert (at the beginning)
2. Delete (based on number)
3. Search (based on name or number)
4. Sort on the basis of number
5. Display
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int num;
    char name[25];
    float marks;
    struct node* link;
};

void insert(struct node* head,int num,char name[],float marks)
{
    struct node* new;
    new=malloc(sizeof(struct node));
    new->num=num;
    strcpy(new->name,name);
    new->marks=marks;
    new->link=head->link;
    head->link=new;
}

void delete(struct node* head,int num)
{
    struct node* ptr,*prev;
    ptr=head;
    if(ptr->link==NULL)
    {
        printf("List Empty\n");
    }
    else
    {
        while(ptr->link!=NULL)
        {
            prev=ptr;
            ptr=ptr->link;
            if(ptr->num==num)
            {
                break;
            }
        }
        if(ptr->num!=num)
        {
            printf("Student NOT FOUND\n");
        }
        else
        {
            prev->link=ptr->link;
            free(ptr);
            printf("Student with number %d is DELETED\n",num);
        }
    }
}

void search(struct node* head,int num)
{
    struct node* ptr;
    ptr=head->link;
    if(ptr==NULL)
    {
        printf("List Empty\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->num==num)
            {
                break;
            }
            ptr=ptr->link;
        }
        if(ptr==NULL)
        {
            printf("Student NOT FOUND\n");
        }
        else
        {
            printf("Student with number %d is PRESENT\n",num);
            printf("NUMBER\tNAME\tMARKS\n");
            printf("%d\t%s\t%f\n",ptr->num,ptr->name,ptr->marks);
        }
    }
}

void sort(struct node* head)
{
    struct node* ptr,*ptr1,*ptr2;
    int swap=1,tempnum;
    char tempname[25];
    float tempmarks;
    ptr=head->link;
    if(ptr==NULL)
    {
        printf("List Empty\n");
    }
    else
    {
        while(swap==1)
        {
            swap=0;
            ptr=head->link;
            while(ptr!=NULL)
            {
                ptr1=ptr;
                ptr2=ptr->link;
                if(ptr2==NULL)
                {
                    break;
                }
                if((ptr1->num >ptr2->num))
                {
                    tempnum=ptr1->num;
                    strcpy(tempname,ptr1->name);
                    tempmarks=ptr1->marks;
                    ptr1->num=ptr2->num;
                    strcpy(ptr1->name,ptr2->name);
                    ptr1->marks=ptr2->marks;
                    ptr2->num=tempnum;
                    strcpy(ptr2->name,tempname);
                    ptr2->marks=tempmarks;
                    swap=1;
                }
                ptr=ptr->link;
            }
        }
    }
}

void display(struct node* head)
{
    struct node* ptr;
    ptr=head->link;
    if(ptr==NULL)
    {
        printf("List Empty\n");
    }
    else
    {
        printf("NUMBER\tNAME\tMARKS\n");
        while(ptr!=NULL)
        {
            printf("%d\t%s\t%f\n",ptr->num,ptr->name,ptr->marks);
            ptr=ptr->link;
        }
    }
}

void main()
{
    struct node* head;
    int value,num;
    char name[25];
    float marks;
    char ch='y';
    head=malloc(sizeof(struct node));
    head->link=NULL;
    while (ch=='y'||ch=='Y')
    {
        printf("1 : Insert (at the beginning)\n2 : Delete (based on number)\n"
        "3 : Search (based on number)\n4 : Sort on the basis of number\n"
        "5 : Display\n");
        printf("Enter your choice : ");
        scanf("%d",&value);
        switch(value)
        {
            case 1: printf("Enter the Number : ");
                    scanf("%d",&num);
                    printf("Enter the Name : ");
                    scanf(" %[^\n]",name);
                    printf("Enter the Marks : ");
                    scanf("%f",&marks);
                    insert(head,num,name,marks);
                    break;

            case 2: printf("Enter the Number : ");
                    scanf("%d",&num);
                    delete(head,num);
                    break;
        
            case 3: printf("Enter the Number : ");
                    scanf("%d",&num);
                    search(head,num);
                    break;

            case 4: sort(head);
                    break;
            case 5: display(head);
                    break;

            default : printf("Invalid Choice!!\n");
        }
        printf("Do you want to continue ?(y/n) : ");
        scanf(" %c",&ch);
    }
}
