#include <stdio.h>
#include <conio.h>

void main() {
    int arr[5], i;
    clrscr();
    
    printf("Enter 5 elements: ");
    for(i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Array elements are: ");
    for(i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    getch();
}
