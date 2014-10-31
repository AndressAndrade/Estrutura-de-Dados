void selection_sort(int list[], int size) { 
    int i, k, min, aux;

    // Percorre todo o vetor
    for (i = 0; i < (size-1); i++) {
        min = i;
        // Percorre o vetor novamente verificando se existe algum elemento com valor inferior ao elemento na posição "i"
        for (k = (i+1); k < size; k++) {
            if(list[k] < list[min]) {
                min = k;
            }
        }
        // Se houver, fazemos uma troca entre o elemento na posição i e o menor, ordenando, desta forma, o vetor
        if (i != min) {
            aux = list[i];
            list[i] = list[min];
            list[min] = aux;
        }
    }
}