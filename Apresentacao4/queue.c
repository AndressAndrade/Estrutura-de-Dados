#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "queue.h"

#define BLOCK_SIZE 3

// The queue itself
// It is a linked list of blocks
struct queue_t {
    struct queue_block_t* first;
    struct queue_block_t* last;
    unsigned size; // The number of elements on the queue. This is not the number of blocks
    unsigned space; // How many empty elements there is on the first block. As we always
                    // remove from it, there will be empty space on the beginning.
};

// A block from the queue.
// Each block contains a vector and pointers to the next block
// This is a element from the linked list.
struct queue_block_t {
    struct queue_block_t* next;
    void* data[BLOCK_SIZE];
};

// Allocate an empty struct
queue* queue_alloc(void) {
    queue* qu = malloc(sizeof(queue));
    // Set the first and last blocks to null so that we have no blocks
    // Also set the size to zero as there are no elements
    // The 'space' is irrelenvant here, have no meaning. But it is set to zero too.
    memset(qu, 0, sizeof(queue));
    return qu;
}

// Free all blocks from the list
void queue_free(queue* qu) {
    // Starting from the first block, we will free all blocks.
    struct queue_block_t* current = qu->first;
    while (current != qu->last)
        free(current++);
    free(qu);
}

// Internal: add block to end
// When we are pushing a new element and the last block is already full,
// a new block must be added to the linked list
static void add_block(queue* qu) {
    // Allocate and zeroout the new block
    struct queue_block_t* blk = malloc(sizeof(struct queue_block_t));
    memset(blk, 0, sizeof(struct queue_block_t));
    // Insert it on the linked list. Being careful to also update the last/first values.
    if (qu->last)
        qu->last->next = blk;
    qu->last = blk;
    if (qu->first == 0)
        qu->first = blk;
}

// Internal: remove block from start
// When elements are being removed from the queue, the first block will get free.
// So, we can remove it. It happens when space == BLOCK_SIZE. Also set space to zero again.
static void remove_block(queue* qu) {
    struct queue_block_t* blk = qu->first;
    qu->first = blk->next;
    if (qu->first == 0)
        qu->last = 0;
    free(blk);
    qu->space = 0;
}

void queue_push(queue* qu, void* el) {
    // If the amount of elements is proportional to the BLOCK_SIZE, then the last block is full.
    // We should insert a new block.
    if ((qu->space+qu->size) % BLOCK_SIZE == 0)
        add_block(qu);

    // The remaining is the index on the last block.
    // Increase size as well.
    qu->last->data[(qu->space + qu->size) % BLOCK_SIZE] = el;
    ++qu->size;
}

void* queue_front(queue* qu) {
    // The first element if right after the empty space on the first block
    return qu->first->data[qu->space];
}

void* queue_shift(queue* qu) {
    // First get the front so that we can return it.
    void* front = queue_front(qu);
    // Reduce size and increase the empty space on the first block
    --qu->size;
    ++qu->space;
    // If the whole first block is free, remove it.
    if (qu->space == BLOCK_SIZE)
        remove_block(qu);

    return front;
}

// Internal: Getting a block, advance i/BLOCK_SIZE blocks after it and return.
static struct queue_block_t* advance_block(struct queue_block_t* source, unsigned i) {
    while (i >= BLOCK_SIZE) {
        source = source->next;
        i -= BLOCK_SIZE;
    }
    return source;
}

// Internal: Get a pointer to the ith element
static void** element_pointer(queue* qu, unsigned i) {
    // We have to skip i+space elements from the begining.
    i += qu->space;
    // Get the block that contains this index by advancing from the first
    struct queue_block_t* block = advance_block(qu->first, i);
    // Return a pointer to the element.
    return &block->data[i % BLOCK_SIZE];
}

// Internal: Simply swap two elements. Sort will use this.
static void swap(void** a, void** b) {
    void* tmp = *a;
    *a = *b;
    *b = tmp;
}

