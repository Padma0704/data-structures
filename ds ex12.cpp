#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int data) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int evaluatePostfix(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (expression[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char expression[] = "53+82-*"; 
    printf("Postfix Expression: %s\n", expression);
    printf("Result: %d\n", evaluatePostfix(expression));
    return 0;
}

