/*
 * Linked Lists - Data Structure Implementation in C
 * 
 * This program demonstrates singly linked list operations including:
 * - Node creation and initialization
 * - Insertion (at beginning, end, and specific position)
 * - Deletion (at beginning, end, and specific position)
 * - Traversal and display
 * - Search and count operations
 * - List reversal
 * 
 * Compilation: gcc -o linked_lists linked_lists.c
 * Execution: ./linked_lists
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Linked List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

// Function to insert node at the beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return head;
    
    newNode->next = head;
    return newNode;  // New head
}

// Function to insert node at the end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return head;
    
    if (head == NULL) {
        return newNode;
    }
    
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert node at specific position (0-indexed)
Node* insertAtPosition(Node* head, int data, int position) {
    if (position < 0) {
        printf("Invalid position! Position should be >= 0\n");
        return head;
    }
    
    if (position == 0) {
        return insertAtBeginning(head, data);
    }
    
    Node* newNode = createNode(data);
    if (!newNode) return head;
    
    Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Position out of bounds! Inserting at end.\n");
        free(newNode);
        return insertAtEnd(head, data);
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete node at the beginning
Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return head;
    }
    
    Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from beginning.\n");
    return head;
}

// Function to delete node at the end
Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return head;
    }
    
    if (head->next == NULL) {
        free(head);
        printf("Last node deleted.\n");
        return NULL;
    }
    
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    free(current->next);
    current->next = NULL;
    printf("Node deleted from end.\n");
    return head;
}

// Function to delete node at specific position (0-indexed)
Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return head;
    }
    
    if (position < 0) {
        printf("Invalid position! Position should be >= 0\n");
        return head;
    }
    
    if (position == 0) {
        return deleteAtBeginning(head);
    }
    
    Node* current = head;
    for (int i = 0; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }
    
    if (current->next == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }
    
    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node deleted at position %d.\n", position);
    return head;
}

// Function to search for an element
int searchElement(Node* head, int key) {
    Node* current = head;
    int position = 0;
    
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;  // Not found
}

// Function to count nodes in the list
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;  // New head
}

// Function to find the middle element
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Function to detect cycle in linked list (Floyd's algorithm)
bool hasCycle(Node* head) {
    if (head == NULL || head->next == NULL) return false;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;  // Cycle detected
        }
    }
    
    return false;  // No cycle
}

// Function to free the entire list
void freeList(Node* head) {
    Node* current = head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = NULL;
    int choice, data, position, key, result;
    
    printf("=== Linked List Operations Demo ===\n\n");
    
    // Initialize with some sample data
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    
    printf("Initial linked list:\n");
    displayList(head);
    
    do {
        printf("\n--- Linked List Operations Menu ---\n");
        printf("1. Display List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Position\n");
        printf("8. Search Element\n");
        printf("9. Count Nodes\n");
        printf("10. Reverse List\n");
        printf("11. Find Middle Element\n");
        printf("12. Check for Cycle\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayList(head);
                break;
                
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printf("Node inserted at beginning.\n");
                displayList(head);
                break;
                
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("Node inserted at end.\n");
                displayList(head);
                break;
                
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (0-indexed): ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                displayList(head);
                break;
                
            case 5:
                head = deleteAtBeginning(head);
                displayList(head);
                break;
                
            case 6:
                head = deleteAtEnd(head);
                displayList(head);
                break;
                
            case 7:
                printf("Enter position to delete (0-indexed): ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                displayList(head);
                break;
                
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = searchElement(head, key);
                if (result != -1) {
                    printf("Element %d found at position %d\n", key, result);
                } else {
                    printf("Element %d not found in list\n", key);
                }
                break;
                
            case 9:
                result = countNodes(head);
                printf("Number of nodes in list: %d\n", result);
                break;
                
            case 10:
                head = reverseList(head);
                printf("List reversed successfully!\n");
                displayList(head);
                break;
                
            case 11: {
                Node* middle = findMiddle(head);
                if (middle) {
                    printf("Middle element: %d\n", middle->data);
                } else {
                    printf("List is empty!\n");
                }
                break;
            }
                
            case 12:
                if (hasCycle(head)) {
                    printf("Cycle detected in the list!\n");
                } else {
                    printf("No cycle detected in the list.\n");
                }
                break;
                
            case 0:
                printf("Freeing list and exiting...\n");
                freeList(head);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}