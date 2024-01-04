/*Implementing Depth First Search*/
/*Using the data structure STACK[RECURSION]*/

#include <stdio.h>
#include <stdlib.h>

int visited[4];

void dfs(int graph[][4],int vertices,int vertex)
{
    printf("%d ",vertex);
    visited[vertex]=1;
    for(int i=0;i<vertices;i++)
    {
        if(graph[vertex][i]==1 && visited[i]!=1)
        {
            dfs(graph,vertices,i);
        }
    }
}

void main()
{
    //int vertices=5;
    /*
    int graph[5][5]={
           {0,1,0,1,0},
           {1,0,1,1,0},
           {0,1,0,1,1},
           {1,1,1,0,1},
           {0,0,1,1,0}
    };
    */
    
    int vertices=4;
    int graph[4][4] = {
            {0,1,1,0},
            {1,0,1,1},
            {1,1,0,1},
            {0,1,1,0},
        };

    for(int i=0;i<vertices;i++)
    {
        visited[i]=0;
    }
    
    int startvertex=0;
    printf("Breadth First Search from starting vertex %d : ",startvertex);
    dfs(graph,vertices,startvertex);

}