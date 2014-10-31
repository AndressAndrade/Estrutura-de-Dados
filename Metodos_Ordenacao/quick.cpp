#include <utility>

using namespace std;

static int partition(int* list, int size) {
    swap(list[size/2], list[size-1]);
    int index = 0;
    for (int i = 0; i < size-1; ++i) {
        if (list[i] < list[size-1]) {
            swap(list[i], list[index]);
            ++index;
        }
    }
    swap(list[index], list[size-1]);
    return index;
}

void quickSort(int* list, int size) {
    if (size <= 1) return;
    int halfsz = partition(list, size);
    quickSort(list, halfsz);
    quickSort(list+halfsz+1, size-halfsz-1);
}
