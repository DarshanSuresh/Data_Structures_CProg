#include <stdio.h>
#include <conio.h>

void main() {
    int arr[10], n, pos, i, value;
    clrscr();
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    // Insertion
    printf("Enter position to insert and value: ");
    scanf("%d %d", &pos, &value);
    for(i = n; i >= pos; i--)
        arr[i] = arr[i-1];
    arr[pos-1] = value;
    n++;
    
    printf("Array after insertion: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    // Deletion
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    for(i = pos-1; i < n-1; i++)
        arr[i] = arr[i+1];
    n--;
    
    printf("Array after deletion: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    getch();
}