// Internal: This is part of the quick sort algorithm.
// From the queue, partition it from start to start+size, using the comparator comp.
// A element (pivot) from the middle will be selected and moved to the end.
// Then the list will be sorted by "greater than or less than the pivot"
static int partition(queue* qu, int start, int size, int(*comp)(void*, void*)) {
    // Swap the middle element with the last one
    swap(element_pointer(qu, start+size/2), element_pointer(qu, start+size-1));
    // Get the value of the pivot
    void* pivot = queue_nth(qu, start+size-1);

    // Get the block and the index to the first element
    struct queue_block_t* iblock = advance_block(qu->first, start);
    int i = start % BLOCK_SIZE;
    // Use another pair of indexes. Also starting from the first
    struct queue_block_t* indexblock = iblock;
    int index = i;
    // Count how many elements we have advanced
    int index2 = 0;

    // Start a loop over each element
    for (int ii = 0; ii < size-1; ++ii) {
        // Compare it with the pivot and if true, advance index
        if (comp(iblock->data[i], pivot)) {
            swap(&iblock->data[i], &indexblock->data[index]);
            ++index;
            ++index2;
            if (index >= BLOCK_SIZE) {
                indexblock = indexblock->next;
                index -= BLOCK_SIZE;
            }
        }
        // Advance to the next element
        ++i;
        if (i >= BLOCK_SIZE) {
            iblock = iblock->next;
            i -= BLOCK_SIZE;
        }
    }
    // Swap back the pivot from the end to the index
    swap(element_pointer(qu, start+size-1), &indexblock->data[index]);
    // Return how many elements we have advanced
    return index2;
}

// Internal: The classic quick sort. Nothing unusual here
static void quick_sort(queue* qu, int start, int size, int(*comp)(void*, void*)) {
    if (size <= 1) return;
    int halfsz = partition(qu, start, size, comp);
    quick_sort(qu, start, halfsz, comp);
    quick_sort(qu, start+halfsz+1, size-halfsz-1, comp);
}

// To sort the queue we skip the space and sort size elements
void queue_sort(queue* qu, int(*comp)(void*, void*)) {
    quick_sort(qu, qu->space, qu->size, comp);
}

// The last element from the queue, we must advance size and space elements and go back one
void* queue_last(queue* qu) {
    return qu->last->data[(qu->space + qu->size - 1) % BLOCK_SIZE];
}

// To get the nth element, derreference a pointer to it.
void* queue_nth(queue* qu, unsigned i) {
    return *element_pointer(qu, i);
}

// Simply the size.
unsigned queue_size(queue* qu) {
    return qu->size;
}

// Find a element on the queue. The test function is used to
// check if this is the element we want.
unsigned queue_find(queue* qu, int test(void*)) {
    // If the size is zero, the element is not here!
    if (qu->size == 0)
        return -1;
    // Start from the first block and from the beginning of the queue
    struct queue_block_t* block = qu->first;
    unsigned i = qu->space;
    // The index we will return
    unsigned index = 0;
    // If the element is not found
    while (!test(block->data[i])) {
        // Advance both the counter and the index
        ++i;
        ++index;
        // If we already checked all elements, we failed.
        if (index == qu->size)
            return -1;
        // Skip the block if needed
        if (i >= BLOCK_SIZE) {
            block = block->next;
            i -= BLOCK_SIZE;
        }
    }
    return index;
}

void queue_each(queue* qu, void(*action)(void*)) {
    // Start from the first block and from the beginning of the queue
    struct queue_block_t* block = qu->first;
    unsigned i = qu->space;
    // A simple counter
    unsigned index = 0;
    // While we didn't get to the end
    while (index < qu->size) {
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

int sort_op(void* a, void* b) {
    return (long)a > (long)b;
}

void print_element(void* el) {
    printf("%ld ", (long)el);
}

