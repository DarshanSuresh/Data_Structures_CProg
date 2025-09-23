#include <stdio.h>
#include <conio.h>
#include <math.h>

void main() {
    int arr[20], n, i, key, step, prev, found=0;
    clrscr();
    
    printf("Enter number of elements (sorted): ");
    scanf("%d",&n);
    
    printf("Enter sorted elements: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    
    printf("Enter element to search: ");
    scanf("%d",&key);
    
    step = sqrt(n);
    prev = 0;
    
    while(arr[(prev+step<n ? prev+step : n)-1] < key) {
        prev += step;
        if(prev >= n) break;
    }
    
    for(i=prev; i<(prev+step<n ? prev+step : n); i++) {
        if(arr[i]==key){ found=1; break; }
    }
    
    if(found) printf("Element found at position %d\n", i+1);
    else printf("Element not found\n");
    
    getch();
}
