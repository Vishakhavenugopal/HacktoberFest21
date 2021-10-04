#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* 4. Implement Selection Sort. Determine the time required to sort the elements in an array.
Repeat the experiment for different values of n and plot a graph of the time taken versus n.
This program is written by Shreyas G Trivikram, USN- 4NI19IS093, B Section
*/

void delay(unsigned int msec)
{
    clock_t goal=msec+clock();
    while (goal > clock());
}
void selection_sort(int n,int a[])
{
    int min,temp,i,j;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            delay(1);
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

int main()
{
    int a[100000],n,pos,item, i, opt;
    clock_t start, end;
    double time;

    printf("Enter the array size:");
    scanf("%d",&n);

    printf("\nElements are:\n");
    for(i=0;i<n;i++)
    {

        a[i]=(int)rand()%10000;
        printf("%d\t", a[i]);

    }

    printf("\n\nThe sorted list by selection sort is:\n");
    start=clock();
    selection_sort(n,a);
    end=clock();

    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
     time = (end-start)/CLK_TCK;
     printf("\n\nThe time taken = %f",time);

     return 0;
}
