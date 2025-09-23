#include <stdio.h>
#include <conio.h>

int factorialRec(int n){
    if(n==0 || n==1) return 1;
    else return n*factorialRec(n-1);
}

void main(){
    int n, i, fact=1;
    clrscr();
    printf("Enter number: ");
    scanf("%d",&n);
    
    // Iterative
    for(i=1;i<=n;i++) fact*=i;
    printf("Factorial (Iterative) of %d is %d\n", n, fact);
    
    // Recursive
    printf("Factorial (Recursive) of %d is %d\n", n, factorialRec(n));
    
    getch();
}
