#include <stdio.h>
#include <conio.h>

void main() {
    int arr[10], n, i, j, gap, temp;
    clrscr();
    
    printf("Enter number of elements: ");
    scanf("%d",&n);
    
    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    
    for(gap=n/2; gap>0; gap/=2)
        for(i=gap;i<n;i++) {
            temp=arr[i];
            for(j=i; j>=gap && arr[j-gap]>temp; j-=gap)
                arr[j]=arr[j-gap];
            arr[j]=temp;
        }
    
    printf("Sorted array: ");
    for(i=0;i<n;i++) printf("%d ", arr[i]);
    getch();
}
