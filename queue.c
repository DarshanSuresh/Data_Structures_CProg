/*
 * Queue - Data Structure Implementation in C
 * 
 * This program demonstrates queue operations using both array and linked list implementations:
 * - Enqueue operation (add element to rear)
 * - Dequeue operation (remove element from front)
 * - Front/Rear operations (view elements without removing)
 * - Circular queue implementation
 * - Priority queue implementation
 * - Queue applications (BFS traversal simulation)
 * 
 * Compilation: gcc -o queue queue.c
 * Execution: ./queue
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100

// ===== LINEAR QUEUE (ARRAY-BASED) =====

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} LinearQueue;

// Initialize linear queue
void initLinearQueue(LinearQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if linear queue is empty
bool isLinearQueueEmpty(LinearQueue* queue) {
    return queue->front == -1;
}

// Check if linear queue is full
bool isLinearQueueFull(LinearQueue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Enqueue operation for linear queue
bool enqueueLinear(LinearQueue* queue, int item) {
    if (isLinearQueueFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", item);
        return false;
    }
    
    if (isLinearQueueEmpty(queue)) {
        queue->front = 0;
    }
    queue->items[++queue->rear] = item;
    return true;
}

// Dequeue operation for linear queue
int dequeueLinear(LinearQueue* queue) {
    if (isLinearQueueEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from empty queue\n");
        return -1;
    }
    
    int item = queue->items[queue->front];
    
    if (queue->front == queue->rear) {
        // Queue becomes empty
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    
    return item;
}

// Get front element of linear queue
int frontLinear(LinearQueue* queue) {
    if (isLinearQueueEmpty(queue)) {
        printf("Queue is empty! No front element\n");
        return -1;
    }
    return queue->items[queue->front];
}

// Get rear element of linear queue
int rearLinear(LinearQueue* queue) {
    if (isLinearQueueEmpty(queue)) {
        printf("Queue is empty! No rear element\n");
        return -1;
    }
    return queue->items[queue->rear];
}

// Display linear queue
void displayLinearQueue(LinearQueue* queue) {
    if (isLinearQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue (front to rear): ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

// ===== CIRCULAR QUEUE (ARRAY-BASED) =====

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;

// Initialize circular queue
void initCircularQueue(CircularQueue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

// Check if circular queue is empty
bool isCircularQueueEmpty(CircularQueue* queue) {
    return queue->count == 0;
}

// Check if circular queue is full
bool isCircularQueueFull(CircularQueue* queue) {
    return queue->count == MAX_SIZE;
}

// Enqueue operation for circular queue
bool enqueueCircular(CircularQueue* queue, int item) {
    if (isCircularQueueFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", item);
        return false;
    }
    
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = item;
    queue->count++;
    return true;
}

// Dequeue operation for circular queue
int dequeueCircular(CircularQueue* queue) {
    if (isCircularQueueEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from empty queue\n");
        return -1;
    }
    
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;
    return item;
}

// Get front element of circular queue
int frontCircular(CircularQueue* queue) {
    if (isCircularQueueEmpty(queue)) {
        printf("Queue is empty! No front element\n");
        return -1;
    }
    return queue->items[queue->front];
}

// Get rear element of circular queue
int rearCircular(CircularQueue* queue) {
    if (isCircularQueueEmpty(queue)) {
        printf("Queue is empty! No rear element\n");
        return -1;
    }
    return queue->items[queue->rear];
}

// Display circular queue
void displayCircularQueue(CircularQueue* queue) {
    if (isCircularQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Circular Queue (front to rear): ");
    int i = queue->front;
    for (int count = 0; count < queue->count; count++) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

// ===== LINKED QUEUE =====

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} LinkedQueue;

// Initialize linked queue
void initLinkedQueue(LinkedQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Check if linked queue is empty
bool isLinkedQueueEmpty(LinkedQueue* queue) {
    return queue->front == NULL;
}

// Enqueue operation for linked queue
bool enqueueLinked(LinkedQueue* queue, int item) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        printf("Memory allocation failed! Cannot enqueue %d\n", item);
        return false;
    }
    
    newNode->data = item;
    newNode->next = NULL;
    
    if (isLinkedQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    return true;
}

// Dequeue operation for linked queue
int dequeueLinked(LinkedQueue* queue) {
    if (isLinkedQueueEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from empty queue\n");
        return -1;
    }
    
    QueueNode* temp = queue->front;
    int item = temp->data;
    
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;  // Queue becomes empty
    }
    
    free(temp);
    return item;
}

// Get front element of linked queue
int frontLinked(LinkedQueue* queue) {
    if (isLinkedQueueEmpty(queue)) {
        printf("Queue is empty! No front element\n");
        return -1;
    }
    return queue->front->data;
}

// Get rear element of linked queue
int rearLinked(LinkedQueue* queue) {
    if (isLinkedQueueEmpty(queue)) {
        printf("Queue is empty! No rear element\n");
        return -1;
    }
    return queue->rear->data;
}

// Display linked queue
void displayLinkedQueue(LinkedQueue* queue) {
    if (isLinkedQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Linked Queue (front to rear): ");
    QueueNode* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free linked queue memory
void freeLinkedQueue(LinkedQueue* queue) {
    while (!isLinkedQueueEmpty(queue)) {
        dequeueLinked(queue);
    }
}

// ===== PRIORITY QUEUE =====

typedef struct {
    int data;
    int priority;
} PriorityItem;

typedef struct {
    PriorityItem items[MAX_SIZE];
    int size;
} PriorityQueue;

// Initialize priority queue
void initPriorityQueue(PriorityQueue* pq) {
    pq->size = 0;
}

// Check if priority queue is empty
bool isPriorityQueueEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

// Check if priority queue is full
bool isPriorityQueueFull(PriorityQueue* pq) {
    return pq->size == MAX_SIZE;
}

// Enqueue with priority (higher priority value = higher priority)
bool enqueuePriority(PriorityQueue* pq, int data, int priority) {
    if (isPriorityQueueFull(pq)) {
        printf("Priority Queue Overflow! Cannot enqueue %d\n", data);
        return false;
    }
    
    int i = pq->size;
    
    // Find correct position to insert (maintain priority order)
    while (i > 0 && pq->items[i - 1].priority < priority) {
        pq->items[i] = pq->items[i - 1];
        i--;
    }
    
    pq->items[i].data = data;
    pq->items[i].priority = priority;
    pq->size++;
    return true;
}

// Dequeue highest priority element
int dequeuePriority(PriorityQueue* pq) {
    if (isPriorityQueueEmpty(pq)) {
        printf("Priority Queue Underflow! Cannot dequeue from empty queue\n");
        return -1;
    }
    
    int data = pq->items[0].data;
    
    // Shift elements
    for (int i = 0; i < pq->size - 1; i++) {
        pq->items[i] = pq->items[i + 1];
    }
    pq->size--;
    
    return data;
}

// Display priority queue
void displayPriorityQueue(PriorityQueue* pq) {
    if (isPriorityQueueEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        return;
    }
    
    printf("Priority Queue (data:priority): ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d:%d ", pq->items[i].data, pq->items[i].priority);
    }
    printf("\n");
}

// ===== QUEUE APPLICATIONS =====

// Simulate BFS traversal using queue
void simulateBFS() {
    printf("\n=== BFS Traversal Simulation ===\n");
    printf("Simulating BFS on a sample graph:\n");
    printf("Graph: 1 -> 2, 3\n");
    printf("       2 -> 4, 5\n");
    printf("       3 -> 6\n");
    printf("       4, 5, 6 -> (no children)\n\n");
    
    LinearQueue queue;
    initLinearQueue(&queue);
    
    printf("Starting BFS from vertex 1:\n");
    enqueueLinear(&queue, 1);
    printf("Enqueue: 1\n");
    
    while (!isLinearQueueEmpty(&queue)) {
        int vertex = dequeueLinear(&queue);
        printf("Visit: %d\n", vertex);
        
        // Add children based on our sample graph
        switch (vertex) {
            case 1:
                enqueueLinear(&queue, 2);
                enqueueLinear(&queue, 3);
                printf("Enqueue: 2, 3\n");
                break;
            case 2:
                enqueueLinear(&queue, 4);
                enqueueLinear(&queue, 5);
                printf("Enqueue: 4, 5\n");
                break;
            case 3:
                enqueueLinear(&queue, 6);
                printf("Enqueue: 6\n");
                break;
        }
        
        if (!isLinearQueueEmpty(&queue)) {
            printf("Queue state: ");
            displayLinearQueue(&queue);
        }
        printf("\n");
    }
    
    printf("BFS traversal completed!\n");
}

int main() {
    int choice, item, priority, result;
    LinearQueue linearQueue;
    CircularQueue circularQueue;
    LinkedQueue linkedQueue;
    PriorityQueue priorityQueue;
    
    printf("=== Queue Data Structure Demo ===\n\n");
    
    // Initialize queues
    initLinearQueue(&linearQueue);
    initCircularQueue(&circularQueue);
    initLinkedQueue(&linkedQueue);
    initPriorityQueue(&priorityQueue);
    
    do {
        printf("\n--- Queue Operations Menu ---\n");
        printf("Linear Queue:\n");
        printf("1. Enqueue to Linear Queue\n");
        printf("2. Dequeue from Linear Queue\n");
        printf("3. Display Linear Queue\n");
        printf("\nCircular Queue:\n");
        printf("4. Enqueue to Circular Queue\n");
        printf("5. Dequeue from Circular Queue\n");
        printf("6. Display Circular Queue\n");
        printf("\nLinked Queue:\n");
        printf("7. Enqueue to Linked Queue\n");
        printf("8. Dequeue from Linked Queue\n");
        printf("9. Display Linked Queue\n");
        printf("\nPriority Queue:\n");
        printf("10. Enqueue to Priority Queue\n");
        printf("11. Dequeue from Priority Queue\n");
        printf("12. Display Priority Queue\n");
        printf("\nApplications:\n");
        printf("13. BFS Simulation\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                if (enqueueLinear(&linearQueue, item)) {
                    printf("Element %d enqueued successfully!\n", item);
                }
                break;
                
            case 2:
                result = dequeueLinear(&linearQueue);
                if (result != -1) {
                    printf("Dequeued element: %d\n", result);
                }
                break;
                
            case 3:
                displayLinearQueue(&linearQueue);
                break;
                
            case 4:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                if (enqueueCircular(&circularQueue, item)) {
                    printf("Element %d enqueued successfully!\n", item);
                }
                break;
                
            case 5:
                result = dequeueCircular(&circularQueue);
                if (result != -1) {
                    printf("Dequeued element: %d\n", result);
                }
                break;
                
            case 6:
                displayCircularQueue(&circularQueue);
                break;
                
            case 7:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                if (enqueueLinked(&linkedQueue, item)) {
                    printf("Element %d enqueued successfully!\n", item);
                }
                break;
                
            case 8:
                result = dequeueLinked(&linkedQueue);
                if (result != -1) {
                    printf("Dequeued element: %d\n", result);
                }
                break;
                
            case 9:
                displayLinkedQueue(&linkedQueue);
                break;
                
            case 10:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                printf("Enter priority (higher value = higher priority): ");
                scanf("%d", &priority);
                if (enqueuePriority(&priorityQueue, item, priority)) {
                    printf("Element %d with priority %d enqueued successfully!\n", item, priority);
                }
                break;
                
            case 11:
                result = dequeuePriority(&priorityQueue);
                if (result != -1) {
                    printf("Dequeued highest priority element: %d\n", result);
                }
                break;
                
            case 12:
                displayPriorityQueue(&priorityQueue);
                break;
                
            case 13:
                simulateBFS();
                break;
                
            case 0:
                printf("Freeing memory and exiting...\n");
                freeLinkedQueue(&linkedQueue);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}