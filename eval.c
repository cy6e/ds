#include<string.h>

#include<string.h>

#include<ctype.h>

#include<math.h>

#define ss 30
int st[ss];
int top = -1, ans = 0;
void push(int ele) {
    if (top == ss - 1) {
        printf("stack is full\n");
        return;
    }
    top++;
    st[top] = ele;
}
int pop() {
    int a;
    if (top == -1) {
        printf("stack is empty\n");
        return;
    }
    a = st[top];
    top--;
    return a;
}
void main() {
    char postfix[25], ele;
    int i = 0, num1, num2;
    printf("enter the postfix expression\n");
    scanf("%s", postfix);
    printf("post fix expression is %s\n", postfix);
    while (postfix[i] != '\0') {
        ele = postfix[i];
        if (isdigit(ele)) {
            push(ele - '0');
        } else {
            num1 = pop();
            num2 = pop();
            switch (ele) {
            case '$':
                ans = pow(num2, num1);
                break;
            case '/':
                ans = num2 / num1;
                break;
            case '*':
                ans = num2 * num1;
                break;
            case '-':
                ans = num2 - num1;
                break;
            case '+':
                ans = num2 + num1;
                break;
            }
            push(ans);
        }
        i++;
    }
    printf("answer =%d\n", pop());
}
