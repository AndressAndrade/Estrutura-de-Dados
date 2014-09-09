#include <stdio.h>

int main(void)
{

    int vetor[5];
    int i;
    int *ponteiro = vetor;
    printf("Digite 5 valores inteiros, separados por espaco:\n");
    scanf("%i %i %i %i %i",&vetor[0],&vetor[1],&vetor[2],&vetor[3],&vetor[4]);
    for(i = 0; i < 5; i++)
    {
        *(ponteiro + i) *= 2;
        printf("%i ", vetor[i]);
    }

    return 0;

}
