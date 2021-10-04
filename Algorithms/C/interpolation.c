/*  Interpolation Search Execution in C.
    This program is written by Vishakha V USN-4NI18IS111 B Section
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void delay(int msec)
{
    clock_t goal = msec+clock();
    while(goal > clock());
}
void Sort(int a[],int);
int interpolation_search(int a[], int,int,int);

int main()
{
    int a[20000],n,pos,item,i,r;
    clock_t start,end;
    double timetaken;

    printf("Enter the array size:");
    scanf("%d",&n);
    printf("\nElements are:\n");
   for(int j=0;j<n;j++)
   a[j]=-1;
   for(int i=0;i<n;i++)
   {
      r = (rand() % 1000) + 1;
      for(int j=0;j<n;j++)
      {
        if(r == a[j])
        {
          r = (rand() % 1000) + 1;
          j=-1;
        }
    }
        a[i]=r;
    }
    for(int i=0;i<n;i++){
        printf("%d  ",a[i]);
    }

    Sort(a,n);
    printf("\nSorted list:\n");
    for(i=0;i<n;i++)
    {
    printf("%d\t",a[i]);
    }

    printf("\nEnter the key element:\n");
    scanf("%d",&item);

     start=clock();
     pos=interpolation_search(a,0,n-1,item);
     end=clock();

    if (pos == -1)
		printf("\nElement %d not found\n", item);
	else
		printf("\nElement %d found at position %d\n", item, pos);

    timetaken=(double)(end-start)/CLK_TCK;
    printf("\n Time taken = %f\n",timetaken);

    return 0;
}


void Sort(int a[], int n)
{
int i,j,temp;
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
    if(a[i]>a[j])
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}}}

int interpolation_search(int a[], int start, int end, int item)
{
	int pos;
	while (start <= end)
	{
		pos = start + (end - start) * ((item - a[start]) / (a[end] - a[start]));
		if (item == a[pos])
			return pos;
		if (item < a[pos])
			end = pos - 1;
		else
			start = pos + 1;
			delay(10);
	}
	return -1;
}
