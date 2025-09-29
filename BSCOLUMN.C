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

	for (k = 0; k < c; k++) {
		for (i = 0; i < r - 1; i++) {
			for (j = 0; j < r - i - 1; j++) {
				if (mat[j][k] > mat[j + 1][k]) {
					temp = mat[j][k];
					mat[j][k] = mat[j + 1][k];
					mat[j + 1][k] = temp;
				}
			}
		}
	}

	printf("\nMatrix after Column-wise Bubble Sort:\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%4d", mat[i][j]);
		}
		printf("\n");
	}

	getch();
}
