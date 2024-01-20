//Program for Counting Sort O(N)
#include<stdio.h>
#include<stdlib.h>
int getmax(int *arr, int n)
{
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        } 
    }
    return max;
}

void count_sort(int *arr, int n)
{
    int c[10], b[10];
    int max = getmax(arr,n);
    for(int i=0; i<=max; i++)
    {
        c[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        c[arr[i]]++;
    }
    for(int i=1; i<=max; i++)
    {
        c[i] = c[i-1] + c[i];
    }
    for(int i=n-1; i>=0; i--)
    {
        b[c[arr[i]]-1] = arr[i];
        c[arr[i]]--;
    }
    for(int i=0; i<n; i++)
    {
        arr[i] = b[i];
    }
    printf("\nSorted Array:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void main()
{
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    count_sort(arr,n);
    
}