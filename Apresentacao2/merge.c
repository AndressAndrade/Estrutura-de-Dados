#include <stdlib.h>

void merge(int list[], int size) {
    int mid;
    int i, j, k;
    int * tmp;

    tmp = (int * ) malloc(size * sizeof(int));
    mid = size / 2;
    i = 0;
    j = mid;
    k = 0;

    while (i < mid && j < size) {
        if (list[i] <= list[j]) {
            tmp[k] = list[i++];
        } else {
            tmp[k] = list[j++];
        }
        ++k;
    }

    if (i == mid) {
        while (j < size) {
            tmp[k++] = list[j++];
        }
    } else {
        while (i < mid) {
            tmp[k++] = list[i++];

        }
    }

    for (i = 0; i < size; ++i) {
        list[i] = tmp[i];
    }

    free(tmp);
}

void merge_sort(int list[], int size) {
    int mid;

    if (size > 1) {
        mid = size / 2;
        merge_sort(list, mid);
        merge_sort(list + mid, size - mid);
        merge(list, size);
    }
}