#include <stdio.h>

#include <stdlib.h>

struct node {
    int info;
    struct node * next;
};
struct node * head; //S
void push() {
    int valueTobePushed;
    struct node * top = (struct node * ) malloc(sizeof(struct node));
    if (top == NULL) {
        printf("Insert is not possible \n");
        exit(1);
    } else {
        printf("Enter the value to be pushed :");
        scanf("%d", & valueTobePushed);
        if (head == NULL) {
            printf("This is the first Element \n");
            top -> info = valueTobePushed;
            top -> next = NULL;
            head = top;
        } else {
            top -> info = valueTobePushed;
            top -> next = head;
            head = top;
        }
        printf("Element Inserted is %d\n", head -> info);
    }
}
void pop() {
    int valueDeleted;
    struct node * top;
    if (head == NULL) {
        printf("STACK IS EMPTY \n");
    } else {
        valueDeleted = head -> info;
        top = head;
        head = head -> next;
        printf(" Value deleted = %d\n", valueDeleted);
        free(top);
    }
}
void display() {
    struct node * top = head;
    if (head == NULL) {
        printf("STACK IS EMPTY \n");
    } else {
        while (top != NULL) {
            printf("%d ", top -> info);
            top = top -> next;
            printf("\n");
        }
    }
}
int main() {
    int choice, ele;
    printf("1.push\n2.pop\n3.display\n4.exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            return 0;
        }
    }
}
