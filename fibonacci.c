#include <stdio.h>
#include <conio.h>

int fibRec(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fibRec(n-1)+fibRec(n-2);
}

void main(){
    int n,i,a=0,b=1,c;
    clrscr();
    printf("Enter number of terms: ");
    scanf("%d",&n);
    
    // Iterative
    printf("Fibonacci Series (Iterative): ");
    for(i=0;i<n;i++){
        if(i<=1) c=i;
        else { c=a+b; a=b; b=c; }
        printf("%d ",c);
    }
    
    // Recursive
    printf("\nFibonacci Series (Recursive): ");
    for(i=0;i<n;i++)
        printf("%d ", fibRec(i));
    
    getch();
}
