#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <ctype.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = item;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char* postfix) {
    int i = 0, operand1, operand2, result;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            operand2 = pop();
            operand1 = pop();

            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
            push(result);
        }
    }
    return pop();
}

void main() {
    char postfix[MAX_SIZE];
    int result;
    clrscr();	
    printf("Enter Postfix Expression (e.g., 23+5*): ");
    scanf("%s", postfix);  // Reads input without spaces

    result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    getch();
}
