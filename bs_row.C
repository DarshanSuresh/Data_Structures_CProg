#include <stdio.h>
#include <conio.h>

#define MAX 10

void main() {
	int mat[MAX][MAX];
	int r, c;
	int i, j, k;
	int temp;

	clrscr();

	printf("Enter number of rows and columns: ");
	scanf("%d %d", &r, &c);

	printf("Enter matrix elements:\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	for (k = 0; k < r; k++) {
		for (i = 0; i < c - 1; i++) {
			for (j = 0; j < c - i - 1; j++) {
				if (mat[k][j] > mat[k][j + 1]) {
					temp = mat[k][j];
					mat[k][j] = mat[k][j + 1];
					mat[k][j + 1] = temp;
				}
			}
		}
	}

	printf("\nMatrix after Row-wise Bubble Sort:\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%4d", mat[i][j]);
		}
		printf("\n");
	}

	getch();
}
