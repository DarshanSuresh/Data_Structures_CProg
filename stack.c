#include <stdio.h>
#include <conio.h>
#define MAX 5

void main() {
    int stack[MAX], top=-1, choice, val;
    clrscr();
    
    do {
        printf("\n1.Push 2.Pop 3.Display 4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                if(top==MAX-1) printf("Stack Overflow");
                else {
                    printf("Enter value to push: ");
                    scanf("%d",&val);
                    top++; stack[top]=val;
                }
                break;
            case 2:
                if(top==-1) printf("Stack Underflow");
                else {
                    printf("Popped element: %d", stack[top]);
                    top--;
                }
                break;
            case 3:
                if(top==-1) printf("Stack is empty");
                else {
                    printf("Stack elements: ");
                    for(int i=top;i>=0;i--) printf("%d ", stack[i]);
                }
                break;
            case 4: break;
            default: printf("Invalid choice");
        }
    } while(choice!=4);
    getch();
}
