/*
 * Sorting Algorithms - Implementation in C
 * 
 * This program demonstrates various sorting algorithms including:
 * - Bubble Sort, Selection Sort, Insertion Sort
 * - Merge Sort, Quick Sort, Heap Sort
 * - Counting Sort, Radix Sort, Bucket Sort
 * - Shell Sort, Cocktail Sort
 * - Performance comparison of different algorithms
 * 
 * Compilation: gcc -o sorting sorting.c
 * Execution: ./sorting
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000

// ===== SIMPLE SORTING ALGORITHMS =====

// Bubble Sort - O(n²) time complexity
void bubbleSort(int arr[], int size) {
    printf("Performing Bubble Sort...\n");
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no swapping occurred, array is already sorted
        if (!swapped) break;
    }
}

// Selection Sort - O(n²) time complexity
void selectionSort(int arr[], int size) {
    printf("Performing Selection Sort...\n");
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap minimum element with first element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Insertion Sort - O(n²) time complexity, O(n) best case
void insertionSort(int arr[], int size) {
    printf("Performing Insertion Sort...\n");
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ===== ADVANCED SORTING ALGORITHMS =====

// Merge Sort - O(n log n) time complexity
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int* leftArr = (int*)malloc(n1 * sizeof(int));
    int* rightArr = (int*)malloc(n2 * sizeof(int));
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    // Merge the temporary arrays back
    int i = 0, j = 0, k = left;
    
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
    
    // Copy remaining elements
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
    
    free(leftArr);
    free(rightArr);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort - O(n log n) average case, O(n²) worst case
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;        // Index of smaller element
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Place pivot in correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// ===== HEAP SORT =====

void heapify(int arr[], int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    
    // Find largest among root, left child and right child
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    
    // If largest is not root
    if (largest != root) {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;
        
        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    printf("Performing Heap Sort...\n");
    
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    
    // Extract elements from heap one by one
    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// ===== COUNTING SORT =====

void countingSort(int arr[], int size) {
    printf("Performing Counting Sort...\n");
    
    // Find maximum element
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Create count array
    int* count = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(size * sizeof(int));
    
    // Store count of each element
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    
    // Change count[i] to actual position
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // Copy output array to original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    
    free(count);
    free(output);
}

// ===== RADIX SORT =====

int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSortForRadix(int arr[], int size, int exp) {
    int output[size];
    int count[10] = {0};
    
    // Store count of occurrences
    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    // Change count[i] to actual position
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Copy output array to original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int size) {
    printf("Performing Radix Sort...\n");
    int max = getMax(arr, size);
    
    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortForRadix(arr, size, exp);
    }
}

// ===== SHELL SORT =====

void shellSort(int arr[], int size) {
    printf("Performing Shell Sort...\n");
    
    // Start with a big gap, then reduce the gap
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            arr[j] = temp;
        }
    }
}

// ===== COCKTAIL SORT (BIDIRECTIONAL BUBBLE SORT) =====

void cocktailSort(int arr[], int size) {
    printf("Performing Cocktail Sort...\n");
    bool swapped = true;
    int start = 0;
    int end = size - 1;
    
    while (swapped) {
        swapped = false;
        
        // Forward pass
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        
        if (!swapped) break;
        
        end--;
        swapped = false;
        
        // Backward pass
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        
        start++;
    }
}

// ===== UTILITY FUNCTIONS =====

void displayArray(int arr[], int size) {
    printf("Array: ");
    int displaySize = size > 20 ? 20 : size;
    for (int i = 0; i < displaySize; i++) {
        printf("%d ", arr[i]);
    }
    if (size > 20) printf("... (%d more elements)", size - 20);
    printf("\n");
}

void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

void generateRandomArray(int arr[], int size, int maxValue) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % maxValue + 1;
    }
}

void generateReverseSortedArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
}

double measureSortingTime(void (*sortFunc)(int[], int), int arr[], int size, const char* name) {
    int* tempArr = (int*)malloc(size * sizeof(int));
    copyArray(arr, tempArr, size);
    
    clock_t start = clock();
    sortFunc(tempArr, size);
    clock_t end = clock();
    
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%s completed in %.6f seconds\n", name, time);
    
    free(tempArr);
    return time;
}

double measureMergeSortTime(int arr[], int size) {
    int* tempArr = (int*)malloc(size * sizeof(int));
    copyArray(arr, tempArr, size);
    
    printf("Performing Merge Sort...\n");
    clock_t start = clock();
    mergeSort(tempArr, 0, size - 1);
    clock_t end = clock();
    
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort completed in %.6f seconds\n", time);
    
    free(tempArr);
    return time;
}

double measureQuickSortTime(int arr[], int size) {
    int* tempArr = (int*)malloc(size * sizeof(int));
    copyArray(arr, tempArr, size);
    
    printf("Performing Quick Sort...\n");
    clock_t start = clock();
    quickSort(tempArr, 0, size - 1);
    clock_t end = clock();
    
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort completed in %.6f seconds\n", time);
    
    free(tempArr);
    return time;
}

void performanceComparison(int arr[], int size) {
    printf("\n=== Performance Comparison ===\n");
    printf("Array size: %d elements\n\n", size);
    
    if (size <= 10000) {  // Only run O(n²) algorithms for smaller arrays
        measureSortingTime(bubbleSort, arr, size, "Bubble Sort");
        measureSortingTime(selectionSort, arr, size, "Selection Sort");
        measureSortingTime(insertionSort, arr, size, "Insertion Sort");
    } else {
        printf("Skipping O(n²) algorithms for large array size\n");
    }
    
    measureMergeSortTime(arr, size);
    measureQuickSortTime(arr, size);
    measureSortingTime(heapSort, arr, size, "Heap Sort");
    measureSortingTime(shellSort, arr, size, "Shell Sort");
    
    if (size <= 10000) {
        measureSortingTime(cocktailSort, arr, size, "Cocktail Sort");
    }
    
    // For counting and radix sort, check if all elements are positive and reasonably small
    bool canUseCountingSort = true;
    int maxVal = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0 || arr[i] > 10000) {
            canUseCountingSort = false;
            break;
        }
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    
    if (canUseCountingSort) {
        measureSortingTime(countingSort, arr, size, "Counting Sort");
        measureSortingTime(radixSort, arr, size, "Radix Sort");
    } else {
        printf("Skipping Counting/Radix Sort (negative numbers or too large values)\n");
    }
    
    printf("\n");
}

int main() {
    int choice, size;
    int arr[MAX_SIZE];
    int originalArr[MAX_SIZE];
    
    printf("=== Sorting Algorithms Demo ===\n\n");
    
    // Initialize with sample data
    int sampleData[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    size = sizeof(sampleData) / sizeof(sampleData[0]);
    
    for (int i = 0; i < size; i++) {
        arr[i] = originalArr[i] = sampleData[i];
    }
    
    printf("Initial array:\n");
    displayArray(arr, size);
    
    do {
        printf("\n--- Sorting Algorithms Menu ---\n");
        printf("Simple Sorting (O(n²)):\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("\nAdvanced Sorting (O(n log n)):\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Heap Sort\n");
        printf("\nSpecial Sorting:\n");
        printf("7. Counting Sort\n");
        printf("8. Radix Sort\n");
        printf("9. Shell Sort\n");
        printf("10. Cocktail Sort\n");
        printf("\nUtilities:\n");
        printf("11. Display Current Array\n");
        printf("12. Reset to Original Array\n");
        printf("13. Generate Random Array\n");
        printf("14. Generate Reverse Sorted Array\n");
        printf("15. Performance Comparison\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                copyArray(originalArr, arr, size);
                bubbleSort(arr, size);
                printf("Array after Bubble Sort:\n");
                displayArray(arr, size);
                break;
                
            case 2:
                copyArray(originalArr, arr, size);
                selectionSort(arr, size);
                printf("Array after Selection Sort:\n");
                displayArray(arr, size);
                break;
                
            case 3:
                copyArray(originalArr, arr, size);
                insertionSort(arr, size);
                printf("Array after Insertion Sort:\n");
                displayArray(arr, size);
                break;
                
            case 4:
                copyArray(originalArr, arr, size);
                printf("Performing Merge Sort...\n");
                mergeSort(arr, 0, size - 1);
                printf("Array after Merge Sort:\n");
                displayArray(arr, size);
                break;
                
            case 5:
                copyArray(originalArr, arr, size);
                printf("Performing Quick Sort...\n");
                quickSort(arr, 0, size - 1);
                printf("Array after Quick Sort:\n");
                displayArray(arr, size);
                break;
                
            case 6:
                copyArray(originalArr, arr, size);
                heapSort(arr, size);
                printf("Array after Heap Sort:\n");
                displayArray(arr, size);
                break;
                
            case 7:
                copyArray(originalArr, arr, size);
                countingSort(arr, size);
                printf("Array after Counting Sort:\n");
                displayArray(arr, size);
                break;
                
            case 8:
                copyArray(originalArr, arr, size);
                radixSort(arr, size);
                printf("Array after Radix Sort:\n");
                displayArray(arr, size);
                break;
                
            case 9:
                copyArray(originalArr, arr, size);
                shellSort(arr, size);
                printf("Array after Shell Sort:\n");
                displayArray(arr, size);
                break;
                
            case 10:
                copyArray(originalArr, arr, size);
                cocktailSort(arr, size);
                printf("Array after Cocktail Sort:\n");
                displayArray(arr, size);
                break;
                
            case 11:
                displayArray(arr, size);
                break;
                
            case 12:
                copyArray(originalArr, arr, size);
                printf("Array reset to original:\n");
                displayArray(arr, size);
                break;
                
            case 13:
                printf("Enter array size (max %d): ", MAX_SIZE);
                scanf("%d", &size);
                if (size > MAX_SIZE) size = MAX_SIZE;
                generateRandomArray(arr, size, 1000);
                copyArray(arr, originalArr, size);
                printf("Random array generated:\n");
                displayArray(arr, size);
                break;
                
            case 14:
                printf("Enter array size (max %d): ", MAX_SIZE);
                scanf("%d", &size);
                if (size > MAX_SIZE) size = MAX_SIZE;
                generateReverseSortedArray(arr, size);
                copyArray(arr, originalArr, size);
                printf("Reverse sorted array generated:\n");
                displayArray(arr, size);
                break;
                
            case 15:
                performanceComparison(originalArr, size);
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