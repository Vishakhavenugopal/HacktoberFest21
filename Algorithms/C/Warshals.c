/*  Warshall's Algorithm
    This program is written by Vishakha V USN- 4NI18IS111 B Section
*/
#include<stdio.h>
#include<stdlib.h>

void warshal(int a[10][10],int n)
{
    int i,j,k;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j][i]==1)
            {
                for(k=0;k<n;k++)
                    a[j][k] = a[j][k] || a[i][k];
            }
        }
    }
}

int main()
{
    int a[10][10],n,i,j;

    printf("Enter the number of vertices\n");
    scanf("%d",&n);

    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }

    warshal(a,n);

    printf("The Transitive closure is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
