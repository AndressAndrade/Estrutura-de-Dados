
void insertionSort(int* list, int size) {
    for (int j = 1; j < size; j++) {
        int aux = list[j];
        int i = j - 1;
        while (i >= 0 && list[i] > aux) {
            list[i+1] = list[i];
            i--;
        }
        list[i+1] = aux;
    }
}
