#include "process.h"
#include "stack.c"
#include <stdlib.h>

struct process_manager {
    stack* st;
};

processes* processAlloc(void) {
    processes* prcs = malloc(sizeof(*prcs));
    prcs->st = stack_alloc();
    return prcs;
}

int processInsert(processes* prcs, process el) {
    process* elm = malloc(sizeof(*elm));
    *elm = el;
    stack_push(prcs->st, elm);
}


static int finderId;
static int foundIndex;
static int findId(void* e) {
    if (((process*)e)->processId == finderId)
        return 1;

    ++foundIndex;
    return 0;

}
void processRemoveByID(processes* prcs, int id) {
    finderId = id;
    foundIndex = 0;
    stack_each(prcs->st, findId);
    stack_remove(prcs->st, foundIndex);
}

process processPop(processes* prcs) {
    process* pp = (process*)stack_pop(prcs->st);
    process p = *pp;
    free(pp);
    return p;
}

process processTop(processes* prcs) {
    return *(process*)stack_top(prcs->st);
}

process processBottom(processes* prcs) {
    return *(process*)stack_nth(prcs->st, 0);
}

process processGetByID(processes* prcs, int id)  {
    finderId = id;
    foundIndex = 0;
    stack_each(prcs->st, findId);
    return *(process*)stack_nth(prcs->st, foundIndex);
}

int sortSupermarketId;
static int sortValueSupermarket(void* a, void* b) {
    process* pa = (process*)a;
    process* pb = (process*)b;
    if (pa->supermarketId == sortSupermarketId && pb->supermarketId != sortSupermarketId)
        return 1;
    if (pa->supermarketId != sortSupermarketId && pb->supermarketId == sortSupermarketId)
        return 0;
    return pa->value > pb->value;
}
void processPrioritizeSupermarket(processes* prcs, int supermarketId) {
    sortSupermarketId = supermarketId;
    stack_sort(prcs->st, sortValueSupermarket);
}

static int sortValue(void* a, void* b) {
    process* pa = (process*)a;
    process* pb = (process*)b;
    return pa->value > pb->value;
}
void processPrioritizeValue(processes* prcs) {
    stack_sort(prcs->st, sortValue);
}

unsigned processAmount(processes* prcs) {
    return stack_size(prcs->st);
}

static void(*callbackFunc)(process el);
static int eachCallback(void* e) {
    callbackFunc(*(process*)e);
    return 0;
}

void processEach(processes* prcs, void(*callback)(process el)) {
    callbackFunc = callback;
    stack_each(prcs->st, eachCallback);
}

