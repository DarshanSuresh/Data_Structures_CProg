#include <stdio.h>
#include <conio.h>

void main() {
    int matrix[2][3], i, j;
    clrscr();
    
    printf("Enter 6 elements for 2x3 matrix:\n");
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            scanf("%d",&matrix[i][j]);
    
    // Row-major
    printf("Row-major order: ");
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            printf("%d ", matrix[i][j]);
    
    // Column-major
    printf("\nColumn-major order: ");
    for(j=0;j<3;j++)
        for(i=0;i<2;i++)
            printf("%d ", matrix[i][j]);
    
    getch();
}
