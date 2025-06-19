#include<stdio.h>

int res[20]; 
int s[20]; 
int j=0;

void dfs(int u,int n,int cost[10][10])
{
    int v;
    //visit the vertex u
    s[u]=1;
    //traverse deeper into the graph till we get the dead end or till all the vertices are visited
    for(v=0;v<n;v++)
    {
        if(cost[u][v]==1  && s[v]==0)
            {
                dfs(v,n,cost);
            }
    }
    res[j++]=u;
}


void depth_first_traversal(int n,int a[10][10])
{
    int i;
    for(i=0;i<n;i++)
            s[i]=0;
    for(i=0;i<n;i++)
    {
        if(s[i]==0)
            dfs(i,n,a);
    }
}

void main()
{
    int i,j,k,m,n,cost[10][10];
    printf("\nEnter the number of nodes");
    scanf("%d",&n);

    printf("\nEnter the adjacency matrix:");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
             scanf("%d",&cost[i][j]);

    depth_first_traversal(n,cost);

    printf("\nThe topological sequence is:\n");
    for(i=n-1;i>=0;i--)
        printf("%d   ",res[i]);
}
