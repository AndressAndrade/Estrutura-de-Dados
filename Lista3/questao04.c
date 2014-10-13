#include <stdio.h>
#include <stdlib.h>

int *alocar(int n)
{
    int *vetor;
    vetor = malloc(n*sizeof(int));
    return vetor;
}

void parimpar(int *vector, int n)
{
    int i,pa = 0,im = 0;
    for(i = 0; i < n; i++)
    {
        if(vector[i]%2 == 0)
        {
            pa++;
        }
        else
        {
            im++;
        }

    }
    printf("\nO vetor tem %i numeros pares e %i numeros impares\n",pa,im);
}
int main()
{
    int *vetor,tamanho,i;
    printf("Digite o numero de elementos do seu vetor:\n");
    scanf("%i",&tamanho);
    vetor = alocar(tamanho);
    printf("Digite os elementos de seu vetor, separando por espaco:\n");
    for(i = 0; i < tamanho; i++)
    {
        scanf(" %i",&vetor[i]);
    }
    parimpar(vetor,tamanho);
    free(vetor);
    return 0;
}
