#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

// Insert at beginning
void insertFront(int item) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("\nOVERFLOW");
        return;
    }
    newNode->data = item;
    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
        head = newNode;
    }
    printf("\nNode with value %d inserted at position 1", item);
}

// Insert at end
void insertEnd(int item) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("\nOVERFLOW");
        return;
    }
    newNode->data = item;
    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
        printf("\nNode with value %d inserted at position 1", item);
        return;
    }
    struct Node *last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    
    // find position
    int pos = 1;
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
        pos++;
    }
    printf("\nNode with value %d inserted at position %d", item, pos + 1);
}

// Insert after a given position
void insertAfter(int item, int loc) {
    if (head == NULL && loc > 1) {
        printf("\nCan't insert, position out of range");
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("\nOVERFLOW");
        return;
    }
    newNode->data = item;

    if (head == NULL) { // Empty list, insert at head
        newNode->next = newNode->prev = newNode;
        head = newNode;
        printf("\nNode with value %d inserted at position 1", item);
        return;
    }

    struct Node *temp = head;
    int i;
    for (i = 1; i < loc; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("\nCan't insert, position out of range");
            free(newNode);
            return;
        }
    }
    struct Node *nextNode = temp->next;
    newNode->next = nextNode;
    newNode->prev = temp;
    temp->next = newNode;
    nextNode->prev = newNode;

    printf("\nNode with value %d inserted at position %d", item, loc + 1);
}

// Delete from beginning
void deleteFront() {
    if (!head) {
        printf("\nList is empty");
        return;
    }
    int val = head->data;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node *last = head->prev;
        struct Node *temp = head;
        head = head->next;
        head->prev = last;
        last->next = head;
        free(temp);
    }
    printf("\nNode with value %d deleted from position 1", val);
}

// Delete from end
void deleteEnd() {
    if (!head) {
        printf("\nList is empty");
        return;
    }
    struct Node *last = head->prev;
    int val = last->data;
    if (last == head) { // Only one node
        free(head);
        head = NULL;
    } else {
        struct Node *prev = last->prev;
        prev->next = head;
        head->prev = prev;
        free(last);
    }

    // Find position
    int pos = 1;
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
        pos++;
    }
    printf("\nNode with value %d deleted from position %d", val, pos);
}

// Delete from a given position
void deleteValue(int loc) {
    if (!head) {
        printf("\nList is empty");
        return;
    }
    if (loc == 1) {
        deleteFront();
        return;
    }

    struct Node *temp = head;
    int i;
    for (i = 1; i < loc; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("\nCan't delete, position out of range");
            return;
        }
    }
    int val = temp->data;
    struct Node *prev = temp->prev;
    struct Node *next = temp->next;
    prev->next = next;
    next->prev = prev;
    free(temp);
    printf("\nNode with value %d deleted from position %d", val, loc);
}

// Search for a value
void search(int item) {
    if (!head) {
        printf("\nEmpty List");
        return;
    }
    struct Node *temp = head;
    int i = 1, found = 0;
    do {
        if (temp->data == item) {
            printf("\nItem %d found at position %d", item, i);
            found = 1;
            break;
        }
        temp = temp->next;
        i++;
    } while (temp != head);
    if (!found)
        printf("\nItem %d not found", item);
}

// Display the list
void display() {
    if (!head) {
        printf("\nList is empty");
        return;
    }
    struct Node *temp = head;
    printf("\nDoubly Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main menu
void main() {
    int choice, val, pos;
    clrscr();
    do {
        printf("\n===== Doubly Circular Linked List Menu =====\n");
        printf("1. Insert Front\n2. Insert End\n3. Insert After Position\n4. Delete Front\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insertAfter(val, pos);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteValue(pos);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
        getch();
        clrscr();
    } while (choice != 9);
}
