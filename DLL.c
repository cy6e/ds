#include<stdio.h>

#include<stdlib.h>

struct node {
    int data;
    struct node * next, * prev;
};
struct node * head = NULL;
void isf() {
    int ele;
    struct node * p = (struct node * ) malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d", & ele);
    p -> data = ele;
    p -> next = NULL;
    p -> prev = NULL;
    if (head == NULL) {
        head = p;
        printf("%d is inserted\n", head -> data);
        return;
    }
    p -> next = head;
    head -> prev = p;
    head = p;
    printf("%d is inserted\n", head -> data);
}

void def() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head -> next == NULL) {
        printf("%d is deleted\n", head -> data);
        head = head -> next;
        free(head);
        return;
    }
    struct node * p;
    p = head;
    printf("%d is deleted\n", p -> data);
    head = head -> next;
    head -> prev = NULL;
    free(p);
}

void displayF() {
    struct node * temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void main() {
        int ch, res;
        printf("1.Insert at the top\n2.Delete at the top\n3.DisplayF\n4.Exit\n");
            while (1) {
                printf("Enter your choice: ");
                scanf("%d", & ch);
                switch (ch) {
                case 1:
                    isf();
                    break;
                case 2:
                    def();
                    break;
                case 3:
                    displayF();
                    break;
                case 4:
                    exit(0);
                default:
                    printf("Invalid position");
                }
            }
        }
