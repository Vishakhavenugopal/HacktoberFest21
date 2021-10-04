/* Dijkstras's  algorithm Execution in C.
    This program is written by Vishakha V USN-4NI18IS111 B Section
*/
#include<stdio.h>
#include<stdlib.h>

void dijkstras(int n,int v,int cost[10][10],int dist[10])
{
    int count,w,i,u,visited[10],min;

    for(i=0;i<n;i++)
    {
        visited[i]=0;
        dist[i]=cost[v][i];
    }

    visited[v]=1;
    dist[v]=1;
    count = 2;

    while(count <= n)
    {
        min=999;
        for(w=0;w<n;w++)
        {
            if(dist[w] < min && visited[w]!=1)
            {
                min=dist[w];
                u=w;
            }
        }
        visited[u]=1;
        count++;

        for(w=0;w<n;w++)
        {
            if(dist[u]+cost[u][w] < dist[w] && visited[w]!=1)
                dist[w] = dist[u] + cost[u][w];
        }
    }
}

int main()
{
    int dist[10],cost[10][10],v,n,i,j;

    printf("Enter the number of Vertices\n");
    scanf("%d",&n);

    printf("Enter the cost matrix. (Put 999 for infinity)\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }

    printf("\nEnter the source vertex\n");
    scanf("%d",&v);

    dijkstras(n,v,cost,dist);

    printf("The Shortest path from:\n\n");

    for(i=0;i<n;i++)
    {
        if(i!=v)
        {
            printf("%d -> %d is %d\n",v,i,dist[i]);
        }
    }
    return 0;
}
