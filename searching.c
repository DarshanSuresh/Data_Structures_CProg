/*
 * Searching Algorithms - Implementation in C
 * 
 * This program demonstrates various searching algorithms including:
 * - Linear Search (Sequential Search)
 * - Binary Search (for sorted arrays)
 * - Interpolation Search
 * - Exponential Search
 * - Jump Search
 * - Fibonacci Search
 * - Ternary Search
 * - Hash Table based searching
 * 
 * Compilation: gcc -o searching searching.c
 * Execution: ./searching
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1000
#define HASH_TABLE_SIZE 101

// ===== BASIC SEARCHING ALGORITHMS =====

// Linear Search - O(n) time complexity
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Binary Search - O(log n) time complexity (requires sorted array)
int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            return mid;
        }
        
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // Element not found
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            return mid;
        }
        
        if (arr[mid] > key) {
            return binarySearchRecursive(arr, left, mid - 1, key);
        }
        
        return binarySearchRecursive(arr, mid + 1, right, key);
    }
    
    return -1;
}

// ===== ADVANCED SEARCHING ALGORITHMS =====

// Interpolation Search - O(log log n) for uniformly distributed data
int interpolationSearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }
        
        // Calculate position using interpolation formula
        int pos = low + ((double)(key - arr[low]) / (arr[high] - arr[low])) * (high - low);
        
        if (arr[pos] == key) {
            return pos;
        }
        
        if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    
    return -1;
}

// Jump Search - O(√n) time complexity
int jumpSearch(int arr[], int size, int key) {
    int jump = sqrt(size);
    int prev = 0;
    
    // Find block where element may be present
    while (arr[jump < size ? jump : size - 1] < key) {
        prev = jump;
        jump += sqrt(size);
        if (prev >= size) {
            return -1;
        }
    }
    
    // Linear search in the identified block
    while (arr[prev] < key) {
        prev++;
        if (prev == (jump < size ? jump : size)) {
            return -1;
        }
    }
    
    if (arr[prev] == key) {
        return prev;
    }
    
    return -1;
}

// Exponential Search - O(log n) time complexity
int exponentialSearch(int arr[], int size, int key) {
    if (arr[0] == key) {
        return 0;
    }
    
    // Find range for binary search
    int bound = 1;
    while (bound < size && arr[bound] <= key) {
        bound *= 2;
    }
    
    // Perform binary search in the found range
    int left = bound / 2;
    int right = (bound < size) ? bound : size - 1;
    
    return binarySearchRecursive(arr, left, right, key);
}

// Fibonacci Search - O(log n) time complexity
int fibonacciSearch(int arr[], int size, int key) {
    int fib2 = 0;   // (m-2)'th Fibonacci number
    int fib1 = 1;   // (m-1)'th Fibonacci number
    int fib = fib2 + fib1; // m'th Fibonacci number
    
    // Find smallest Fibonacci number >= size
    while (fib < size) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }
    
    int offset = -1;
    
    while (fib > 1) {
        int i = (offset + fib2 < size - 1) ? offset + fib2 : size - 1;
        
        if (arr[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return i;
        }
    }
    
    if (fib1 && offset + 1 < size && arr[offset + 1] == key) {
        return offset + 1;
    }
    
    return -1;
}

// Ternary Search - O(log₃ n) time complexity
int ternarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        
        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }
        
        if (key < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, key);
        } else if (key > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, key);
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
        }
    }
    
    return -1;
}

// ===== HASH TABLE IMPLEMENTATION =====

typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode* table[HASH_TABLE_SIZE];
} HashTable;

// Hash function
int hashFunction(int key) {
    return key % HASH_TABLE_SIZE;
}

// Initialize hash table
void initHashTable(HashTable* ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

// Insert into hash table
void hashInsert(HashTable* ht, int key, int value) {
    int index = hashFunction(key);
    
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Search in hash table - O(1) average case
int hashSearch(HashTable* ht, int key) {
    int index = hashFunction(key);
    HashNode* current = ht->table[index];
    
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    
    return -1;  // Not found
}

// ===== UTILITY FUNCTIONS =====

// Function to sort array using bubble sort (for demonstration)
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Display array
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Generate random array
void generateRandomArray(int arr[], int size, int max_value) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % max_value + 1;
    }
}

// Search comparison function
void compareSearchAlgorithms(int arr[], int size, int key) {
    printf("\n=== Search Algorithm Comparison for key %d ===\n", key);
    
    // Ensure array is sorted for algorithms that require it
    int sortedArr[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        sortedArr[i] = arr[i];
    }
    bubbleSort(sortedArr, size);
    
    printf("Searching in sorted array: ");
    for (int i = 0; i < (size < 20 ? size : 20); i++) {
        printf("%d ", sortedArr[i]);
    }
    if (size > 20) printf("...");
    printf("\n\n");
    
    // Linear Search
    int result = linearSearch(sortedArr, size, key);
    printf("Linear Search: %s at index %d\n", 
           result != -1 ? "Found" : "Not found", result);
    
    // Binary Search
    result = binarySearch(sortedArr, size, key);
    printf("Binary Search: %s at index %d\n", 
           result != -1 ? "Found" : "Not found", result);
    
    // Interpolation Search
    result = interpolationSearch(sortedArr, size, key);
    printf("Interpolation Search: %s at index %d\n", 
           result != -1 ? "Found" : "Not found", result);
    
    // Jump Search
    result = jumpSearch(sortedArr, size, key);
    printf("Jump Search: %s at index %d\n", 
           result != -1 ? "Found" : "Not found", result);
    
    // Exponential Search
    result = exponentialSearch(sortedArr, size, key);
    printf("Exponential Search: %s at index %d\n", 
           result != -1 ? "Found" : "Not found", result);
    
    // Fibonacci Search
    result = fibonacciSearch(sortedArr, size, key);
    printf("Fibonacci Search: %s at index %d\n", 
           result != -1 ? "Found" : "Not found", result);
    
    // Ternary Search
    result = ternarySearch(sortedArr, 0, size - 1, key);
    printf("Ternary Search: %s at index %d\n", 
           result != -1 ? "Found" : "Not found", result);
}

int main() {
    int choice, key, result, size;
    int arr[MAX_SIZE];
    HashTable hashTable;
    
    printf("=== Searching Algorithms Demo ===\n\n");
    
    // Initialize with sample data
    int sampleData[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    size = sizeof(sampleData) / sizeof(sampleData[0]);
    
    for (int i = 0; i < size; i++) {
        arr[i] = sampleData[i];
    }
    
    // Initialize hash table with sample data
    initHashTable(&hashTable);
    for (int i = 0; i < size; i++) {
        hashInsert(&hashTable, arr[i], i);
    }
    
    printf("Initial array created with %d elements.\n", size);
    displayArray(arr, size);
    
    do {
        printf("\n--- Searching Algorithms Menu ---\n");
        printf("Basic Searching:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search (sorts array first)\n");
        printf("3. Interpolation Search\n");
        printf("4. Jump Search\n");
        printf("5. Exponential Search\n");
        printf("6. Fibonacci Search\n");
        printf("7. Ternary Search\n");
        printf("\nHash Table Operations:\n");
        printf("8. Hash Table Search\n");
        printf("9. Insert into Hash Table\n");
        printf("\nUtilities:\n");
        printf("10. Display Current Array\n");
        printf("11. Generate Random Array\n");
        printf("12. Compare All Algorithms\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = linearSearch(arr, size, key);
                if (result != -1) {
                    printf("Element %d found at index %d using Linear Search\n", key, result);
                } else {
                    printf("Element %d not found using Linear Search\n", key);
                }
                break;
                
            case 2:
                printf("Sorting array for binary search...\n");
                bubbleSort(arr, size);
                displayArray(arr, size);
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = binarySearch(arr, size, key);
                if (result != -1) {
                    printf("Element %d found at index %d using Binary Search\n", key, result);
                } else {
                    printf("Element %d not found using Binary Search\n", key);
                }
                break;
                
            case 3:
                bubbleSort(arr, size);
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = interpolationSearch(arr, size, key);
                if (result != -1) {
                    printf("Element %d found at index %d using Interpolation Search\n", key, result);
                } else {
                    printf("Element %d not found using Interpolation Search\n", key);
                }
                break;
                
            case 4:
                bubbleSort(arr, size);
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = jumpSearch(arr, size, key);
                if (result != -1) {
                    printf("Element %d found at index %d using Jump Search\n", key, result);
                } else {
                    printf("Element %d not found using Jump Search\n", key);
                }
                break;
                
            case 5:
                bubbleSort(arr, size);
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = exponentialSearch(arr, size, key);
                if (result != -1) {
                    printf("Element %d found at index %d using Exponential Search\n", key, result);
                } else {
                    printf("Element %d not found using Exponential Search\n", key);
                }
                break;
                
            case 6:
                bubbleSort(arr, size);
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = fibonacciSearch(arr, size, key);
                if (result != -1) {
                    printf("Element %d found at index %d using Fibonacci Search\n", key, result);
                } else {
                    printf("Element %d not found using Fibonacci Search\n", key);
                }
                break;
                
            case 7:
                bubbleSort(arr, size);
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = ternarySearch(arr, 0, size - 1, key);
                if (result != -1) {
                    printf("Element %d found at index %d using Ternary Search\n", key, result);
                } else {
                    printf("Element %d not found using Ternary Search\n", key);
                }
                break;
                
            case 8:
                printf("Enter element to search in hash table: ");
                scanf("%d", &key);
                result = hashSearch(&hashTable, key);
                if (result != -1) {
                    printf("Element %d found in hash table at original index %d\n", key, result);
                } else {
                    printf("Element %d not found in hash table\n", key);
                }
                break;
                
            case 9:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &result);
                hashInsert(&hashTable, key, result);
                printf("Key-value pair (%d, %d) inserted into hash table\n", key, result);
                break;
                
            case 10:
                displayArray(arr, size);
                break;
                
            case 11:
                printf("Enter array size (max %d): ", MAX_SIZE);
                scanf("%d", &size);
                if (size > MAX_SIZE) size = MAX_SIZE;
                generateRandomArray(arr, size, 100);
                printf("Random array generated:\n");
                displayArray(arr, size);
                break;
                
            case 12:
                printf("Enter element to search: ");
                scanf("%d", &key);
                compareSearchAlgorithms(arr, size, key);
                break;
                
            case 0:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}