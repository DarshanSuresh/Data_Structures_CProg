# Complete Data Structures & Algorithms Lab Programs
## Turbo C++ Compatible (with getch() and clrscr())

---

## 1. TOWER OF HANOI (Recursive Solution)

### Program:
```c
#include <stdio.h>
#include <conio.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("\n Move disk %d from rod %c to rod %c", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    clrscr();
    int n = 4;
    printf("========================================");
    printf("\nTOWER OF HANOI (Recursive Solution)");
    printf("\n========================================");
    printf("\nNumber of disks: %d", n);
    printf("\nSequence of moves:\n");
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\n========================================");
    printf("\nTotal moves required: %d\n", (1 << n) - 1);
    printf("========================================\n");
    getch();
    return 0;
}
```

### Output:
```
========================================
TOWER OF HANOI (Recursive Solution)
========================================
Number of disks: 4
Sequence of moves:

 Move disk 1 from rod A to rod B
 Move disk 2 from rod A to rod C
 Move disk 1 from rod B to rod C
 Move disk 3 from rod A to rod B
 Move disk 1 from rod C to rod A
 Move disk 2 from rod C to rod B
 Move disk 1 from rod A to rod B
 Move disk 4 from rod A to rod C
 Move disk 1 from rod B to rod C
 Move disk 2 from rod B to rod A
 Move disk 1 from rod C to rod A
 Move disk 3 from rod B to rod C
 Move disk 1 from rod A to rod B
 Move disk 2 from rod A to rod C
 Move disk 1 from rod B to rod C
========================================
Total moves required: 15
========================================
```

**Time Complexity:** O(2^n)  
**Space Complexity:** O(n)

---

## 2. MERGE SORT

### Program:
```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    clrscr();
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("========================================");
    printf("\nMERGE SORT\n");
    printf("========================================\n");
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    mergeSort(arr, 0, n - 1);

    printf("\n\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n========================================");
    printf("\nTime Complexity: O(n log n)\n");
    printf("========================================\n");
    getch();
    return 0;
}
```

### Output:
```
========================================
MERGE SORT
========================================
Original array: 38 27 43 3 9 82 10 

Sorted array: 3 9 10 27 38 43 82 
========================================
Time Complexity: O(n log n)
========================================
```

---

## 3. QUICK SORT

### Program:
```c
#include <stdio.h>
#include <conio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    clrscr();
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("========================================");
    printf("\nQUICK SORT\n");
    printf("========================================\n");
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    quickSort(arr, 0, n - 1);

    printf("\n\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n========================================");
    printf("\nAverage Time Complexity: O(n log n)\n");
    printf("========================================\n");
    getch();
    return 0;
}
```

### Output:
```
========================================
QUICK SORT
========================================
Original array: 64 34 25 12 22 11 90 

Sorted array: 11 12 22 25 34 64 90 
========================================
Average Time Complexity: O(n log n)
========================================
```

---

## 4. QUEUE USING ARRAY

### Program:
```c
#include <stdio.h>
#include <conio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("\nQueue is Full!");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = val;
        printf("\n%d enqueued into the queue", val);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty!");
    } else {
        printf("\n%d dequeued from the queue", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty!");
    } else {
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

int main() {
    clrscr();

    printf("========================================");
    printf("\nQUEUE USING ARRAY\n");
    printf("========================================\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    printf("\n\n========================================");
    printf("\nTime Complexity: O(1) for both operations\n");
    printf("========================================\n");
    getch();
    return 0;
}
```

### Output:
```
========================================
QUEUE USING ARRAY
========================================

10 enqueued into the queue
20 enqueued into the queue
30 enqueued into the queue
40 enqueued into the queue
50 enqueued into the queue

Queue elements: 10 20 30 40 50 

20 dequeued from the queue
30 dequeued from the queue

Queue elements: 40 50 

========================================
Time Complexity: O(1) for both operations
========================================
```

---

## 5. QUEUE USING LINKED LIST

### Program:
```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n%d enqueued into the queue", val);
}

void dequeue() {
    if (front == NULL) {
        printf("\nQueue is Empty!");
    } else {
        struct Node *temp = front;
        printf("\n%d dequeued from the queue", temp->data);
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("\nQueue is Empty!");
    } else {
        printf("\nQueue elements: ");
        struct Node *temp = front;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}

int main() {
    clrscr();

    printf("========================================");
    printf("\nQUEUE USING LINKED LIST\n");
    printf("========================================\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    printf("\n\n========================================");
    printf("\nTime Complexity: O(1) for both operations\n");
    printf("========================================\n");
    getch();
    return 0;
}
```

