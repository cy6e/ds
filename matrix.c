#include<stdio.h>

void main() {
    int a[20][20], b[20][20], sum[20][20], sub[20][20];
    int i, j, n, m;
    printf("Enter no. of rows of 1st matrix : ");
    scanf("%d", & n);
    printf("Enter no. of columns of 1st matrix: ");
    scanf("%d", & m);
    printf("Enter the elements for 1st matrix :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", ( * (a + i) + j));
    }
    printf("Enter the elements for 2nd matrix :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", ( * (b + i) + j));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            *( * (sum + i) + j) = * ( * (a + i) + j) + * ( * (b + i) + j);
            *( * (sub + i) + j) = * ( * (a + i) + j) - * ( * (b + i) + j);
        }
    }
    printf("Addition of 2 matrices :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d\t", *( * (sum + i) + j));
        printf("\n");
    }
    printf("Substraction of 2 matrices :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d\t", *( * (sub + i) + j));
        printf("\n");
    }
}
