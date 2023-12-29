/*Creating a Binary Tree using Linked List */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
};

struct node* create()
{
    struct node* new;
    new=malloc(sizeof(struct node));
    new->lchild=NULL;
    new->rchild=NULL;
    return new;
}

void BuildTree(struct node* ptr,int data)
{
    struct node* new;
    int value;
    char ch;
    ptr->data=data;
    printf("Node with %d has left child?(y/n) : ",ptr->data);
    scanf(" %c",&ch);
    if (ch=='y' || ch=='Y')
    {
        new=create();
        ptr->lchild=new;
        printf("Enter the data : ");
        scanf("%d",&value);
        BuildTree(new,value);
    }
    printf("Node with %d has right child?(y/n) : ",ptr->data);
    scanf(" %c",&ch);
    if (ch=='y' || ch=='Y')
    {
        new=create();
        ptr->rchild=new;
        printf("Enter the data : ");
        scanf("%d",&value);
        BuildTree(new,value);
    }
    
}

void Inorder(struct node* ptr)
{
    struct node* ptr1;
    ptr1=ptr;
    if(ptr1!=NULL)
    {
        Inorder(ptr1->lchild);
        printf("%d ",ptr1->data);
        Inorder(ptr1->rchild);
    }
}

void Preorder(struct node* ptr)
{
    struct node* ptr1;
    ptr1=ptr;
    if(ptr1!=NULL)
    {
        printf("%d ",ptr1->data);
        Preorder(ptr1->lchild);
        Preorder(ptr1->rchild);
    }
}

void Postorder(struct node* ptr)
{
    struct node* ptr1;
    ptr1=ptr;
    if(ptr1!=NULL)
    {
        Postorder(ptr1->lchild);
        Postorder(ptr1->rchild);
        printf("%d ",ptr1->data);
    }
}

void main()
{
    int data;
    struct node* root;
    root=create();
    printf("Enter the data : ");
    scanf("%d",&data);
    BuildTree(root,data);
    Inorder(root);
    printf("\n");
    Preorder(root);
    printf("\n");
    Postorder(root);
    printf("\n");
    

}