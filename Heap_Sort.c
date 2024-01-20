#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void MaxHeapify(int *arr, int n, int i)
{
    int largest = i, left = 2*i+1, right = 2*i+2;
    if(left<n && arr[left]>arr[largest])
    {
        largest = left;
    }
    if(right<n && arr[right]>arr[largest])
    {
        largest = right;
    }
    if(largest!=i)
    {
        swap(arr, largest, i);
    }
}

void BuildHeap(int *arr, int n)
{
    for(int i = (n-2)/2; i>=0; i--)
    {
        MaxHeapify(arr, n, i);
    }
}

void HeapSort(int *arr, int n)
{
    BuildHeap(arr, n);
    for(int i = n-1; i>=0; i--)
    {
        swap(arr, 0, i);
        MaxHeapify(arr, i, 0);
    }
}

void main()
{
    int size;
    printf("Enter array size: ");
    scanf("%d",&size);

    int *arr = (int *)malloc(sizeof(int)*size);

    printf("\nEnter array elements: ");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }

    HeapSort(arr, size);
    
    printf("\nSorted Array: ");
    for(int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
}