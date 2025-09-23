#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void deleteFront() {
    if(head==NULL) printf("List is empty");
    else {
        struct Node *temp=head;
        head=head->next;
        printf("Deleted element: %d", temp->data);
        free(temp);
    }
}

void deleteEnd() {
    if(head==NULL) printf("List is empty");
    else if(head->next==NULL) { printf("Deleted element: %d", head->data); free(head); head=NULL; }
    else {
        struct Node *temp=head;
        while(temp->next->next!=NULL) temp=temp->next;
        printf("Deleted element: %d", temp->next->data);
        free(temp->next);
        temp->next=NULL;
    }
}

void deleteValue(int val) {
    if(head==NULL) { printf("List is empty"); return; }
    if(head->data==val) { struct Node *temp=head; head=head->next; free(temp); printf("Deleted %d", val); return; }
    struct Node *temp=head;
    while(temp->next!=NULL && temp->next->data!=val) temp=temp->next;
    if(temp->next==NULL) printf("Element not found");
    else { struct Node *del=temp->next; temp->next=del->next; free(del); printf("Deleted %d", val); }
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
        printf("\n1.Delete Front 2.Delete End 3.Delete Value 4.Display 5.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: deleteFront(); break;
            case 2: deleteEnd(); break;
            case 3: printf("Enter value to delete: "); scanf("%d",&val); deleteValue(val); break;
            case 4: display(); break;
            case 5: break;
            default: printf("Invalid choice");
        }
    } while(choice!=5);
    getch();
}
