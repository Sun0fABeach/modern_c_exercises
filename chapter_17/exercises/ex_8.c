#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    int value;
    struct node *next;
} Node;

Node *stack_top = NULL; //topmost entry of the stack


void make_empty()
{
    while(stack_top) {
        Node *tmp = stack_top->next;
        free(stack_top);
        stack_top = tmp;
    }
}

bool is_empty()
{
    return !stack_top;
}

bool push(int value)
{
    Node *new = malloc(sizeof(Node));
    if(!new) return false;
    *new = (Node){.value = value, .next = stack_top};
    stack_top = new;
    return true;
}

int pop()
{
    if(!stack_top) {
        fputs("Tried to pop from empty stack!", stderr);
        exit(EXIT_FAILURE);
    }

    int return_value = stack_top->value;
    Node *to_delete = stack_top;
    stack_top = stack_top->next;
    free(to_delete);
    return return_value;
}


int main()
{
    push(3);
    push(4);
    printf("3 times 4: %d\n", pop() * pop());
    push(5);
    printf("Is empty? (not): %hhu\n", is_empty());
    make_empty();
    printf("Is empty? (yes): %hhu\n", is_empty());

    exit(EXIT_SUCCESS);
}
