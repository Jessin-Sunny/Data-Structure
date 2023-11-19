/*Program for reading two polynomial using arrays and finding the sum of the polynomials*/
#include <stdio.h>
struct poly
{
    float coeff;
    int exp;
}P[10],Q[10],R[10];

int k=0;
void read(int terms,struct poly A[])
{
    int i;
    for(i=0;i<terms;i++)
    {
        printf("Enter the exponent : ");
        scanf("%d",&A[i].exp);
        printf("Enter the coefficent : ");
        scanf("%f",&A[i].coeff);
    }
}
void sum(int m,struct poly A1[],int n,struct poly A2[])
{
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(A1[i].exp==A2[j].exp)
        {
            R[k].coeff=A1[i].coeff+A2[j].coeff;
            R[k].exp=A1[i].exp;
            i++;
            j++;
            k++;
        }
        else if(A1[i].exp>A2[j].exp)
        {
            R[k].coeff=A1[i].coeff;
            R[k].exp=A1[i].exp;
            i++;
            k++;
        }
        else
        {
            R[k].coeff=A2[j].coeff;
            R[k].exp=A2[j].exp;
            j++;
            k++;
        }
    }
    while(i<m)
    {
       R[k].coeff=A1[i].coeff;
        R[k].exp=A1[i].exp;
        i++;
        k++; 
    }
    while(j<n)
    {
        R[k].coeff=A2[j].coeff;
        R[k].exp=A2[j].exp;
        j++;
        k++;
    }
}
void display(int terms,struct poly A[])
{
    int i;
    for(i=0;i<terms;i++)
    {
        if(i==terms-1)
        {
            printf("%.2fx^%d",A[i].coeff,A[i].exp);    
        }
        else
        {
            printf("%.2fx^%d + ",A[i].coeff,A[i].exp);
        }
    }
}
void main()
{
    int m,n;
    printf("Enter the number of terms of first polynomial : ");
    scanf("%d",&m);
    read(m,P);
    printf("Enter the number of terms of second polynomial : ");
    scanf("%d",&n);
    read(n,Q);
    sum(m,P,n,Q);
    printf("The first polynomial : ");
    display(m,P);
    printf("\n");
    printf("The second polynomial : ");
    display(n,Q);
    printf("\n");
    printf("The Resultant polynomial : ");
    display(k,R);
    printf("\n");
}