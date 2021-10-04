/*  0/1 Knapsack Problem Execution in C.
    This program is written by Vishakha V USN-4NI18IS111 B Section
*/
#include<stdio.h>
#include<stdlib.h>

int maxi(int a, int b){
    if(a>b)
        return a;
    return b;
}

int knapsack( int max , int n , int w[],int v[]){

    int k[n][max],m=0;

    for(int i=0;i<n;i++){

        for(int j=0;j<max;j++){

            if(i==0 || j == 0)
                k[i][j]=0;

            else if(w[i]<=j){
                k[i][j]=maxi(v[i]+k[i-1][j-w[i]], k[i-1][j]);
            }

            else
                k[i][j]= k[i-1][j];

            if(k[i][j]>m)
                m=k[i][j];
        }
    }

    return m;
}

int main()
{

    int n,max;
    printf("Enter the number of items\n");
    scanf("%d",&n);

    int w[n], v[n];
    printf("Enter the respective weights\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }

    printf("Enter the respective values\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }

    printf("Enter the max capacity\n");
    scanf("%d",&max);

    printf("The maximum profit is %d",knapsack(max , n , w , v));
    // knapsack(max , n , w , v);
    return 0;
}
