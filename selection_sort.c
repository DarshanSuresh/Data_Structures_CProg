#include <stdio.h>
#include <conio.h>

void main() {
    int arr[10], n, i, j, min, temp;
    clrscr();
    
    printf("Enter number of elements: ");
    scanf("%d",&n);
    
    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    
    for(i=0;i<n-1;i++) {
        min=i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[min]) min=j;
        temp=arr[i]; arr[i]=arr[min]; arr[min]=temp;
    }
    
    printf("Sorted array: ");
    for(i=0;i<n;i++) printf("%d ", arr[i]);
    getch();
}
