#include <stdlib.h>
#include <stdio.h>

typedef struct inner *inner_p;
typedef struct outer *outer_p;

struct inner {
    int i;
};

struct outer {
    int num;
    inner_p arr[];
};


int main() {
    inner_p q = malloc(sizeof(struct inner));
    inner_p r = malloc(sizeof(struct inner));
    inner_p s = malloc(sizeof(struct inner));
    q->i = 0;
    r->i = 0;
    s->i = 0;


    ++q->i;
    printf("%d\n", q->i);
    printf("%d\n", r++->i);
    
}