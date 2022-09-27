#include<stdio.h>

#include<stdlib.h>

#define qs 5
int front = -1, rear = -1, queue[qs];
void enqueue(int ele) {
    if (isFull())
        printf("Overflow\n");
    else if (rear == -1 && front == -1) {
        front = 0;
        rear = 0;
        queue[rear] = ele;
        printf("Element enqueued is %d\n", queue[rear]);
    } else {
        rear = rear + 1;
        queue[rear] = ele;
        printf("Element enqueued is %d\n", queue[rear]);
    }
}
void dequeue() {
    if (isEmpty())
        printf("Underflow condition\n");
    else if (front == rear) {
        printf("Element deleted is %d\n", queue[front]);
        front = -1;
        rear = -1;
    } else {
        int ele = queue[front];
        front++;
        printf("Element deleted is %d\n", ele);
    }
}
int isEmpty() {
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}
int isFull() {
    if (rear == qs - 1)
        return 1;
    else
        return 0;
}
void peek() {
    if (isEmpty())
        printf("Peek operation cannot be performed\n");
    else {
        printf("Peek element is %d\n", queue[front]);
    }
}
void display() {
    int i;
    if (isEmpty())
        printf("No elements to display\n");
    printf("Elements are : ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
void main() {
    int choice, n;
    printf("1.Enqueue\n 2.Dequeue\n 3.Peek\n 4.Display\n 5.Exit\n");
    while (1) {
        printf("Enter your choice : ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", & n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        }
    }
}
