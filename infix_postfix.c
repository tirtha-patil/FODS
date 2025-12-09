#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int evalStack[MAX];
int evalTop = -1;

// Stack functions for infix→postfix
void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

// Operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix → postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isalnum(c)) {  
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // pop '('
        }
        else {  
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Stack functions for postfix evaluation
void evalPush(int num) {
    evalStack[++evalTop] = num;
}

int evalPop() {
    return evalStack[evalTop--];
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    int i, op1, op2;

    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            evalPush(c - '0'); // convert char digit → int
        }
        else {
            op2 = evalPop();
            op1 = evalPop();

            switch (c) {
                case '+': evalPush(op1 + op2); break;
                case '-': evalPush(op1 - op2); break;
                case '*': evalPush(op1 * op2); break;
                case '/': evalPush(op1 / op2); break;
                case '^': {
                    int res = 1;
                    for (int k = 0; k < op2; k++) res *= op1;
                    evalPush(res);
                    break;
                }
            }
        }
    }

    return evalPop();
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation Result: %d\n", result);

    return 0;
}
