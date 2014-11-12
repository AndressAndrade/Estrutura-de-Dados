#pragma once

typedef struct queue_t queue;

// create empty queue
// O(1)
queue* queue_alloc(void);

// free whole queue
// O(size)
void queue_free(queue* qu);

// add element, read front, remove front
// O(1)
void  queue_push(queue* qu, void* el);
void* queue_front(queue* qu);
void* queue_shift(queue* qu);

// quick sort
// use the comp parameter to compare two elements
// O(n log n)
void queue_sort(queue* qu, int(*comp)(void*, void*));

// read last element
// O(1)
void* queue_last(queue* qu);

// get nth element
// O(n)
void* queue_nth(queue* qu, unsigned i);

// find one element
// use the test parameter to test if the element is the one you want
// O(n)
unsigned queue_find(queue* qu, int(*test)(void*));

// get size
// O(1)
unsigned queue_size(queue* qu);

// calls the argument function on each element of the queue
// O(n)
void queue_each(queue* qu, void(*action)(void*));

