#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insertion
void insertFront(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) head = newNode;
    else {
        struct Node *temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void insertAfter(int val, int after) {
    struct Node *temp = head;
    while(temp != NULL && temp->data != after) temp = temp->next;
    if(temp == NULL) printf("Element %d not found\n", after);
    else {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Deletion
void deleteFront() {
    if(head == NULL) printf("List is empty\n");
    else {
        struct Node *temp = head;
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

void deleteEnd() {
    if(head == NULL) printf("List is empty\n");
    else if(head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        printf("Deleted element: %d\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteValue(int val) {
    if(head == NULL) { printf("List is empty\n"); return; }
    if(head->data == val) { struct Node *temp=head; head=head->next; free(temp); printf("Deleted %d\n", val); return; }
    struct Node *temp=head;
    while(temp->next != NULL && temp->next->data != val) temp = temp->next;
    if(temp->next == NULL) printf("Element %d not found\n", val);
    else { struct Node *del = temp->next; temp->next = del->next; free(del); printf("Deleted %d\n", val); }
}

// Search
void search(int val) {
    struct Node *temp = head;
    int pos = 1, found = 0;
    while(temp != NULL) {
        if(temp->data == val) { found = 1; break; }
        temp = temp->next; pos++;
    }
    if(found) printf("Element %d found at position %d\n", val, pos);
    else printf("Element %d not found\n", val);
}

// Display
void display() {
    struct Node *temp = head;
    if(temp == NULL) { printf("List is empty\n"); return; }
    printf("Linked list: ");
    while(temp != NULL) { printf("%d ", temp->data); temp = temp->next; }
    printf("\n");
}

void main() {
    int choice, val, after;
    clrscr();
    do {
        printf("\n===== Linked List Menu =====\n");
        printf("1. Insert Front\n2. Insert End\n3. Insert After\n4. Delete Front\n5. Delete End\n6. Delete Value\n7. Search\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d",&val); insertFront(val); break;
            case 2: printf("Enter value: "); scanf("%d",&val); insertEnd(val); break;
            case 3: printf("Enter value and after element: "); scanf("%d %d",&val,&after); insertAfter(val, after); break;
            case 4: deleteFront(); break;
            case 5: deleteEnd(); break;
            case 6: printf("Enter value to delete: "); scanf("%d",&val); deleteValue(val); break;
            case 7: printf("Enter value to search: "); scanf("%d",&val); search(val); break;
            case 8: display(); break;
            case 9: break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 9);
    getch();
}
