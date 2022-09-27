#include<stdio.h>

#include<string.h>

#include<ctype.h>

#define ss 30
char infix[30], mstack[30], res[30];
int top = -1, i, j = 0;
void push(char c) {
    if (top == ss - 1) {
        printf("Stack is full");
        return;
    }
    top++;
    mstack[top] = c;
}
char pop() {
    if (top == -1) {
        printf("Stack is empty");
        return;
    }
    return (mstack[top--]);
}
void main() {
    printf("Enter an infix expression\n");
    scanf("%s", infix);
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i])) {
            res[j++] = infix[i];
        } else {
            switch (infix[i]) {
            case '(':
                push(infix[i]);
                break;
            case ')':
                while (mstack[top] != '(') {
                    char ele = pop();
                    res[j++] = ele;
                }
                pop();
                break;
            case '$':
                push(infix[i]);
                break;
            case '/':
            case '*':
                while (mstack[top] == '/' || mstack[top] == '*' || mstack[top] == '$') {
                    char ele = pop();
                    res[j++] = ele;
                }
                push(infix[i]);
                break;
            case '+':
            case '-':
                while (mstack[top] == '/' || mstack[top] == '*' || mstack[top] == '$' ||
                    mstack[top] == '+' || mstack[top] == '-') {
                    char ele = pop();
                    res[j++] = ele;
                }
                push(infix[i]);
                break;
            }
        }
    }
    while (top != -1)
        res[j++] = pop();
    res[j] = '\0';
    printf("%s", res);
}
