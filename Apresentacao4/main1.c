#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "queue.c"

int main(void)
{
    queue* qu = queue_alloc();
    srand(time(NULL));

    for (int i = 0; i < 20; ++i) {
        int c;
        c = rand() % 100;
        queue_push(qu, (void*)(long)c);
    }
    queue_push(qu, (void*)(long)17);
    queue_each(qu, print_element);

    printf("\n\nFila ordenada por QuickSort:\n\n");
    queue_sort(qu, sort_op);
    queue_each(qu, print_element);

    printf("\n\nTamanho da Fila:\n\n");
    int x = queue_size(qu);
    printf("%i",x);

    printf("\n\nTerceiro da Fila:\n\n");
    int y = queue_nth(qu, 2);
    printf("%i",y);

    printf("\n\nPosicao do elemento 17:\n\n");
    int test(void* a) {
        return (long)a == 17;
    }
    int z = queue_find(qu, test);
    printf("%i\n",z+1);

    for (int i = 0; i < 21; ++i) {
        queue_shift(qu);
    }

    queue_free(qu);
}
