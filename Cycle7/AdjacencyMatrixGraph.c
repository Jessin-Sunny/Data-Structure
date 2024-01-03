/*Representing Graph in adjaceny matrix*/
#include <stdio.h>
#define size 10
int A[size][size];

void create_adjmatrix(int vertex)
{
    int i,j;        //i and j represents rows and columns
    for(i=0;i<vertex;i++)
    {
        for(j=0;j<vertex;j++)
        {
            A[i][j]=0;
        }
    }
}

void insert_edge(int i,int j,int isdirect)
{
    if(!isdirect)       //updating both directions for undirected graph
    {
        A[i][j]=1;
        A[j][i]=1;
    }
    else
    {
        A[i][j]=1;
    }
}

void display(int vertex)
{
    int i,j;
    printf("Graph in Adjacency Matrix\n");
    for(i=0;i<vertex;i++)
    {
        for(j=0;j<vertex;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int vertex,edges,s,d,isdirect;
    printf("How many vertices ? : ");
    scanf("%d",&vertex);
    create_adjmatrix(vertex);
    printf("Enter 1 for a directed graph or 0 for an undirected graph: ");
    scanf("%d",&isdirect);
    printf("How many edges ? : ");
    scanf("%d",&edges);
    printf("Enter the edges(source destination)\n");
    for(int i=1;i<=edges;i++)
    {
        printf("Edge %d : ",i);
        scanf("%d %d",&s,&d);
        
        //checking whether the edge given is valid or not
        if(s<0 || s>=vertex || d<0 || d>=vertex)
        {
            printf("Invalid edge, please enter valid edge\n");
            i--;
            continue;
        }
        insert_edge(s,d,isdirect);
    }
    display(vertex);
}
