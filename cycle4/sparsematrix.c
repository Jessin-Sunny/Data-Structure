/*Read two matrix in normal form*/
//Converting to tuple form
//transpose of matrix
//find sum of two matrices
#include <stdio.h>
#define size 25
typedef struct
{
    int row;
    int col;
    int value;
}smatrix;
smatrix A[size],B[size],R[size],T1[size],T2[size];
void readmatrix(int m,int n,int a[][25])
{
    int i,j;
    printf("Enter the elements : \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }   
}
void convert(int m,int n,int a[][25],smatrix S[])
{
    int i,j,k=1,nz=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                S[k].row=i;
                S[k].col=j;
                S[k].value=a[i][j];
                k++;
                nz++;
            }
        }
    }
    S[0].row=m;
    S[0].col=n;
    S[0].value=nz;
}

void transpose(smatrix S[],smatrix T[])
{
    int n,i,j,k;
    T[0].value=S[0].value;
    n=S[0].value;
    T[0].row=S[0].col;
    T[0].col=S[0].row;
    if(n>0)                         //non zero elements condition
    {
        k=1;
        for(i=0;i<=S[0].col;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(S[j].col==i)     //Ascending order
                {
                    T[k].row=S[j].col;
                    T[k].col=S[j].row;
                    T[k].value=S[j].value;
                    k++;
                }
            }
        }
    }                     
}

void sum(smatrix A[],smatrix B[],smatrix S[])
{
    int r1,r2,c1,c2,i,j;
    int m=1,n=1,k=1;
    r1=A[0].row;
    r2=B[0].row;
    c1=A[0].col;
    c2=B[0].col;
    if((r1!=r2)&&(c1!=c2))
    {
        printf("Matrix Multiplication is NOT possible\n");
    }
    else
    {
        S[0].row=r1;
        S[0].col=c1;
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                if((A[m].row)==i && (A[m].col==j) && (B[n].row==i) && (B[n].col==j))
                {
                    S[k].row=i;
                    S[k].col=j;
                    S[k].value=A[m].value+B[n].value;
                    k++;
                    m++;
                    n++;

                }
                else if((A[m].row==i && (A[m].col==j)))
                {
                    S[k].row=i;
                    S[k].col=j;
                    S[k].value=A[m].value;
                    m++;
                    k++;
                }
                else if((B[n].row==i && (B[n].col==j)))
                {
                    S[k].row=i;
                    S[k].col=j;
                    S[k].value=B[n].value;
                    n++;
                    k++;
                }
            }
        }
        S[0].value=k-1;
    }



}
void display(smatrix S[])
{
    int i=0,j=0,k,rows,cols,values;
    rows=S[0].row;
    cols=S[0].col;
    values=S[0].value;
    if(values>0)
    {
        printf("Row\tColumn\tValue\n");
        for(k=0;k<=values;k++)
        {
            printf("%d\t%d\t%d\n", S[k].row,S[k].col,S[k].value);
        }
    }
    else
    {
        printf("Matrix is EMPTY\n");
    }
}
void main()
{
    int a[25][25],b[25][25];
    int m,n;
    printf("Enter the number of rows and columns of first matrix : ");
    scanf("%d%d",&m,&n);
    readmatrix(m,n,a);
    convert(m,n,a,A);
    printf("Enter the number of rows and columns of second matrix : ");
    scanf("%d%d",&m,&n);
    readmatrix(m,n,b);
    convert(m,n,b,B);
    printf("\n");
    printf("MATRIX 1\n");
    display(A);
    printf("\n");
    printf("MATRIX 2\n");
    display(B);
    printf("\n");
    printf("TRANSPOSE OF MATRIX 1\n");
    transpose(A,T1);
    display(T1);
    printf("\n");
    printf("TRANSPOSE OF MATRIX 2\n");
    transpose(B,T2);
    display(T2);
    printf("\n");
    printf("SUM OF MATRICES\n");
    sum(A,B,R);
    display(R);
}