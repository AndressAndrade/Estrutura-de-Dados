#include <stdio.h>
#include<stdlib.h>


int *aloca_vetor(int n)
{
    int *vetor;
    vetor = malloc(n*sizeof(int));
    return vetor;
}

void preenche_imprime(int *vector,int n)
{
    int i;
    printf("Digite os valores de seu vetor, separando por espaco:\n");
    for(i = 0; i < n; i++)
    {
        scanf(" %i",&vector[i]);
    }
    printf("\nO vetor lido foi:\n\n");
    for(i = 0; i < n; i++)
    {
        printf("%i ",vector[i]);
    }
    printf("\n");
}

int main()
{
    int x,*vetor;
    printf("Digite o tamanho do vetor para alocacao:\n");
    scanf("%i",&x);
    vetor = aloca_vetor(x);
    preenche_imprime(vetor,x);
    return 0;

}