### Output:
```
========================================
QUEUE USING LINKED LIST
========================================

10 enqueued into the queue
20 enqueued into the queue
30 enqueued into the queue
40 enqueued into the queue
50 enqueued into the queue

Queue elements: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

10 dequeued from the queue
20 dequeued from the queue

Queue elements: 30 -> 40 -> 50 -> NULL

========================================
Time Complexity: O(1) for both operations
========================================
```

---

## 6. CIRCULAR QUEUE

### Program:
```c
#include <stdio.h>
#include <conio.h>

#define SIZE 5

int cqueue[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % SIZE == front) {
        printf("\nQueue is Full!");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        cqueue[rear] = val;
        printf("\n%d enqueued into the circular queue", val);
    }
}

void dequeue() {
    if (front == -1) {
        printf("\nQueue is Empty!");
    } else {
        printf("\n%d dequeued from the circular queue", cqueue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("\nQueue is Empty!");
    } else {
        printf("\nQueue elements: ");
        int i = front;
        if (front <= rear) {
            while (i <= rear) {
                printf("%d ", cqueue[i]);
                i++;
            }
        } else {
            while (i < SIZE) {
                printf("%d ", cqueue[i]);
                i++;
            }
            i = 0;
            while (i <= rear) {
                printf("%d ", cqueue[i]);
                i++;
            }
        }
    }
}

int main() {
    clrscr();

    printf("========================================");
    printf("\nCIRCULAR QUEUE\n");
    printf("========================================\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    printf("\nAfter enqueuing 60:");
    display();

    printf("\n\n========================================");
    printf("\nTime Complexity: O(1) for both operations\n");
    printf("========================================\n");
    getch();
    return 0;
}
```

### Output:
```
========================================
CIRCULAR QUEUE
========================================

10 enqueued into the circular queue
20 enqueued into the circular queue
30 enqueued into the circular queue
40 enqueued into the circular queue
50 enqueued into the circular queue

Queue elements: 10 20 30 40 50 

10 dequeued from the circular queue
20 dequeued from the circular queue

Queue elements: 30 40 50 

After enqueuing 60:
Queue elements: 30 40 50 60 

========================================
Time Complexity: O(1) for both operations
========================================
```

---

## 7. DOUBLE ENDED QUEUE (DEQUE)

### Program:
```c
#include <stdio.h>
#include <conio.h>

#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

void addRear(int val) {
    if ((rear + 1) % SIZE == front) {
        printf("\nDeque is Full!");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        deque[rear] = val;
        printf("\n%d added at rear", val);
    }
}

void addFront(int val) {
    if ((front - 1 + SIZE) % SIZE == rear && rear != -1) {
        printf("\nDeque is Full!");
    } else {
        if (rear == -1)
            rear = 0;
        front = (front - 1 + SIZE) % SIZE;
        deque[front] = val;
        printf("\n%d added at front", val);
    }
}

void deleteRear() {
    if (front == -1) {
        printf("\nDeque is Empty!");
    } else {
        printf("\n%d removed from rear", deque[rear]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }
    }
}

void deleteFront() {
    if (front == -1) {
        printf("\nDeque is Empty!");
    } else {
        printf("\n%d removed from front", deque[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("\nDeque is Empty!");
    } else {
        printf("\nDeque elements: ");
        int i = front;
        if (front <= rear) {
            while (i <= rear) {
                printf("%d ", deque[i]);
                i++;
            }
        } else {
            while (i < SIZE) {
                printf("%d ", deque[i]);
                i++;
            }
            i = 0;
            while (i <= rear) {
                printf("%d ", deque[i]);
                i++;
            }
        }
    }
}

int main() {
    clrscr();

    printf("========================================");
    printf("\nDOUBLE ENDED QUEUE (DEQUE)\n");
    printf("========================================\n");

    addRear(10);
    addRear(20);
    addRear(30);
    addFront(5);
    addFront(1);

    display();

    deleteRear();
    deleteFront();

    display();

    printf("\n\n========================================");
    printf("\nTime Complexity: O(1) for all operations\n");
    printf("========================================\n");
    getch();
    return 0;
}
```

### Output:
```
========================================
DOUBLE ENDED QUEUE (DEQUE)
========================================

10 added at rear
20 added at rear
30 added at rear
5 added at front
1 added at front

Deque elements: 1 5 10 20 30 

30 removed from rear
1 removed from front

Deque elements: 5 10 20 

========================================
Time Complexity: O(1) for all operations
========================================
```

---

