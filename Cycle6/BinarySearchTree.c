/* Binary Search Tree */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
};

struct node* root;

struct node* create()
{
    struct node* new;
    new=malloc(sizeof(struct node));
    new->lchild=NULL;
    new->rchild=NULL;
    return new;
}

struct node* insert(struct node* ptr,int data)
{
    if(ptr==NULL)
    {
        ptr=create();
        ptr->data=data;
        return ptr;
    }
    if(data < ptr->data)
    {
        ptr->lchild=insert(ptr->lchild,data);
    }
    else if(data > ptr->data)
    {
        ptr->rchild=insert(ptr->rchild,data);
    }
    return ptr;
}

void Inorder(struct node* ptr)
{
    if(ptr!=NULL)
    {
        Inorder(ptr->lchild);
        printf("%d ",ptr->data);
        Inorder(ptr->rchild);
    }
}

void Preorder(struct node* ptr)
{
    if(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        Preorder(ptr->lchild);
        Preorder(ptr->rchild);
    }
}

void Postorder(struct node* ptr)
{
    if(ptr!=NULL)
    {
        Postorder(ptr->lchild);
        Postorder(ptr->rchild);
        printf("%d ",ptr->data);
    }
}

int countln(struct node* ptr)
{
    int count=0;
    if(ptr==NULL)
    {
        return 0;
    }
    if(ptr->lchild==NULL && ptr->rchild==NULL)
    {
        return 1;
    }
    count=count+countln(ptr->lchild);
    count=count+countln(ptr->rchild);
    return count;
}

void sort(struct node* root)
{
    Inorder(root);
}

struct node* delete(struct node* ptr,int data)
{
    if(ptr==NULL)
    {
        return ptr;
    }
    if(data < ptr->data)
    {
        ptr->lchild=delete(ptr->lchild,data);
    }
    else if(data > ptr->data)
    {
        ptr->rchild=delete(ptr->rchild,data);
    }
    else
    {
        struct node* temp;
        if(ptr->lchild==NULL)
        {
            temp=ptr->rchild;
            free(ptr);
            return temp;
            
        }
        else if(ptr->rchild==NULL)
        {
            temp=ptr->lchild;
            free(ptr);
            return temp;
        }
        struct node* succparent,*succ;
        succparent=ptr;
        succ=ptr->rchild;
        while(succ->lchild!=NULL)
        {
            succparent=succ;
            succ=succ->lchild;
        }
        ptr->data=succ->data;
        if(succparent!=ptr)
        {
            succparent->lchild=delete(succparent->lchild,succ->data);
        }
        else
        {
            succparent->rchild=delete(succparent->rchild,succ->data);
        }
    }
    return ptr;
}

void main()
{
    char ch='y';
    int value,data;
    while (ch=='y' || ch=='Y')
    {
        printf("1 : Insert a node\n");
        printf("2 : Inorder\n");
        printf("3 : Preorder\n");
        printf("4 : Postorder\n");
        printf("5 : Delete a node : \n");
        printf("6 : Number of Leaf Nodes\n");
        printf("7 : Sort\n");
        printf("Enter your choice : ");
        scanf("%d",&value);
        switch(value)
        {
            case 1: printf("Enter the data : ");
                    scanf("%d",&data);
                    root=insert(root,data);
                        break;
            
            case 2: printf("Inorder : ");
                    Inorder(root);
                    printf("\n");
                    break;
                    
            case 3: printf("Preorder: ");
                    Preorder(root);
                    printf("\n");
                    break;
            
            case 4: printf("Postorder : ");
                    Postorder(root);
                    printf("\n");
                    break;

            case 5: printf("Enter the data : ");
                    scanf("%d",&data);
                    delete(root,data);
                    break;
                
            case 6: printf("Number of leaf nodes : %d", countln(root));
                    printf("\n");
                    break;
                
            case 7: printf("After Sorting : ");
                    sort(root);
                    printf("\n");
                    break;
                    
            
            default: printf("Invalid Choice\n");
                     break;
        
        }
        printf("Do you want to continue(y/n) : ");
        scanf(" %c",&ch);
        }
}
