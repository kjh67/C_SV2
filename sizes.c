#include <stdio.h>

void f(int* j) {int i = sizeof j; printf("%d\n", i);};
void f2(int* j) {int i = sizeof j; printf("%d\n", i);};

int main() {
    int i;
    i = sizeof(char);
    printf("%d\n", i);
    i = sizeof(int);
    printf("%d\n", i);
    int a; i = sizeof a;
    printf("%d\n", i);
    char b[5]; i = sizeof(b);
    printf("%d\n", i);
    char *c = b; i = sizeof(c);
    printf("%d\n", i);
    struct {int d; char e;} s; i = sizeof s;
    printf("%d\n", i);
    int j[5];
    int j2[3][10];
    f(j);
    f2(j2);
}