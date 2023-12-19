/*Creating a linked list and traversing by deallocating the memory space*/
/*Inserting node at begining end and at arbitary position*/
/*Deleting node at begining end and at arbitary position*/
/*Reversing it*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};
void InsertFront(struct node* head,int item)
{
    struct node* new;
    new=malloc(sizeof(struct node));
    new->link=head->link;
    new->data=item;
    head->link=new;
}
void InsertEnd(struct node* head,int item)
{
    struct node* new,*ptr;
    new=malloc(sizeof(struct node));
    ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=new;
    new->data=item;
    new->link=NULL;
}
void InsertAny(struct node* head,int key,int item)
{
    struct node* new,*ptr;
    new=malloc(sizeof(struct node));
    ptr=head;
    while(ptr->data!=key)
    {
        ptr=ptr->link;
    }
    new->link=ptr->link;
    new->data=item;
    ptr->link=new;
}
void DeleteFront(struct node* head)
{
    struct node* ptr;
    ptr=head->link;
    head->link=ptr->link;
    free(ptr);
}
void DeleteEnd(struct node* head)
{
    struct node* ptr,*temp;
    ptr=head->link;
    while(ptr->link!=NULL)
    {
        temp=ptr;
        ptr=ptr->link;
    }
    temp->link=NULL;
    free(ptr);
}
void DeleteAny(struct node* head,int key)
{
    struct node* ptr,*temp;
    ptr=head->link;
    while(ptr->data!=key)
    {
        temp=ptr;
        ptr=ptr->link;
    }
    temp->link=ptr->link;
    free(ptr);
}
void display(struct node* head)
{
    struct node* ptr,*ptr1;
    printf("List contents : ");
    ptr=head;
    while (ptr!=NULL)
    {
        ptr1=ptr->link;
        printf("%d ",ptr1->data);
        free(ptr);
        ptr=ptr1;
    }
    printf("\n");
}
void Reverse(struct node* head)
{
    struct node* prev,*curr,*next;
    prev=NULL;
    curr=head->link;
    next=NULL;
    while(curr!=NULL)
    {
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    head->link=prev;
}
struct node* head;
void main()
{
    struct node* ptr,*temp,*ptr1;
    int n,num,i;
    head=malloc(sizeof(struct node));
    head->link=NULL;
    ptr=head;
    printf("How many elements ? : ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Enter the data : ");
        scanf("%d",&num);
        temp=malloc(sizeof(struct node));
        temp->data=num;
        temp->link=NULL;
        ptr->link=temp;
        ptr=ptr->link;
    }
    int item=40,key=20;
    //InsertFront(head,item);
    //InsertEnd(head,item);
    //InsertAny(head,key,item);
    //DeleteFront(head);
    //DeleteEnd(head);
    //DeleteAny(head,key);
    //Reverse(head);
    display(head);
     
}
