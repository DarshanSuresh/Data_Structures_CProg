#include <stdio.h>
#include <conio.h>
void main() {
    int A[10][10], B[10][10], C[10][10];
    int r1,c1,r2,c2,i,j,k;
    clrscr();
    
    // Input first matrix
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter elements of first matrix:\n");
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            scanf("%d",&A[i][j]);
    
    // Input second matrix
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d",&r2,&c2);
    printf("Enter elements of second matrix:\n");
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            scanf("%d",&B[i][j]);
    
    // Addition
    if(r1==r2 && c1==c2){
        printf("Sum of matrices:\n");
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                C[i][j]=A[i][j]+B[i][j];
                printf("%d ",C[i][j]);
            }
            printf("\n");
        }
    } else printf("Addition not possible (dimensions mismatch)\n");
    
    // Multiplication
    if(c1==r2){
        printf("Product of matrices:\n");
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                C[i][j]=0;
                for(k=0;k<c1;k++)
                    C[i][j]+=A[i][k]*B[k][j];
                printf("%d ",C[i][j]);
            }
            printf("\n");
        }
    } else printf("Multiplication not possible (dimensions mismatch)\n");
    
    // Transpose of first matrix
    printf("Transpose of first matrix:\n");
    for(i=0;i<c1;i++){
        for(j=0;j<r1;j++)
            printf("%d ",A[j][i]);
        printf("\n");
    }
    
    getch();
}
