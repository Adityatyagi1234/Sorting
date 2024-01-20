//Program for Selection Sort O(N2)
#include<stdio.h>
#include<stdlib.h>

void selection_sort(int arr[], int n) {  
  int i, j, min;  
  for (i = 0; i < n-1; i++) 
  {  
    min = i;
    for (j = i+1; j<n; j++) 
    {  
      if(arr[min] > arr[j])
      {
        min = j;
      }
    }  
    if(min!=i)
    {
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
  }  
}

int main(){
    int n;
    printf("Enter the number of elements in array:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selection_sort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}