/*
 * Dynamic Programming - Implementation in C
 * 
 * This program demonstrates various dynamic programming problems and solutions:
 * - Fibonacci sequence (with memoization and tabulation)
 * - Longest Common Subsequence (LCS)
 * - 0/1 Knapsack Problem
 * - Coin Change Problem
 * - Longest Increasing Subsequence (LIS)
 * - Edit Distance (Levenshtein Distance)
 * - Matrix Chain Multiplication
 * - Maximum Sum Subarray (Kadane's Algorithm)
 * 
 * Compilation: gcc -o dynamic_programming dynamic_programming.c
 * Execution: ./dynamic_programming
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 1000
#define MAX_STRING 100

// ===== FIBONACCI SEQUENCE =====

// Naive recursive approach - O(2^n)
long long fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Memoization approach - O(n)
long long fibonacciMemoization(int n, long long memo[]) {
    if (n <= 1) return n;
    
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibonacciMemoization(n - 1, memo) + fibonacciMemoization(n - 2, memo);
    return memo[n];
}

// Tabulation approach - O(n)
long long fibonacciTabulation(int n) {
    if (n <= 1) return n;
    
    long long dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

// Space-optimized approach - O(1) space
long long fibonacciOptimized(int n) {
    if (n <= 1) return n;
    
    long long prev2 = 0, prev1 = 1, current;
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

// ===== LONGEST COMMON SUBSEQUENCE =====

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

// LCS using dynamic programming
int longestCommonSubsequence(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    
    int dp[m + 1][n + 1];
    
    // Build dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

// Print LCS
void printLCS(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    
    int dp[m + 1][n + 1];
    
    // Build dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Backtrack to find LCS
    int lcsLength = dp[m][n];
    char lcs[lcsLength + 1];
    lcs[lcsLength] = '\0';
    
    int i = m, j = n, index = lcsLength - 1;
    
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[index] = str1[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    printf("LCS: %s\n", lcs);
}

// ===== 0/1 KNAPSACK PROBLEM =====

int knapsack01(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];
    
    // Build dp table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], 
                              dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][capacity];
}

// Print items selected in knapsack
void printKnapsackItems(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];
    
    // Build dp table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], 
                              dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    // Backtrack to find selected items
    int w = capacity;
    printf("Selected items (weight, value):\n");
    
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item %d: (%d, %d)\n", i, weights[i - 1], values[i - 1]);
            w -= weights[i - 1];
        }
    }
}

// ===== COIN CHANGE PROBLEM =====

// Minimum coins needed
int coinChangeMinCoins(int coins[], int n, int amount) {
    int dp[amount + 1];
    
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

// Number of ways to make change
int coinChangeWays(int coins[], int n, int amount) {
    int dp[amount + 1];
    
    dp[0] = 1;
    
    for (int i = 1; i <= amount; i++) {
        dp[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    
    return dp[amount];
}

// ===== LONGEST INCREASING SUBSEQUENCE =====

int longestIncreasingSubsequence(int arr[], int n) {
    int dp[n];
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    int maxLength = dp[0];
    for (int i = 1; i < n; i++) {
        if (dp[i] > maxLength) {
            maxLength = dp[i];
        }
    }
    
    return maxLength;
}

// ===== EDIT DISTANCE =====

int editDistance(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    
    int dp[m + 1][n + 1];
    
    // Initialize base cases
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }
    
    // Fill dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(min(dp[i - 1][j],    // Delete
                                       dp[i][j - 1]),   // Insert
                                       dp[i - 1][j - 1]); // Replace
            }
        }
    }
    
    return dp[m][n];
}

// ===== MATRIX CHAIN MULTIPLICATION =====

int matrixChainOrder(int p[], int n) {
    int dp[n][n];
    
    // Initialize diagonal to 0
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
    
    // Fill dp table
    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    
    return dp[1][n - 1];
}

// ===== MAXIMUM SUM SUBARRAY (KADANE'S ALGORITHM) =====

int maxSubarraySum(int arr[], int n) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    
    for (int i = 1; i < n; i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}

// Print maximum sum subarray
void printMaxSubarray(int arr[], int n) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    int start = 0, end = 0, tempStart = 0;
    
    for (int i = 1; i < n; i++) {
        if (maxEndingHere < 0) {
            maxEndingHere = arr[i];
            tempStart = i;
        } else {
            maxEndingHere += arr[i];
        }
        
        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
            start = tempStart;
            end = i;
        }
    }
    
    printf("Maximum sum: %d\n", maxSoFar);
    printf("Subarray: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ===== UTILITY FUNCTIONS =====

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void compareFibonacciMethods(int n) {
    printf("\n=== Fibonacci Comparison for n = %d ===\n", n);
    
    // Memoization
    long long memo[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    
    printf("Recursive (only for small n): ");
    if (n <= 40) {
        printf("%lld\n", fibonacciRecursive(n));
    } else {
        printf("Skipped (too slow)\n");
    }
    
    printf("Memoization: %lld\n", fibonacciMemoization(n, memo));
    printf("Tabulation: %lld\n", fibonacciTabulation(n));
    printf("Space Optimized: %lld\n", fibonacciOptimized(n));
}

int main() {
    int choice;
    
    printf("=== Dynamic Programming Algorithms Demo ===\n\n");
    
    do {
        printf("\n--- Dynamic Programming Menu ---\n");
        printf("1. Fibonacci Sequence (Multiple Approaches)\n");
        printf("2. Longest Common Subsequence (LCS)\n");
        printf("3. 0/1 Knapsack Problem\n");
        printf("4. Coin Change Problem\n");
        printf("5. Longest Increasing Subsequence\n");
        printf("6. Edit Distance\n");
        printf("7. Matrix Chain Multiplication\n");
        printf("8. Maximum Sum Subarray (Kadane's Algorithm)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int n;
                printf("Enter n for Fibonacci: ");
                scanf("%d", &n);
                compareFibonacciMethods(n);
                break;
            }
            
            case 2: {
                char str1[MAX_STRING], str2[MAX_STRING];
                printf("Enter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);
                
                int lcsLength = longestCommonSubsequence(str1, str2);
                printf("LCS Length: %d\n", lcsLength);
                printLCS(str1, str2);
                break;
            }
            
            case 3: {
                int n, capacity;
                printf("Enter number of items: ");
                scanf("%d", &n);
                
                int weights[n], values[n];
                printf("Enter weights: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &weights[i]);
                }
                
                printf("Enter values: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &values[i]);
                }
                
                printf("Enter knapsack capacity: ");
                scanf("%d", &capacity);
                
                int maxValue = knapsack01(weights, values, n, capacity);
                printf("Maximum value: %d\n", maxValue);
                printKnapsackItems(weights, values, n, capacity);
                break;
            }
            
            case 4: {
                int n, amount;
                printf("Enter number of coin denominations: ");
                scanf("%d", &n);
                
                int coins[n];
                printf("Enter coin denominations: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &coins[i]);
                }
                
                printf("Enter amount: ");
                scanf("%d", &amount);
                
                int minCoins = coinChangeMinCoins(coins, n, amount);
                int ways = coinChangeWays(coins, n, amount);
                
                if (minCoins == -1) {
                    printf("Cannot make change for amount %d\n", amount);
                } else {
                    printf("Minimum coins needed: %d\n", minCoins);
                }
                printf("Number of ways to make change: %d\n", ways);
                break;
            }
            
            case 5: {
                int n;
                printf("Enter array size: ");
                scanf("%d", &n);
                
                int arr[n];
                printf("Enter array elements: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                int lisLength = longestIncreasingSubsequence(arr, n);
                printf("Length of Longest Increasing Subsequence: %d\n", lisLength);
                break;
            }
            
            case 6: {
                char str1[MAX_STRING], str2[MAX_STRING];
                printf("Enter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);
                
                int distance = editDistance(str1, str2);
                printf("Edit Distance: %d\n", distance);
                break;
            }
            
            case 7: {
                int n;
                printf("Enter number of matrices: ");
                scanf("%d", &n);
                
                int p[n + 1];
                printf("Enter matrix dimensions (n+1 values): ");
                for (int i = 0; i <= n; i++) {
                    scanf("%d", &p[i]);
                }
                
                int minMultiplications = matrixChainOrder(p, n + 1);
                printf("Minimum number of scalar multiplications: %d\n", minMultiplications);
                break;
            }
            
            case 8: {
                int n;
                printf("Enter array size: ");
                scanf("%d", &n);
                
                int arr[n];
                printf("Enter array elements: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                printf("Array: ");
                displayArray(arr, n);
                printMaxSubarray(arr, n);
                break;
            }
            
            case 0:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}