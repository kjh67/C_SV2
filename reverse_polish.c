#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack *stack_ptr;
typedef struct item *item_ptr;


struct stack {
    int data;
    stack_ptr ptr;
};


// implementing the stack functions; push, pop
void push(stack_ptr *stack, int data) {
    // stack is a pointer to a stack pointer; so we can change the pointer without needing to return anything
    stack_ptr new_stack = malloc(sizeof(struct stack));
    new_stack->data = data;
    new_stack->ptr = *stack;
    *stack = new_stack;
}

int pop(stack_ptr *stack) {
    stack_ptr s = *stack;
    int i = s->data;
    stack_ptr new_stack = s->ptr;
    free(s);
    *stack = new_stack;
    return i;
}



int eval(char** commands, int comm_len) {
    stack_ptr ex_stack = NULL;

    // for each command, check whether instruction; if so, pop operands from stack, do it, return result to stack
    for (int i=0; i<comm_len; i++) {
        char* command = commands[i];
        if (command[0] == '+') {
            // add last two stack values
            int a = pop(&ex_stack);
            int b = pop(&ex_stack);
            push(&ex_stack, a+b);
            printf("%d\n", a+b);
        }
        else if (command[0] == 'x') {
            // multiply last two stack values
            int a = pop(&ex_stack);
            int b = pop(&ex_stack);
            push(&ex_stack, a*b);
            printf("%d\n", a*b);
        }
        else {
            // read in a value; assume single digit for now
            int v = 0;
            int l = strlen(command);
            int mult = 1;
            for (int i = 1; i<=l; i++) {
                v += (command[l-i] - 48) * mult;
                mult = mult * 10;
            }
            push(&ex_stack, v);
            printf("%d\n", v);
        }
    }

    // assume that after finishing execution, the result is the last thing on the stack
    return pop(&ex_stack);
}



int main(int argc, char **argv) {
    char** ps = &(argv[1]);
    int result = eval(ps, argc-1);
    printf("Result is %d\n", result);

    // stack_ptr stack = NULL;
    // push(&stack, 2); 
    // printf("one push\n"); fflush(stdout);
    // push(&stack, 3);
    // printf("two push\n"); fflush(stdout);
    // printf("%d\n", pop(&stack));
    // printf("one pop\n"); fflush(stdout);
    // printf("%d\n", pop(&stack));
    // printf("two pop\n"); fflush(stdout);
}