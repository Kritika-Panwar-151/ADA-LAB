#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int count=0;
void merge(int low,int mid,int high,int arr[]);
void merge_sort(int low,int high,int arr[])
{
    if(low<high)
    {

        int mid=(low+high)/2;
        merge_sort(low,mid,arr);
        merge_sort(mid+1,high,arr);
        merge(low,mid,high,arr);
    }
}
void merge(int low,int mid,int high,int arr[])
{
    count+=high-low+1;
    int i=low;
    int j=mid+1;
    int k=low;
    int temp[high+1];
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=high)
    {
        temp[k++]=arr[j++];
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i];
    }
}
void main()
{
    clock_t start, end;
    double cpu_time_used;
    srand(time(NULL));
    /*
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    */
    int n=45000;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=(rand() % (2*n));
    }
    start = clock();
    merge_sort(0,n-1,arr);
    end = clock();
 /*
    printf("The sorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    */
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC)*1000.0;

    printf("\nInput: %d Execution time: %f milliseconds\n",n,cpu_time_used);
}
