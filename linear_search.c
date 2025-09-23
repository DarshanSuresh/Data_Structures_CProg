#include <stdio.h>
#include <conio.h>

void main() {
    int arr[10], n, i, key, found=0;
    clrscr();
    
    printf("Enter number of elements: ");
    scanf("%d",&n);
    
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    printf("Enter element to search: ");
    scanf("%d",&key);
    
    for(i=0;i<n;i++) {
        if(arr[i]==key) {
            found=1;
            break;
        }
    }
    
    if(found)
        printf("Element found at position %d", i+1);
    else
        printf("Element not found");
    getch();
}
