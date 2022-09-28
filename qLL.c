#include <stdio.h>

#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};
struct node * front, * rear;
void enqueue() {
    int ele;
    struct node * p = (struct node * ) malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d", & ele);
    p -> data = ele;
    p -> next = NULL;
    if (front == NULL) {
        front = p;
        rear = p;
        printf("%d is inserted\n", rear -> data);
    } else {
        rear -> next = p;
        rear = p;
        printf("%d is inserted\n", rear -> data);
    }
}
void dequeue() {
    struct node * p;
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    p = front;
    printf("%d is deleted\n", p -> data);
    front = front -> next;
    free(p);
}
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node * temp = front;
    while (temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Peek element is %d\n", front -> data);
}
void main() {
    int choice, ele;
    printf("1.Enqueue\n2.Dequeue\n3.display\n4.peek\n5.exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}
