#include <stdbool.h>

typedef struct stack Stack;

Stack *create_stack(size_t size);
void destroy_stack(Stack *s);
void make_empty(Stack *s);
bool is_empty(Stack *s);
bool is_full(Stack *s);
void push(Stack *s, char c);
char pop(Stack *s);
