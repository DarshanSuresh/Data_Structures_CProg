/*
 * Binary Trees - Data Structure Implementation in C
 * 
 * This program demonstrates binary tree operations including:
 * - Binary tree creation and insertion
 * - Tree traversals (Inorder, Preorder, Postorder, Level-order)
 * - Tree search operations
 * - Tree properties (height, count, etc.)
 * - Binary Search Tree (BST) operations
 * - Tree deletion and balancing concepts
 * 
 * Compilation: gcc -o trees trees.c
 * Execution: ./trees
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Tree node structure
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Queue node for level-order traversal
typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// ===== QUEUE OPERATIONS FOR LEVEL-ORDER TRAVERSAL =====

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, TreeNode* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

TreeNode* dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) return NULL;
    
    QueueNode* temp = queue->front;
    TreeNode* treeNode = temp->treeNode;
    
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    return treeNode;
}

// ===== BINARY TREE OPERATIONS =====

// Create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert node in BST
TreeNode* insertBST(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else if (data > root->data) {
        root->right = insertBST(root->right, data);
    }
    
    return root;
}

// Search in BST
TreeNode* searchBST(TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    
    if (key < root->data) {
        return searchBST(root->left, key);
    }
    
    return searchBST(root->right, key);
}

// Find minimum value node in BST
TreeNode* findMin(TreeNode* root) {
    if (root == NULL) return NULL;
    
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Find maximum value node in BST
TreeNode* findMax(TreeNode* root) {
    if (root == NULL) return NULL;
    
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Delete node from BST
TreeNode* deleteBST(TreeNode* root, int key) {
    if (root == NULL) return root;
    
    if (key < root->data) {
        root->left = deleteBST(root->left, key);
    } else if (key > root->data) {
        root->right = deleteBST(root->right, key);
    } else {
        // Node to be deleted found
        
        // Case 1: Node with no child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: Node with one child
        else if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Node with two children
        else {
            TreeNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
    }
    return root;
}

// ===== TREE TRAVERSALS =====

// Inorder traversal (Left, Root, Right)
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Level-order traversal (Breadth-First)
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, root);
    
    while (!isQueueEmpty(&queue)) {
        TreeNode* current = dequeue(&queue);
        printf("%d ", current->data);
        
        if (current->left != NULL) {
            enqueue(&queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(&queue, current->right);
        }
    }
}

// ===== TREE PROPERTIES =====

// Calculate height of tree
int treeHeight(TreeNode* root) {
    if (root == NULL) return -1;
    
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Count total nodes in tree
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeafNodes(TreeNode* root) {
    if (root == NULL) return 0;
    
    if (root->left == NULL && root->right == NULL) return 1;
    
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Check if tree is a valid BST
bool isBST(TreeNode* root, int min, int max) {
    if (root == NULL) return true;
    
    if (root->data <= min || root->data >= max) return false;
    
    return isBST(root->left, min, root->data) && 
           isBST(root->right, root->data, max);
}

// Check if two trees are identical
bool areIdentical(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    
    if (root1 == NULL || root2 == NULL) return false;
    
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

// Calculate diameter of tree (longest path between any two nodes)
int calculateDiameter(TreeNode* root, int* height) {
    if (root == NULL) {
        *height = 0;
        return 0;
    }
    
    int leftHeight = 0, rightHeight = 0;
    int leftDiameter = calculateDiameter(root->left, &leftHeight);
    int rightDiameter = calculateDiameter(root->right, &rightHeight);
    
    *height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    
    int currentDiameter = leftHeight + rightHeight + 1;
    int maxDiameter = leftDiameter > rightDiameter ? leftDiameter : rightDiameter;
    return currentDiameter > maxDiameter ? currentDiameter : maxDiameter;
}

// Print tree structure
void printTree(TreeNode* root, int space) {
    const int COUNT = 10;
    
    if (root == NULL) return;
    
    space += COUNT;
    
    printTree(root->right, space);
    
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    
    printTree(root->left, space);
}

// Free tree memory
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Create a sample tree for demonstration
TreeNode* createSampleTree() {
    TreeNode* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);
    return root;
}

int main() {
    TreeNode* bstRoot = NULL;
    TreeNode* sampleRoot = NULL;
    int choice, value, result, height;
    
    printf("=== Binary Trees and BST Demo ===\n\n");
    
    // Create sample tree
    sampleRoot = createSampleTree();
    printf("Sample tree created:\n");
    printf("        50\n");
    printf("       /  \\\n");
    printf("      30   70\n");
    printf("     / \\   / \\\n");
    printf("    20 40 60 80\n\n");
    
    do {
        printf("\n--- Binary Tree Operations Menu ---\n");
        printf("BST Operations:\n");
        printf("1. Insert into BST\n");
        printf("2. Search in BST\n");
        printf("3. Delete from BST\n");
        printf("4. Display BST\n");
        printf("\nTree Traversals (Sample Tree):\n");
        printf("5. Inorder Traversal\n");
        printf("6. Preorder Traversal\n");
        printf("7. Postorder Traversal\n");
        printf("8. Level-order Traversal\n");
        printf("\nTree Properties:\n");
        printf("9. Tree Height\n");
        printf("10. Count Nodes\n");
        printf("11. Count Leaf Nodes\n");
        printf("12. Check if BST\n");
        printf("13. Tree Diameter\n");
        printf("14. Find Min/Max in BST\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert into BST: ");
                scanf("%d", &value);
                bstRoot = insertBST(bstRoot, value);
                printf("Value %d inserted into BST.\n", value);
                break;
                
            case 2:
                printf("Enter value to search in BST: ");
                scanf("%d", &value);
                if (searchBST(bstRoot, value)) {
                    printf("Value %d found in BST.\n", value);
                } else {
                    printf("Value %d not found in BST.\n", value);
                }
                break;
                
            case 3:
                printf("Enter value to delete from BST: ");
                scanf("%d", &value);
                bstRoot = deleteBST(bstRoot, value);
                printf("Value %d deleted from BST.\n", value);
                break;
                
            case 4:
                printf("BST Structure:\n");
                if (bstRoot) {
                    printTree(bstRoot, 0);
                } else {
                    printf("BST is empty.\n");
                }
                break;
                
            case 5:
                printf("Inorder Traversal (Sample Tree): ");
                inorderTraversal(sampleRoot);
                printf("\n");
                break;
                
            case 6:
                printf("Preorder Traversal (Sample Tree): ");
                preorderTraversal(sampleRoot);
                printf("\n");
                break;
                
            case 7:
                printf("Postorder Traversal (Sample Tree): ");
                postorderTraversal(sampleRoot);
                printf("\n");
                break;
                
            case 8:
                printf("Level-order Traversal (Sample Tree): ");
                levelOrderTraversal(sampleRoot);
                printf("\n");
                break;
                
            case 9:
                result = treeHeight(sampleRoot);
                printf("Height of sample tree: %d\n", result);
                if (bstRoot) {
                    result = treeHeight(bstRoot);
                    printf("Height of BST: %d\n", result);
                }
                break;
                
            case 10:
                result = countNodes(sampleRoot);
                printf("Total nodes in sample tree: %d\n", result);
                if (bstRoot) {
                    result = countNodes(bstRoot);
                    printf("Total nodes in BST: %d\n", result);
                }
                break;
                
            case 11:
                result = countLeafNodes(sampleRoot);
                printf("Leaf nodes in sample tree: %d\n", result);
                if (bstRoot) {
                    result = countLeafNodes(bstRoot);
                    printf("Leaf nodes in BST: %d\n", result);
                }
                break;
                
            case 12:
                if (isBST(sampleRoot, INT_MIN, INT_MAX)) {
                    printf("Sample tree is a valid BST.\n");
                } else {
                    printf("Sample tree is NOT a valid BST.\n");
                }
                if (bstRoot && isBST(bstRoot, INT_MIN, INT_MAX)) {
                    printf("Your BST is valid.\n");
                }
                break;
                
            case 13:
                result = calculateDiameter(sampleRoot, &height);
                printf("Diameter of sample tree: %d\n", result);
                if (bstRoot) {
                    result = calculateDiameter(bstRoot, &height);
                    printf("Diameter of BST: %d\n", result);
                }
                break;
                
            case 14:
                if (bstRoot) {
                    TreeNode* minNode = findMin(bstRoot);
                    TreeNode* maxNode = findMax(bstRoot);
                    if (minNode) printf("Minimum value in BST: %d\n", minNode->data);
                    if (maxNode) printf("Maximum value in BST: %d\n", maxNode->data);
                } else {
                    printf("BST is empty.\n");
                }
                break;
                
            case 0:
                printf("Freeing memory and exiting...\n");
                freeTree(bstRoot);
                freeTree(sampleRoot);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}