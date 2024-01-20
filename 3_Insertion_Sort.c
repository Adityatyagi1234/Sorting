//Program for Insertion Sort O(N2)
#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int arr[], int n) {  
  int i, j;  
  for (i = 0; i < n-1; i++) 
  {  
    j = i+1;
    while (j > 0 && arr[j] < arr[j-1]) 
    {  
      int temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
      j--;
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
    insertion_sort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}