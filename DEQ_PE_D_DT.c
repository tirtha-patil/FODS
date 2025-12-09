#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int deque[MAX];
int front = -1, rear = -1;

// Check if deque is full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// Check if deque is empty
int isEmpty() {
    return front == -1;
}

// Enqueue at front
void enqueueFront(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert at front.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } 
    else if (front == 0) {
        front = MAX - 1;  // wrap around
    } 
    else {
        front--;
    }

    deque[front] = value;
    printf("%d inserted at front.\n", value);
}

// Enqueue at rear
void enqueueRear(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert at rear.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } 
    else if (rear == MAX - 1) {
        rear = 0;  // wrap around
    } 
    else {
        rear++;
    }

    deque[rear] = value;
    printf("%d inserted at rear.\n", value);
}

// Dequeue from front
void dequeueFront() {
    if (isEmpty()) {
        printf("Deque Underflow! Nothing to delete.\n");
        return;
    }

    printf("Deleted from front: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;  // Now empty
    } 
    else if (front == MAX - 1) {
        front = 0;
    } 
    else {
        front++;
    }
}

// Dequeue from rear
void dequeueRear() {
    if (isEmpty()) {
        printf("Deque Underflow! Nothing to delete.\n");
        return;
    }

    printf("Deleted from rear: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;  // Now empty
    } 
    else if (rear == 0) {
        rear = MAX - 1;
    } 
    else {
        rear--;
    }
}

// Peek at front
void peekFront() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Front element: %d\n", deque[front]);
}

// Display deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;

    while (1) {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Enqueue at Front\n");
        printf("2. Enqueue at Rear\n");
        printf("3. Dequeue from Front\n");
        printf("4. Dequeue from Rear\n");
        printf("5. Peek Front Element\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                enqueueFront(value);
                break;

            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                enqueueRear(value);
                break;

            case 3:
                dequeueFront();
                break;

            case 4:
                dequeueRear();
                break;

            case 5:
                peekFront();
                break;

            case 6:
                display();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
