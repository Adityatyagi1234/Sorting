//Program for Radix Sort (Sorting in linear time)
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

void count_sort(int *arr, int n, int digit)
{
    int b[10];
    int c[10] = {0};
    for(int i=0; i<n; i++)
    {
        c[(arr[i]/digit)%10]++;
    }
    for(int i=1; i<=10; i++)
    {
        c[i] = c[i-1] + c[i];
    }
    for(int i=n-1; i>=0; i--)
    {
        b[c[(arr[i]/digit)%10]-1] = arr[i];
        c[(arr[i]/digit)%10]--;
    }
    for(int i=0; i<n; i++)
    {
        arr[i] = b[i];
    }
}

void radix_sort(int *arr, int n)
{
    int c[10], b[10];
    int max = getmax(arr,n);
    for(int digit=1; (max/digit)>0; digit=digit*10)
    {
        count_sort(arr, n, digit);
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
    radix_sort(arr,n);
}