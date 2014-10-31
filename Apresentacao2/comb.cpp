#include <utility>

using namespace std;

static int novogap(int gap) {
    gap = (gap * 10) / 13; // gap / fatordeencolhimento ~= 1.3
    if (gap == 9 || gap == 10) {
        gap = 11; // estudos feitos mostraram, que o processo sempre
                  // passa pelos gap 9,10 ou 11 e que utilizar gap 11
                  // otimiza o resultado (combsort11)
    }
    if (gap < 1) {
        gap = 1;
    }

    return gap;
}

void combSort(int* list, int size) {
    int gap = size;         // gap recebe o tamanho do vetor
    while (true) {
        gap = novogap(gap);  // atualiza o gap
        bool swaped = false; // declara a variavel booleana que ira identificar a ocorrencia de uma troca em cada varredura

        for (int i = 0; i < size-gap; i++) {
            int j = i + gap; // distancia de i ate j, igual ao gap
            if (list[i] > list[j]) { // compara os valores separados pelo gap
                swap(list[i], list[j]); //exerce a troca caso necessario
                swaped = true; // houve uma troca, entao trocado = true
            }
        }
        if (gap == 1 && !swaped) { //conclui a varredura caso nao tenha sido feito nenhuma troca e o gap = 1
            break;
        }
    }
}
