//Program for Merge Sort O(NlogN)
#include<stdio.h>
#include<stdlib.h>

void MergeArray(int *arr, int l, int mid, int r, int size)
{
    int i=l, j=mid+1, k=0;
    int *result = (int *)malloc(sizeof(int)*size);
    while(i<=mid && j<=r)
    {
        if(arr[i]<arr[j])
        {
            result[k]=arr[i];
            i++;
        }
        else
        {
            result[k]=arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        result[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r) {
        result[k] = arr[j];
        j++;
        k++;
    }

    for (i = l, k = 0; i <= r; i++, k++) 
    {
        arr[i] = result[k];
    }

    free(result);
}

void MergeSort(int *arr, int l, int r, int size)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        MergeSort(arr, l, mid, size);
        MergeSort(arr, mid+1, r, size);
        MergeArray(arr, l, mid, r, size);
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
    MergeSort(arr, 0, size-1, size);

    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
}