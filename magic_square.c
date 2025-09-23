#include <stdio.h>
#include <conio.h>
void main() {
    int n,i,j;
    clrscr();
    printf("Enter size of odd order magic square (n x n): ");
    scanf("%d",&n);
    if(n%2==0){ printf("Magic square requires odd n.\n"); getch(); return; }
    
    int magic[15][15]={0}; // max 15x15
    int num=1,row=0,col=n/2;
    
    while(num<=n*n){
        magic[row][col]=num++;
        int newRow=(row-1+n)%n;
        int newCol=(col+1)%n;
        if(magic[newRow][newCol]!=0) row=(row+1)%n;
        else { row=newRow; col=newCol; }
    }
    
    printf("Magic Square:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%4d",magic[i][j]);
        printf("\n");
    }
    getch();
}
