#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertFront(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=head;
    head=newNode;
}

void insertEnd(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val; newNode->next=NULL;
    if(head==NULL) head=newNode;
    else {
        struct Node *temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=newNode;
    }
}

void insertAfter(int val, int after) {
    struct Node *temp=head;
    while(temp!=NULL && temp->data!=after) temp=temp->next;
    if(temp==NULL) printf("Element not found");
    else {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data=val; newNode->next=temp->next;
        temp->next=newNode;
    }
}

void display() {
    struct Node *temp=head;
    if(temp==NULL) { printf("List is empty"); return; }
    printf("Linked list: ");
    while(temp!=NULL) { printf("%d ", temp->data); temp=temp->next; }
}

void main() {
    int choice, val, after;
    clrscr();
    do {
        printf("\n1.Insert Front 2.Insert End 3.Insert After 4.Display 5.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d",&val); insertFront(val); break;
            case 2: printf("Enter value: "); scanf("%d",&val); insertEnd(val); break;
            case 3: 
                printf("Enter value and after element: "); 
                scanf("%d %d",&val,&after); 
                insertAfter(val,after); 
                break;
            case 4: display(); break;
            case 5: break;
            default: printf("Invalid choice");
        }
    } while(choice!=5);
    getch();
}
