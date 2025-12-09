#include <stdio.h>

#define MAX 100

// Stack
int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Convert decimal to required base using stack
void convert(int num, int base) {
    top = -1; // Reset stack

    // If num is 0
    if (num == 0) {
        printf("0");
        return;
    }

    while (num > 0) {
        push(num % base);
        num /= base;
    }

    // Pop and print
    while (top != -1) {
        int value = pop();

        // For hexadecimal digits A–F
        if (value >= 10)
            printf("%c", value - 10 + 'A');
        else
            printf("%d", value);
    }
}

int main() {
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("\nBinary: ");
    convert(num, 2);

    printf("\nOctal: ");
    convert(num, 8);

    printf("\nHexadecimal: ");
    convert(num, 16);

    printf("\n");

    return 0;
}
