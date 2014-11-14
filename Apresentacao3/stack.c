#include <stdlib.h>
#include <string.h>

#include "stack.h"

#define BLOCK_SIZE 3

// The stack itself
// It is a linked list of vectors
struct stack_t {
    struct stack_block_t* first;
    struct stack_block_t* last;
    unsigned size;
};

// A linear block from the stack
struct stack_block_t {
    struct stack_block_t* prev;
    struct stack_block_t* next;
    void* data[BLOCK_SIZE];
};

// Allocate an empty struct
stack* stack_alloc(void) {
    stack* st = malloc(sizeof(stack));
    memset(st, 0, sizeof(stack));
    return st;
}

// Free all blocks from the list
void stack_free(stack* st) {
    struct stack_block_t* current = st->first;
    while (current != st->last)
        free(current++);
    free(st);
}

// Internal: add block
static void add_block(stack* st) {
    struct stack_block_t* blk = malloc(sizeof(struct stack_block_t));
    memset(blk, 0, sizeof(struct stack_block_t));
    blk->prev = st->last;
    if (st->last)
        st->last->next = blk;
    st->last = blk;
    if (st->first == 0)
        st->first = blk;
}

// Internal: remove block
static void remove_block(stack* st) {
    struct stack_block_t* blk = st->last;
    st->last = blk->prev;
    if (st->last == 0)
        st->first = 0;
    free(blk);
}

void stack_push(stack* st, void* el) {
    if (st->size % BLOCK_SIZE == 0)
        add_block(st);

    st->last->data[st->size % BLOCK_SIZE] = el;
    ++st->size;
}

void* stack_top(stack* st) {
    return st->last->data[(st->size-1) % BLOCK_SIZE];
}

void* stack_pop(stack* st) {
    void* top = stack_top(st);
    --st->size;
    if (st->size % BLOCK_SIZE == 0)
        remove_block(st);
    return top;
}

static void** element_pointer(stack* st, unsigned i) {
    struct stack_block_t* current = st->first;
    while (i >= BLOCK_SIZE) {
        current = current->next;
        i -= BLOCK_SIZE;
    }
    return &current->data[i];
}

static void swap(void** a, void** b) {
    void* tmp = *a;
    *a = *b;
    *b = tmp;
}

static int partition(stack* st, int start, int size, int(*comp)(void*, void*)) {
    swap(element_pointer(st, start+size/2), element_pointer(st, start+size-1));
    void* pivot = stack_nth(st, start+size-1);
    struct stack_block_t* iblock = st->first;
    int i = start;
    while (i >= BLOCK_SIZE) {
        iblock = iblock->next;
        i -= BLOCK_SIZE;
    }
    struct stack_block_t* indexblock = iblock;
    int index = i;
    int index2 = 0;
    for (int ii = 0; ii < size-1; ++ii) {
        if (comp(iblock->data[i], pivot)) {
            swap(&iblock->data[i], &indexblock->data[index]);
            ++index;
            ++index2;
            if (index >= BLOCK_SIZE) {
                indexblock = indexblock->next;
                index -= BLOCK_SIZE;
            }
        }
        ++i;
        if (i >= BLOCK_SIZE) {
            iblock = iblock->next;
            i -= BLOCK_SIZE;
        }
    }
    swap(element_pointer(st, start+size-1), &indexblock->data[index]);
    return index2;
}

static void quick_sort(stack* st, int start, int size, int(*comp)(void*, void*)) {
    if (size <= 1) return;
    int halfsz = partition(st, start, size, comp);
    quick_sort(st, start, halfsz, comp);
    quick_sort(st, start+halfsz+1, size-halfsz-1, comp);
}

void stack_sort(stack* st, int(*comp)(void*, void*)) {
    quick_sort(st, 0, st->size, comp);
}

void* stack_first(stack* st) {
    return st->first->data[0];
}

void* stack_nth(stack* st, unsigned i) {
    return *element_pointer(st, i);
}

unsigned stack_size(stack* st) {
    return st->size;
}

int sort_op(void* a, void* b) {
    return (long)a > (long)b;
}

void stack_each(stack* st, void(*action)(void*)) {
    struct stack_block_t* block = st->first;
    unsigned i = 0;
    unsigned index = 0;
    while (index < st->size) {
        // Call the function
        action(block->data[i]);
        ++index;

        // Advance element
        ++i;
        if (i >= BLOCK_SIZE) {
            block = block->next;
            i -= BLOCK_SIZE;
        }
    }
}

void print_element(void* el) {
    printf("%ld ", (long)el);
}
