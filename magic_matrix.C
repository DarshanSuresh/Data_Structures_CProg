#include <stdio.h>
#include <conio.h>

#define MAX 10

int isMagic(int mat[MAX][MAX], int n) {
	int sum = 0;
	int i, j;
	int rowSum, colSum;
	int diag1 = 0, diag2 = 0;

	for (j = 0; j < n; j++) {
		sum += mat[0][j];
	}

	for (i = 1; i < n; i++) {
		rowSum = 0;
		for (j = 0; j < n; j++) {
			rowSum += mat[i][j];
		}
		if (rowSum != sum) {
			return 0;
		}
	}

	for (j = 0; j < n; j++) {
		colSum = 0;
		for (i = 0; i < n; i++) {
			colSum += mat[i][j];
		}
		if (colSum != sum) {
			return 0;
		}
	}

	for (i = 0; i < n; i++) {
		diag1 += mat[i][i];
		diag2 += mat[i][n - i - 1];
	}

	if (diag1 != sum || diag2 != sum) {
		return 0;
	}

	return 1;
}

void main() {
	int mat[MAX][MAX];
	int n;
	int i, j;

	clrscr();

	printf("Enter size of square matrix: ");
	scanf("%d", &n);

	printf("Enter matrix elements:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	if (isMagic(mat, n)) {
		printf("The matrix IS a Magic Matrix.\n");
	}
	else {
		printf("The matrix is NOT a Magic Matrix.\n");
	}

	getch();
}
