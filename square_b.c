#include <stdio.h>

int main() {
    int A[] = {1,2,3,4,5};
    int b = 3;
    int c = 2;

    printf("%d\n", A[b]);
    printf("%d\n", *(A+b));

    printf("%d\n", b[A]);

    int x = (b, *(A+c));
    int y = A[b,c];
    printf("%d\n", x);
    printf("%d\n", y);

    int D[][5] = {{1,2,3,4,5},{6,7,8,9},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    printf("%d\n", D[b][c]);
    printf("%d\n", *(*(D+b)+c));
}