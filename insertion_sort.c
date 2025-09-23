#include <stdio.h>
#include <conio.h>

void main() {
    int arr[10], n, i, j, key;
    clrscr();
    
    printf("Enter number of elements: ");
    scanf("%d",&n);
    
    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    
    for(i=1;i<n;i++) {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    
    printf("Sorted array: ");
    for(i=0;i<n;i++) printf("%d ", arr[i]);
    getch();
}
