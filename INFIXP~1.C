#include <stdio.h>
#include <conio.h>
#include <ctype.h>   // for isalnum()
#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) {   // Function to push element to stack
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {    // Function to pop element from stack
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

int precedence(char symbol) {  // Function to return precedence of operators
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char infix[]) {   // Function to convert infix to postfix
    char postfix[MAX], symbol, temp; int i, k = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];
        if (isalnum(symbol)) {  // If operand, add to postfix expression
            postfix[k++] = symbol;
        }
        else if (symbol == '(') {   // If '(', push to stack
            push(symbol);
        }
        else if (symbol == ')') {   // If ')', pop and output until '('
            while ((temp = pop()) != '(') {
                postfix[k++] = temp;
            }
        }
        else {    // If operator, pop higher precedence operators and push current
            while (precedence(stack[top]) >= precedence(symbol)) { 
                postfix[k++] = pop();
            }
            push(symbol);
        }
    }
    while (top != -1) {   // Pop remaining operators
        postfix[k++] = pop();
    }
    postfix[k] = '\0'; // null terminate
    printf("Postfix Expression: %s\n", postfix);
}

void main() {
    char infix[MAX]; 
    clrscr();
    printf("Enter an Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    getch();
}
