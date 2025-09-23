#include <stdio.h>
#include <conio.h>

void main() {
    int a;
    char name[20];
    clrscr();
    
    printf("Enter an integer: ");
    scanf("%d", &a);
    
    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("You entered: %d and %s\n", a, name);
    getch();
}
