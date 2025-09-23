#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void insertEnd(int val) {
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val; newNode->next=NULL;
    if(head==NULL) head=newNode;
    else {
        struct Node *temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=newNode;
    }
}

void search(int val) {
    struct Node *temp=head;
    int pos=1, found=0;
    while(temp!=NULL) {
        if(temp->data==val) { found=1; break; }
        temp=temp->next;
        pos++;
    }
    if(found) printf("Element %d found at position %d", val, pos);
    else printf("Element not found");
}

void display() {
    struct Node *temp=head;
    if(temp==NULL) { printf("List is empty"); return; }
    printf("Linked list: ");
    while(temp!=NULL) { printf("%d ", temp->data); temp=temp->next; }
}

void main() {
    int choice, val;
    clrscr();
    do {
        printf("\n1.Insert End 2.Search 3.Display 4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d",&val); insertEnd(val); break;
            case 2: printf("Enter value to search: "); scanf("%d",&val); search(val); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice");
        }
    } while(choice!=4);
    getch();
}
