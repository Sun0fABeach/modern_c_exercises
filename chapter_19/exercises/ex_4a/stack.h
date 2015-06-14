#include <stdbool.h>

typedef struct stack Stack;

Stack *new_stack(unsigned int size);
bool push(Stack *stack, int item);
int pop(Stack *stack);
bool is_empty(Stack *stack);
bool is_full(Stack *stack);
void make_empty(Stack *stack);
void destroy(Stack *stack);