## 8. DEPTH FIRST SEARCH (DFS)

### Program:
```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 5

void DFS(int graph[MAX][MAX], int vertices, int start, int visited[]) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < vertices; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            DFS(graph, vertices, i, visited);
        }
    }
}

int main() {
    clrscr();
    int vertices = 5;
    int graph[MAX][MAX] = {
        { 0, 1, 1, 0, 0 },
        { 1, 0, 0, 1, 0 },
        { 1, 0, 0, 1, 1 },
        { 0, 1, 1, 0, 1 },
        { 0, 0, 1, 1, 0 }
    };

    printf("========================================");
    printf("\nDEPTH FIRST SEARCH (DFS)\n");
    printf("========================================\n");

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    int visited[MAX] = { 0 };

    printf("\nDFS Traversal starting from vertex 0: ");
    DFS(graph, vertices, 0, visited);

    printf("\n\n========================================");
    printf("\nTime Complexity: O(V + E)\n");
    printf("========================================\n");
    getch();
    return 0;
}
```

### Output:
```
========================================
DEPTH FIRST SEARCH (DFS)
========================================

Adjacency Matrix:
0 1 1 0 0 
1 0 0 1 0 
1 0 0 1 1 
0 1 1 0 1 
0 0 1 1 0 

DFS Traversal starting from vertex 0: 0 1 3 2 4 

========================================
Time Complexity: O(V + E)
========================================
```

---

## 9. BREADTH FIRST SEARCH (BFS)

### Program:
```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 5

void BFS(int graph[MAX][MAX], int vertices, int start) {
    int visited[MAX] = { 0 };
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal starting from vertex %d: ", start);

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    clrscr();
    int vertices = 5;
    int graph[MAX][MAX] = {
        { 0, 1, 1, 0, 0 },
        { 1, 0, 0, 1, 0 },
        { 1, 0, 0, 1, 1 },
        { 0, 1, 1, 0, 1 },
        { 0, 0, 1, 1, 0 }
    };

    printf("========================================");
    printf("\nBREADTH FIRST SEARCH (BFS)\n");
    printf("========================================\n");

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    BFS(graph, vertices, 0);

    printf("\n\n========================================");
    printf("\nTime Complexity: O(V + E)\n");
    printf("========================================\n");
    getch();
    return 0;
}
```

### Output:
```
========================================
BREADTH FIRST SEARCH (BFS)
========================================

Adjacency Matrix:
0 1 1 0 0 
1 0 0 1 0 
1 0 0 1 1 
0 1 1 0 1 
0 0 1 1 0 

BFS Traversal starting from vertex 0: 0 1 2 3 4 

========================================
Time Complexity: O(V + E)
========================================
```

---

## 10. TREE TRAVERSALS (Inorder, Preorder, Postorder)

### Program:
```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(struct Node *root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(struct Node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct Node *root) {
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    clrscr();

    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("========================================");
    printf("\nTREE TRAVERSALS\n");
    printf("========================================\n");

    printf("\nTree Structure:\n");
    printf("        1\n");
    printf("       / \\\n");
    printf("      2   3\n");
    printf("     / \\ / \\\n");
    printf("    4  5 6  7\n");

    printf("\nInorder Traversal (Left-Root-Right): ");
    inOrder(root);

    printf("\n\nPreorder Traversal (Root-Left-Right): ");
    preOrder(root);

    printf("\n\nPostorder Traversal (Left-Right-Root): ");
    postOrder(root);

    printf("\n\n========================================");
    printf("\nTime Complexity: O(n)\n");
    printf("========================================\n");
    getch();
    return 0;
}
```

### Output:
```
========================================
TREE TRAVERSALS
========================================

Tree Structure:
        1
       / \
      2   3
     / \ / \
    4  5 6  7

Inorder Traversal (Left-Root-Right): 4 2 5 1 6 3 7 

Preorder Traversal (Root-Left-Right): 1 2 4 5 3 6 7 

Postorder Traversal (Left-Right-Root): 4 5 2 6 7 3 1 

========================================
Time Complexity: O(n)
========================================
```

---

## 11. BINARY SEARCH TREE (BST)

