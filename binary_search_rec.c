#include <stdio.h>
#include <conio.h>

int binarySearch(int arr[], int low, int high, int key) {
    int mid;
    if(low>high) return -1;
    mid=(low+high)/2;
    if(arr[mid]==key) return mid;
    else if(arr[mid]<key) return binarySearch(arr, mid+1, high, key);
    else return binarySearch(arr, low, mid-1, key);
}

void main() {
    int arr[10], n, i, key, result;
    clrscr();
    
    printf("Enter number of elements (sorted): ");
    scanf("%d",&n);
    
    printf("Enter sorted elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    printf("Enter element to search: ");
    scanf("%d",&key);
    
    result=binarySearch(arr,0,n-1,key);
    if(result!=-1) printf("Element found at position %d", result+1);
    else printf("Element not found");
    
    getch();
}
