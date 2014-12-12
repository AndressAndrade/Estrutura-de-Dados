#pragma once

typedef struct stack_t stack;

// create empty
// O(1)
stack* stack_alloc(void);

// free whole stack
// O(size)
void stack_free(stack* st);

// add element, read top, remove top
// O(1)
void  stack_push(stack* st, void* el);
void* stack_top(stack* st);
void* stack_pop(stack* st);

// sorts by the comp function using quick sort
// O(n log n)
void stack_sort(stack* st, int(*comp)(void*, void*));

// very bad method to remove an item
// O(n)
void stack_remove(stack* st, unsigned i);

// read first element
// O(1)
void* stack_first(stack* st);

// get nth element
// O(n)
void* stack_nth(stack* st, unsigned i);

// get size
// O(1)
unsigned stack_size(stack* st);

// calls the argument function on each element of the stack
// O(n)
void stack_each(stack* st, int(*action)(void*));

