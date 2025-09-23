#include <stdio.h>
#include <conio.h>

void main() {
    int arr[10], n, i, key, low, high, mid, found=0;
    clrscr();
    
    printf("Enter number of elements (sorted): ");
    scanf("%d",&n);
    
    printf("Enter sorted elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    printf("Enter element to search: ");
    scanf("%d",&key);
    
    low=0; high=n-1;
    while(low<=high) {
        mid=(low+high)/2;
        if(arr[mid]==key) { found=1; break; }
        else if(arr[mid]<key) low=mid+1;
        else high=mid-1;
    }
    
    if(found)
        printf("Element found at position %d", mid+1);
    else
        printf("Element not found");
    getch();
}
