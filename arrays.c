/*
 * Arrays - Data Structure Implementation in C
 * 
 * This program demonstrates basic array operations including:
 * - Array declaration and initialization
 * - Insertion and deletion of elements
 * - Searching (Linear and Binary Search)
 * - Array traversal and display
 * 
 * Compilation: gcc -o arrays arrays.c
 * Execution: ./arrays
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to display array elements
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert element at specific position
bool insertElement(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full! Cannot insert element.\n");
        return false;
    }
    
    if (position < 0 || position > *size) {
        printf("Invalid position! Position should be between 0 and %d\n", *size);
        return false;
    }
    
    // Shift elements to the right
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = element;
    (*size)++;
    return true;
}

// Function to delete element at specific position
bool deleteElement(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Array is empty! Cannot delete element.\n");
        return false;
    }
    
    if (position < 0 || position >= *size) {
        printf("Invalid position! Position should be between 0 and %d\n", *size - 1);
        return false;
    }
    
    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--;
    return true;
}

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

// Function to sort array using bubble sort (for binary search demonstration)
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find maximum element
int findMax(int arr[], int size) {
    if (size == 0) return -1;
    
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find minimum element
int findMin(int arr[], int size) {
    if (size == 0) return -1;
    
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to reverse array
void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position, key, result;
    
    printf("=== Array Operations Demo ===\n\n");
    
    // Initialize array with some sample data
    int sampleData[] = {10, 25, 3, 40, 15, 8, 30};
    size = sizeof(sampleData) / sizeof(sampleData[0]);
    
    for (int i = 0; i < size; i++) {
        arr[i] = sampleData[i];
    }
    
    printf("Initial array:\n");
    displayArray(arr, size);
    
    do {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search (sorts array first)\n");
        printf("6. Find Maximum\n");
        printf("7. Find Minimum\n");
        printf("8. Reverse Array\n");
        printf("9. Sort Array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
                
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &position);
                if (insertElement(arr, &size, element, position)) {
                    printf("Element inserted successfully!\n");
                    displayArray(arr, size);
                }
                break;
                
            case 3:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                if (deleteElement(arr, &size, position)) {
                    printf("Element deleted successfully!\n");
                    displayArray(arr, size);
                }
                break;
                
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = linearSearch(arr, size, key);
                if (result != -1) {
                    printf("Element %d found at index %d\n", key, result);
                } else {
                    printf("Element %d not found in array\n", key);
                }
                break;
                
            case 5:
                printf("Sorting array for binary search...\n");
                bubbleSort(arr, size);
                displayArray(arr, size);
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = binarySearch(arr, size, key);
                if (result != -1) {
                    printf("Element %d found at index %d\n", key, result);
                } else {
                    printf("Element %d not found in array\n", key);
                }
                break;
                
            case 6:
                result = findMax(arr, size);
                if (result != -1) {
                    printf("Maximum element: %d\n", result);
                }
                break;
                
            case 7:
                result = findMin(arr, size);
                if (result != -1) {
                    printf("Minimum element: %d\n", result);
                }
                break;
                
            case 8:
                reverseArray(arr, size);
                printf("Array reversed successfully!\n");
                displayArray(arr, size);
                break;
                
            case 9:
                bubbleSort(arr, size);
                printf("Array sorted successfully!\n");
                displayArray(arr, size);
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