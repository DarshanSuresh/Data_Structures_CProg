#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertFront(int item) {
	struct Node *newNode;
	struct Node *temp;
	newNode = (struct Node *)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("\nOVERFLOW");
		return;
	}
	newNode->data = item;
	if (head == NULL) {
		head = newNode;
		newNode->next = head;
	}
	else {
		temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		newNode->next = head;
		temp->next = newNode;
		head = newNode;
	}
	printf("\nNode with value %d inserted at position 1", item);
}

// Insert at end
void insertEnd(int item) {
	struct Node *newNode;
	struct Node *temp;
	int pos;
	newNode = (struct Node *)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("\nOVERFLOW");
		return;
	}
	newNode->data = item;
	if (head == NULL) {
		head = newNode;
		newNode->next = head;
		printf("\nNode with value %d inserted at position 1", item);
	}
	else {
		temp = head;
		pos = 1;
		while (temp->next != head) {
			temp = temp->next;
			pos++;
		}
		temp->next = newNode;
		newNode->next = head;
		printf("\nNode with value %d inserted at position %d", item, pos + 1);
	}
}

// Insert after a given position
void insertAfter(int item, int loc) {
	struct Node *newNode;
	struct Node *temp;
	int i;
	newNode = (struct Node *)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("\nOVERFLOW");
		return;
	}
	newNode->data = item;
	if (loc == 1 && head == NULL) {
		head = newNode;
		newNode->next = head;
		printf("\nNode with value %d inserted at position 1", item);
		return;
	}
	temp = head;
	for (i = 1; i < loc; i++) {
		temp = temp->next;
		if (temp == head) {
			printf("\nCan't insert, position out of range");
			return;
		}
	}
	newNode->next = temp->next;
	temp->next = newNode;
	printf("\nNode with value %d inserted at position %d", item, loc + 1);
}

// Delete from beginning
void deleteFront() {
	struct Node *temp, *last;
	int val;
	if (head == NULL) {
		printf("\nList is empty");
		return;
	}
	val = head->data;
	if (head->next == head) {
		free(head);
		head = NULL;
	}
	else {
		temp = head;
		last = head;
		while (last->next != head) {
			last = last->next;
		}
		head = head->next;
		last->next = head;
		free(temp);
	}
	printf("\nNode with value %d deleted from position 1", val);
}

// Delete from end
void deleteEnd() {
	struct Node *temp, *prev;
	int val, pos;
	if (head == NULL) {
		printf("\nList is empty");
		return;
	}
	if (head->next == head) {
		val = head->data;
		free(head);
		head = NULL;
		printf("\nNode with value %d deleted from position 1", val);
	}
	else {
		temp = head;
		pos = 1;
		while (temp->next != head) {
			prev = temp;
			temp = temp->next;
			pos++;
		}
		val = temp->data;
		prev->next = head;
		free(temp);
		printf("\nNode with value %d deleted from position %d", val, pos);
	}
}

// Delete from a given position
void deleteValue(int loc) {
	struct Node *temp, *prev;
	int i, val;
	if (head == NULL) {
		printf("\nList is empty");
		return;
	}
	if (loc == 1) {
		deleteFront();
		return;
	}
	temp = head;
	for (i = 1; i < loc; i++) {
		prev = temp;
		temp = temp->next;
		if (temp == head) {
			printf("\nCan't delete, position out of range");
			return;
		}
	}
	val = temp->data;
	prev->next = temp->next;
	free(temp);
	printf("\nNode with value %d deleted from position %d", val, loc);
}

// Search for a value
void search(int item) {
	struct Node *temp;
	int i, found;
	if (head == NULL) {
		printf("\nEmpty List");
		return;
	}
	temp = head;
	i = 1;
	found = 0;
	do {
		if (temp->data == item) {
			printf("\nItem %d found at position %d", item, i);
			found = 1;
			break;
		}
		temp = temp->next;
		i++;
	} while (temp != head);
	if (!found) {
		printf("\nItem %d not found", item);
	}
}

// Display the list
void display() {
	struct Node *temp;
	if (head == NULL) {
		printf("\nList is empty");
		return;
	}
	temp = head;
	printf("\nCircular Linked List: ");
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
		printf("\n===== Circular Linked List Menu =====\n");
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
