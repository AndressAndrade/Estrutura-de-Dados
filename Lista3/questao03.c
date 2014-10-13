#include <stdio.h>
#include <stdlib.h>

int *alocar_vetor(int n)
{
    int *vetor;
    vetor = malloc(n*sizeof(int));//a
    return vetor;
}
void preencher_vetor(int *vector)
{
    printf("Digite os 5 elementos do vetor, separando por espaco:\n");//b
    int i;
    for(i = 0; i < 5; i++)
    {
        scanf(" %i",&vector[i]);
    }
}

void imprime(int *vector)//c
{
    printf("\nOs elementos digitados foram:\n\n");
    int i;
    for(i = 0; i < 5; i++)
    {
        printf("%i ",vector[i]);
    }
    printf("\n");
}

int main()
{
    int *vetor;
    vetor = alocar_vetor(5);
    preencher_vetor(vetor);
    imprime(vetor);
    free(vetor); //d
    return 0;

}
