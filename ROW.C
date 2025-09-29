#include <stdio.h>
#include <conio.h>

#define MAX 10

void main() {
    int mat[MAX][MAX];
    int r, c;
    int base = 1000;
    int size = 4;
    int i, j, addr;

    clrscr();

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++) {
	for (j = 0; j < c; j++) {
	    scanf("%d", &mat[i][j]);
	}
    }

    printf("\nRow Major Addressing:\n");
    for (i = 0; i < r; i++) {
	for (j = 0; j < c; j++) {
	    addr = base + ((i * c) + j) * size;
	    printf("A[%d][%d] = %d at address %d\n", i, j, mat[i][j], addr);
	}
    }

    getch();
}
