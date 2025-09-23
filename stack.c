/*
 * Stack - Data Structure Implementation in C
 * 
 * This program demonstrates stack operations using both array and linked list implementations:
 * - Push operation (add element to top)
 * - Pop operation (remove element from top)
 * - Peek/Top operation (view top element without removing)
 * - Stack traversal and display
 * - Stack applications (expression evaluation, parentheses matching)
 * 
 * Compilation: gcc -o stack stack.c
 * Execution: ./stack
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Array-based stack structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} ArrayStack;

// Linked list node for stack
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Linked list-based stack structure
typedef struct {
    StackNode* top;
} LinkedStack;

// ===== ARRAY-BASED STACK OPERATIONS =====

// Initialize array stack
void initArrayStack(ArrayStack* stack) {
    stack->top = -1;
}

// Check if array stack is empty
bool isArrayStackEmpty(ArrayStack* stack) {
    return stack->top == -1;
}

// Check if array stack is full
bool isArrayStackFull(ArrayStack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push element to array stack
bool pushArray(ArrayStack* stack, int item) {
    if (isArrayStackFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", item);
        return false;
    }
    
    stack->items[++stack->top] = item;
    return true;
}

// Pop element from array stack
int popArray(ArrayStack* stack) {
    if (isArrayStackEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return -1;
    }
    
    return stack->items[stack->top--];
}

// Peek top element of array stack
int peekArray(ArrayStack* stack) {
    if (isArrayStackEmpty(stack)) {
        printf("Stack is empty! No top element\n");
        return -1;
    }
    
    return stack->items[stack->top];
}

// Display array stack
void displayArrayStack(ArrayStack* stack) {
    if (isArrayStackEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("Stack (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// ===== LINKED LIST-BASED STACK OPERATIONS =====

// Initialize linked stack
void initLinkedStack(LinkedStack* stack) {
    stack->top = NULL;
}

// Check if linked stack is empty
bool isLinkedStackEmpty(LinkedStack* stack) {
    return stack->top == NULL;
}

// Push element to linked stack
bool pushLinked(LinkedStack* stack, int item) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) {
        printf("Memory allocation failed! Cannot push %d\n", item);
        return false;
    }
    
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
    return true;
}

// Pop element from linked stack
int popLinked(LinkedStack* stack) {
    if (isLinkedStackEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return -1;
    }
    
    StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Peek top element of linked stack
int peekLinked(LinkedStack* stack) {
    if (isLinkedStackEmpty(stack)) {
        printf("Stack is empty! No top element\n");
        return -1;
    }
    
    return stack->top->data;
}

// Display linked stack
void displayLinkedStack(LinkedStack* stack) {
    if (isLinkedStackEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("Stack (top to bottom): ");
    StackNode* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free linked stack memory
void freeLinkedStack(LinkedStack* stack) {
    while (!isLinkedStackEmpty(stack)) {
        popLinked(stack);
    }
}

// ===== STACK APPLICATIONS =====

// Check if parentheses are balanced
bool isBalancedParentheses(char* expression) {
    ArrayStack stack;
    initArrayStack(&stack);
    
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        
        // Push opening brackets
        if (ch == '(' || ch == '[' || ch == '{') {
            pushArray(&stack, ch);
        }
        // Check closing brackets
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (isArrayStackEmpty(&stack)) {
                return false;  // No matching opening bracket
            }
            
            char top = popArray(&stack);
            
            // Check if brackets match
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return isArrayStackEmpty(&stack);  // All brackets should be matched
}

// Evaluate postfix expression
int evaluatePostfix(char* expression) {
    ArrayStack stack;
    initArrayStack(&stack);
    
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        
        if (ch == ' ') continue;  // Skip spaces
        
        // If operand, push to stack
        if (isdigit(ch)) {
            pushArray(&stack, ch - '0');
        }
        // If operator, pop two operands and apply operation
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (stack.top < 1) {
                printf("Invalid postfix expression!\n");
                return -1;
            }
            
            int operand2 = popArray(&stack);
            int operand1 = popArray(&stack);
            int result;
            
            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error!\n");
                        return -1;
                    }
                    result = operand1 / operand2;
                    break;
                default: return -1;
            }
            
            pushArray(&stack, result);
        }
    }
    
    if (stack.top == 0) {
        return popArray(&stack);
    } else {
        printf("Invalid postfix expression!\n");
        return -1;
    }
}

// Convert decimal to binary using stack
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }
    
    ArrayStack stack;
    initArrayStack(&stack);
    
    printf("Converting %d to binary:\n", decimal);
    
    while (decimal > 0) {
        int remainder = decimal % 2;
        pushArray(&stack, remainder);
        printf("%d / 2 = %d, remainder = %d\n", decimal, decimal / 2, remainder);
        decimal = decimal / 2;
    }
    
    printf("Binary: ");
    while (!isArrayStackEmpty(&stack)) {
        printf("%d", popArray(&stack));
    }
    printf("\n");
}

int main() {
    int choice, item, result, decimal;
    char expression[MAX_SIZE];
    ArrayStack arrayStack;
    LinkedStack linkedStack;
    
    printf("=== Stack Data Structure Demo ===\n\n");
    
    // Initialize stacks
    initArrayStack(&arrayStack);
    initLinkedStack(&linkedStack);
    
    do {
        printf("\n--- Stack Operations Menu ---\n");
        printf("Array Stack Operations:\n");
        printf("1. Push to Array Stack\n");
        printf("2. Pop from Array Stack\n");
        printf("3. Peek Array Stack\n");
        printf("4. Display Array Stack\n");
        printf("\nLinked Stack Operations:\n");
        printf("5. Push to Linked Stack\n");
        printf("6. Pop from Linked Stack\n");
        printf("7. Peek Linked Stack\n");
        printf("8. Display Linked Stack\n");
        printf("\nStack Applications:\n");
        printf("9. Check Balanced Parentheses\n");
        printf("10. Evaluate Postfix Expression\n");
        printf("11. Decimal to Binary Conversion\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to push to array stack: ");
                scanf("%d", &item);
                if (pushArray(&arrayStack, item)) {
                    printf("Element %d pushed successfully!\n", item);
                }
                break;
                
            case 2:
                result = popArray(&arrayStack);
                if (result != -1) {
                    printf("Popped element: %d\n", result);
                }
                break;
                
            case 3:
                result = peekArray(&arrayStack);
                if (result != -1) {
                    printf("Top element: %d\n", result);
                }
                break;
                
            case 4:
                displayArrayStack(&arrayStack);
                break;
                
            case 5:
                printf("Enter element to push to linked stack: ");
                scanf("%d", &item);
                if (pushLinked(&linkedStack, item)) {
                    printf("Element %d pushed successfully!\n", item);
                }
                break;
                
            case 6:
                result = popLinked(&linkedStack);
                if (result != -1) {
                    printf("Popped element: %d\n", result);
                }
                break;
                
            case 7:
                result = peekLinked(&linkedStack);
                if (result != -1) {
                    printf("Top element: %d\n", result);
                }
                break;
                
            case 8:
                displayLinkedStack(&linkedStack);
                break;
                
            case 9:
                printf("Enter expression to check balanced parentheses: ");
                scanf(" %[^\n]", expression);  // Read entire line
                if (isBalancedParentheses(expression)) {
                    printf("Parentheses are balanced!\n");
                } else {
                    printf("Parentheses are NOT balanced!\n");
                }
                break;
                
            case 10:
                printf("Enter postfix expression (single digits with spaces): ");
                scanf(" %[^\n]", expression);  // Read entire line
                result = evaluatePostfix(expression);
                if (result != -1) {
                    printf("Result: %d\n", result);
                }
                break;
                
            case 11:
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal);
                break;
                
            case 0:
                printf("Freeing memory and exiting...\n");
                freeLinkedStack(&linkedStack);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}