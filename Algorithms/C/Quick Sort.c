#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* 3. Implement Quick Sort. Determine the time required to sort the elements in an array.
Repeat the experiment for different values of n and plot a graph of the time taken versus n.
This program is written by Shreyas G Trivikram, USN- 4NI19IS093, B Section
*/

void delay(int msec)
{
    clock_t goal = msec+clock();
    while(goal > clock());
}

int partition(int a[],int l,int h)
{
    int p=a[l],temp,i,j;
    j=h;
    i=l+1;
    while(1)
    {
        while((i<j) && (a[i] <= p))
        {
            i++;
            delay(10);
        }
        while(a[j] > p)
        {
            j--;
            delay(10i
        }
        if(i<j)
        {
           temp=a[i];
           a[i]=a[j];
           a[j]=temp;
        }
        else
        {
           temp=a[l];
           a[l]=a[j];
           a[j]=temp;
           return(j);
        }
    }
    return 0;
}

void quick_sort(int a[],int l,int h)
{
    int pos;
    if(l<h)
    {
        pos=partition(a,l,h);
        quick_sort(a,l,pos-1);
        quick_sort(a,pos+1,h);
    }
    return;
}

int main()
{
    int a[1000],n,i,low,high;
    clock_t start, end;
    double time;

    printf("Enter array size ");
    scanf("%d",&n);
    printf("\nElements are:\n");
    for(i=0;i<n;i++)
    {
        a[i]=(int)rand()%1000;
        printf("%d\t", a[i]);
    }

    low = 0;
    high = n-1;

    start=clock();
    quick_sort(a,low,high);
    end=clock();

    printf("\nThe sorted list by Quick Sort is:\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }

    time=(end-start)/CLK_TCK;

    printf("\nTime taken = %f",time);

    return 0;
}
