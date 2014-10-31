#include <utility>

using namespace std;

void bubbleSort(int* list, int size) {
    for (int i = 0; i < (size -1); i++) {
        for (int j = 0; j < size - (i + 1); j++) {
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
    }
}
