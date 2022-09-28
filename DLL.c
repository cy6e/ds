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
void ise() {
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
    struct node * temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = p;
    p -> prev = temp;
    printf("%d is inserted\n", p -> data);
}
void isp() {
    int ele, pos;
    struct node * p = (struct node * ) malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d", & ele);
    printf("Enter the position: ");
    scanf("%d", & pos);
    p -> data = ele;
    p -> next = NULL;
    p -> prev = NULL;
    if (pos == 0) {
        p -> next = head;
        head -> prev = p;
        head = p;
        printf("%d is inserted at %d\n", ele, pos);
        return;
    }
    struct node * temp = head;
    int i = 0;
    while (i < pos - 1) {
        temp = temp -> next;
        if (temp == NULL) {
            printf("Insert is not possible\n");
            return;
        }
        i++;
    }
    p -> next = temp -> next;
    temp -> next -> prev = p;
    temp -> next = p;
    p -> prev = temp;
    printf("%d is inserted at %d pos\n", ele, pos);
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
void dee() {
    struct node * p, * temp = head, * ptr;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp -> next != NULL) {
        ptr = temp;
        temp = temp -> next;
    }
    printf("%d is deleted\n", temp -> data);
    ptr -> next = NULL;
    free(temp);
}
void dep() {
    int pos;
    struct node * p;
    printf("Enter the position to be deleted: ");
    scanf("%d", & pos);
    if (pos == 0) {
        p = head;
        head = head -> next;
        head -> prev = NULL;
        printf("%d is deleted at %d\n", p -> data, pos);
        free(p);
        return;
    }
    struct node * temp = head;
    int i = 0;
    while (i < pos - 1) {
        temp = temp -> next;
        i++;
    }
    p = temp -> next;
    temp -> next = p -> next;
    if (p -> next == NULL) {
        printf("%d is deleted at %d\n", p -> data, pos);
        return;
    }
    p -> next -> prev = temp;
    printf("%d is deleted at %d\n", p -> data, pos);
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
void displayB() {
    struct node * temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    while (temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> prev;
    }
    printf("\n");
}
int search() {
    int ele;
    if (head == NULL) {
        printf("List is empty\n");
        return -2;
    }
    printf("Enter the element to be searched\n");
    scanf("%d", & ele);
    struct node * temp = head;
    int count = 0;
    while (temp != NULL) {
        if (temp -> data == ele)
            return count;
        temp = temp -> next;
        count = count + 1;
    }
    return -1;
}
void deleteAfter() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head -> next == NULL) {
        printf("Deletion is not possible\n");
        return;
    }
    int ele;
    printf("Enter the element to be deleted after\n");
    scanf("%d", & ele);
}
void main() {
        int ch, res;
        printf("1.Insert at the top\n 2.Insert at the end\n 3.Insert at a pos\n 4.Delete
            at the top\ n 5. Delete at the end\ n6.Delete at a pos\ n7.DisplayF\ n 8. DisplayB\ n9.search\ n10.Exit\ n ");
            while (1) {
                printf("Enter your choice: ");
                scanf("%d", & ch);
                switch (ch) {
                case 1:
                    isf();
                    break;
                case 2:
                    ise();
                    break;
                case 3:
                    isp();
                    break;
                case 4:
                    def();
                    break;
                case 5:
                    dee();
                    break;
                case 6:
                    dep();
                    break;
                case 7:
                    displayF();
                    break;
                case 8:
                    displayB();
                    break;
                case 9:
                    res = search();
                    if (res > 0)
                        printf("Element found at %d\n", res);
                    else if (res == -1)
                        printf("Element not found\n");
                    break;
                case 10:
                    exit(0);
                default:
                    printf("Invalid position");
                }
            }
        }
