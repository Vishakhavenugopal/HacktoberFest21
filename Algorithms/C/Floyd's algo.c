/* Floyd's  algorithm Execution in C.
    This program is written by Vishakha V USN-4NI18IS111 B Section
*/
#include<stdio.h>
#include<stdlib.h>
void floyd(int c[10][10], int n)
{
int i, j, k;

for(k=0;k<n;k++)
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((c[i][k]+c[k][j])<c[i][j])
               c[i][j] = c[i][k]+c[k][j];
        }
    }
}
}

void main()
{
int n, i, j, c[10][10];

printf("Enter number of vertices:");
 scanf("%d",&n);

printf("\nEnter adjacency matrix (for infinity, put 999):\n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
        scanf("%d",&c[i][j]);
}


floyd(c,n);

printf("\nThe all pair shortest path is :\n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
        printf("%d\t",c[i][j]);
    printf("\n");
}
}

