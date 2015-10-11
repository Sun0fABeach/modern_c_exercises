#include <stdbool.h>

typedef struct stack Stack;

Stack *new_stack();
void push(Stack *stack, int item);
int pop(Stack *stack);
bool is_empty(Stack *stack);
void make_empty(Stack *stack);
void destroy(Stack *stack);
