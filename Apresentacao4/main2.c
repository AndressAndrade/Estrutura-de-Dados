#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "queue.c"

struct Person {
    const char* name;
    unsigned age;
};

struct Person* create_person(const char* name, unsigned age) {
    struct Person* p = malloc(sizeof(struct Person));
    p->name = name;
    p->age = age;
    return p;
}

void free_person(void* p) {
    free(p);
}

void print_person(void* vp) {
    struct Person* p = (struct Person*)vp;
    printf("\"%s\" ", p->name);
}

// Comparar as pessoas por idade.
// Na fila a pessoa mais velha tem que ter prioridade :)
int compare_person(void* vpa, void* vpb) {
    struct Person* pa = (struct Person*)vpa;
    struct Person* pb = (struct Person*)vpb;
    return pa->age > pb->age;
}

int main(void) {
    queue* qu = queue_alloc();
    queue_push(qu, create_person("Alberto", 18));
    queue_push(qu, create_person("Beto", 50));
    queue_push(qu, create_person("Carlos", 34));

    puts("Antes de ordenar:");
    queue_each(qu, print_person);
    puts("\n");

    queue_sort(qu, compare_person);

    puts("Depois de ordenar:");
    queue_each(qu, print_person);
    puts("\n");

    printf("Primeira pessoa: %s\n\n", ((struct Person*)queue_front(qu))->name);

    puts("Liberando a memoria...");
    queue_each(qu, free_person);
    queue_free(qu);

}
