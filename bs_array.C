#include <stdio.h>
#include <conio.h>

#define MAX 10

void main() {
	int mat[MAX][MAX];
	int temp[MAX * MAX];
	int r, c;
	int i, j, index;
	int t;

	clrscr();

	printf("Enter number of rows and columns: ");
	scanf("%d %d", &r, &c);

	printf("Enter matrix elements:\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	// Flatten matrix into temp
	index = 0;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			temp[index++] = mat[i][j];
		}
	}

	// Bubble sort on temp array
	for (i = 0; i < r * c - 1; i++) {
		for (j = 0; j < r * c - i - 1; j++) {
			if (temp[j] > temp[j + 1]) {
				t = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = t;
			}
		}
	}

	// Copy back to matrix
	index = 0;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			mat[i][j] = temp[index++];
		}
	}

	printf("\nMatrix after full Bubble Sort:\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%4d", mat[i][j]);
		}
		printf("\n");
	}

	getch();
}
