#include <utility>

using namespace std;

void shellSort(int* list, int size) {
    int i, j, value;
    int gap = 1;
    do {
    gap = 3 * gap + 1;
    } while(gap < size);
    do {
    gap /= 3;
    for(i = gap; i < size; i++) {
        value = list[i];
        j = i - gap;
        while(j >= 0 && value < list[j]) {
            list [j + gap] = list[j];
            j -= gap;
       }
        list [j + gap] = value;
    }
    } while(gap > 1);
}