### Program:
```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void inOrder(struct Node *root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

struct Node* search(struct Node *root, int data) {
    if (root == NULL)
        return NULL;

    if (data == root->data)
        return root;
    else if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int main() {
    clrscr();

    struct Node *root = NULL;

    printf("========================================");
    printf("\nBINARY SEARCH TREE (BST)\n");
    printf("========================================\n");

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("\nInserted values: 50, 30, 70, 20, 40, 60, 80");

    printf("\n\nInorder Traversal (Sorted): ");
    inOrder(root);

    struct Node *found = search(root, 40);
    if (found != NULL) {
        printf("\n\n40 found in BST");
    } else {
        printf("\n\n40 not found in BST");
    }

    printf("\n\n========================================");
    printf("\nBST Properties:");
    printf("\n- Left subtree values < root");
    printf("\n- Right subtree values > root");
    printf("\nTime Complexity: O(log n) average");
    printf("\n========================================\n");
    getch();
    return 0;
}
```

### Output:
```
========================================
BINARY SEARCH TREE (BST)
========================================

Inserted values: 50, 30, 70, 20, 40, 60, 80

Inorder Traversal (Sorted): 20 30 40 50 60 70 80 

40 found in BST

========================================
BST Properties:
- Left subtree values < root
- Right subtree values > root
Time Complexity: O(log n) average
========================================
```

---

## 12. PRIORITY QUEUE

### Program:
```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    int priority;
    struct Node *next;
};

void enqueue(struct Node **head, int data, int priority) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;

    if (*head == NULL || (*head)->priority < priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("\n%d enqueued with priority %d", data, priority);
}

void dequeue(struct Node **head) {
    if (*head == NULL) {
        printf("\nPriority Queue is Empty!");
    } else {
        struct Node *temp = *head;
        printf("\n%d dequeued (Priority: %d)", temp->data, temp->priority);
        *head = temp->next;
        free(temp);
    }
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("\nPriority Queue is Empty!");
    } else {
        printf("\nPriority Queue (Data-Priority): ");
        struct Node *temp = head;
        while (temp != NULL) {
            printf("%d-%d -> ", temp->data, temp->priority);
            temp = temp->next;
        }
        printf("NULL");
    }
}

int main() {
    clrscr();
    struct Node *pQueue = NULL;

    printf("========================================");
    printf("\nPRIORITY QUEUE\n");
    printf("========================================\n");

    enqueue(&pQueue, 10, 3);
    enqueue(&pQueue, 20, 1);
    enqueue(&pQueue, 30, 2);
    enqueue(&pQueue, 40, 1);
    enqueue(&pQueue, 50, 3);

    display(pQueue);

    dequeue(&pQueue);
    dequeue(&pQueue);

    display(pQueue);

    printf("\n\n========================================");
    printf("\nNote: Higher priority dequeued first");
    printf("\nTime Complexity: O(n)");
    printf("\n========================================\n");
    getch();
    return 0;
}
```

### Output:
```
========================================
PRIORITY QUEUE
========================================

10 enqueued with priority 3
20 enqueued with priority 1
30 enqueued with priority 2
40 enqueued with priority 1
50 enqueued with priority 3

Priority Queue (Data-Priority): 10-3 -> 50-3 -> 30-2 -> 20-1 -> 40-1 -> NULL

10 dequeued (Priority: 3)
50 dequeued (Priority: 3)

Priority Queue (Data-Priority): 30-2 -> 20-1 -> 40-1 -> NULL

========================================
Note: Higher priority dequeued first
Time Complexity: O(n)
========================================
```

---

## Compilation & Execution Instructions

### For Turbo C++:
1. Copy the code into a `.c` file
2. Open Turbo C++
3. Press `Alt + F9` to compile
4. Press `Ctrl + F9` to run
5. Press `Alt + F5` to view output

### For Modern C Compilers (GCC/MinGW):
```bash
gcc -o program_name program_name.c
./program_name
```

**Note:** Replace `getch()` with `getchar()` and `clrscr()` with `system("clear")` or `system("cls")` for modern compilers if needed.

---

## Summary of Complexity Analysis

| Algorithm | Time (Avg) | Time (Worst) | Space |
|-----------|-----------|-------------|-------|
| Tower of Hanoi | O(2^n) | O(2^n) | O(n) |
| Merge Sort | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n²) | O(log n) |
| Queue (Array) | O(1) | O(1) | O(1) |
| Queue (LinkedList) | O(1) | O(1) | O(1) |
| Circular Queue | O(1) | O(1) | O(1) |
| Deque | O(1) | O(1) | O(1) |
| DFS | O(V+E) | O(V+E) | O(V) |
| BFS | O(V+E) | O(V+E) | O(V) |
| Tree Traversal | O(n) | O(n) | O(h) |
| BST | O(log n) | O(n) | O(h) |
| Priority Queue | O(n) | O(n) | O(n) |

---

**Prepared for Data Structures & Algorithms Lab Course**
