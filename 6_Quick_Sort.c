//Program for Quick Sort O(NlogN)
#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int LomutoPartition(int *arr, int l, int r)
{
    int p, i;
    p = arr[r];
    i = l-1;
    for(int j=l; j<=r-1; j++)
    {
        if(arr[j] < p)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, r);
    return i+1;
}
void QuickSort(int *arr, int l, int r)
{
    int pivot;
    if(l < r)
    {
        pivot = LomutoPartition(arr, l, r);
        QuickSort(arr, l, pivot-1);
        QuickSort(arr, pivot+1, r);
    }
}
void main()
{
    int i, size;
    printf("Enter size of array: ");
    scanf("%d",&size);

    int *arr = (int *)malloc(sizeof(int)*size);
    printf("Enter elements: ");
    for(i=0; i<size; i++)
    {
        scanf("%d",(arr+i));
    }
    QuickSort(arr, 0, size-1);

    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
}
