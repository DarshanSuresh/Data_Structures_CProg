#include <stdio.h>
#include <conio.h>
#define MAX 5

void main() {
    int queue[MAX], front=-1, rear=-1, choice, val;
    clrscr();
    
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                if(rear==MAX-1) printf("Queue Overflow");
                else {
                    printf("Enter value to enqueue: ");
                    scanf("%d",&val);
                    if(front==-1) front=0;
                    rear++;
                    queue[rear]=val;
                }
                break;
            case 2:
                if(front==-1 || front>rear) { printf("Queue Underflow"); front=-1; rear=-1; }
                else {
                    printf("Dequeued element: %d", queue[front]);
                    front++;
                }
                break;
            case 3:
                if(front==-1) printf("Queue is empty");
                else {
                    printf("Queue elements: ");
                    for(int i=front;i<=rear;i++) printf("%d ", queue[i]);
                }
                break;
            case 4: break;
            default: printf("Invalid choice");
        }
    } while(choice!=4);
    getch();
}
