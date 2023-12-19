/*Polynomial addition with two variables*/
#include <stdio.h>
#include <stdlib.h>
struct poly
{
    float coeff;
    int exp_x,exp_y;
    struct poly* link;
};

void insert(struct poly* head,float coeff,int exp_x,int exp_y)
{
    struct poly* new,*ptr;
    new=malloc(sizeof(struct poly));
    new->coeff=coeff;
    new->exp_x=exp_x;
    new->exp_y=exp_y;
    new->link=NULL;
    if(head->link==NULL)
    {
        head->link=new;
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new;
    }
}

void display(struct poly* head)
{
    struct poly* ptr;
    ptr = head->link;
    while (ptr != NULL)
    {
        printf("%.2fx^%dy^%d", ptr->coeff, ptr->exp_x,ptr->exp_y);
        ptr = ptr->link;
        if (ptr != NULL)
        {
            printf(" + ");
        }
    }
}

void sum(struct poly* head1,struct poly* head2,struct poly* head3)
{
    struct poly* pptr,*qptr,*rptr,*new;
    pptr=head1->link;
    qptr=head2->link;
    rptr=head3;
    while(pptr!=NULL && qptr!=NULL)
    {
        if((pptr->exp_x==qptr->exp_x) && (pptr->exp_y==qptr->exp_y))
        {
            new=malloc(sizeof(struct poly));
            new->link=NULL;
            rptr->link=new;
            rptr=new;
            rptr->coeff=pptr->coeff + qptr->coeff;
            rptr->exp_x=pptr->exp_x;
            rptr->exp_y=pptr->exp_y;
            pptr=pptr->link;
            qptr=qptr->link;  
        }
        else if((pptr->exp_x > qptr->exp_x) || (pptr->exp_x==qptr->exp_x && pptr->exp_y>qptr->exp_y))
        {
            new=malloc(sizeof(struct poly));
            new->link=NULL;
            rptr->link=new;
            rptr=new;
            rptr->coeff=pptr->coeff;
            rptr->exp_x=pptr->exp_x;
            rptr->exp_x=pptr->exp_x;
            pptr=pptr->link;
        }
        else
        {
            new=malloc(sizeof(struct poly));
            new->link=NULL;
            rptr->link=new;
            rptr=new;
            rptr->coeff=qptr->coeff;
            rptr->exp_x=qptr->exp_x;
            rptr->exp_y=qptr->exp_y;
            qptr=qptr->link;
        }
    }
    while(pptr!=NULL)
    {
        new=malloc(sizeof(struct poly));
        rptr->link=new;
        rptr=new;
        rptr->coeff=pptr->coeff;
        rptr->exp_x=pptr->exp_x;
        rptr->exp_y=pptr->exp_y;
        rptr->link=NULL;
        pptr=pptr->link;
    }
    while(qptr!=NULL)
    {
        new=malloc(sizeof(struct poly));
        rptr->link=new;
        rptr=new;
        rptr->coeff=qptr->coeff;
        rptr->exp_x=pptr->exp_x;
        rptr->exp_y=pptr->exp_y;
        rptr->link=NULL;
        qptr=qptr->link;
    }
}

void main()
{
    int i,m,n,exp_x,exp_y;
    float coeff;
    struct poly* phead,*qhead,*rhead;
    phead=malloc(sizeof(struct poly));
    phead->link=NULL;
    qhead=malloc(sizeof(struct poly));
    qhead->link=NULL;
    rhead=malloc(sizeof(struct poly));
    rhead->link=NULL;
    printf("Enter the number of terms of first polynomial : ");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("Enter the coefficent : ");
        scanf("%f",&coeff);
        printf("Enter the exponent of x : ");
        scanf("%d",&exp_x);
        printf("Enter the exponent of y : ");
        scanf("%d",&exp_y);
        insert(phead,coeff,exp_x,exp_y);
    }
    printf("Enter the number of terms of second polynomial : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the coefficent : ");
        scanf("%f",&coeff);
        printf("Enter the exponent of x : ");
        scanf("%d",&exp_x);
        printf("Enter the exponent of y : ");
        scanf("%d",&exp_y);
        insert(qhead,coeff,exp_x,exp_y);
    }
    sum(phead,qhead,rhead);
    printf("The first polynomial : ");
    display(phead);
    printf("\n");
    printf("The second polynomial : ");
    display(qhead);
    printf("\n");
    printf("The Resultant polynomial : ");
    display(rhead);
    printf("\n");
}