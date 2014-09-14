#include <stdio.h>

int main()
{
    int n,i,ocorre,maior;
    void maiorvezes(int v[], int n, int *maior, int *ocorre);
    printf("Digite o numero de elementos de seu vetor de inteiros:\n");
    scanf("%i",&n);
    int vetor[n];
    printf("Digite o valor de cada elemento, separando por espaco:\n");
    for(i = 0; i < n; i++)
    {
       scanf(" %i",&vetor[i]);
    }
    maiorvezes(vetor, n, &maior, &ocorre);
    printf("\nO maior elemento eh: %i\n", maior);
    printf("Esse elemento aparece: %i", ocorre);
    return 0;
}

void maiorvezes(int v[], int n, int *maior, int *ocorre)
{
    int i, j,temporaria;
    *ocorre = 0;
    for(i=0; i < n; ++i)
    {
        for(j= i + 1; j < n; ++j)
            {
                if(v[i] > v[j])
                {
                    temporaria = v[i];
                    v[i] = v[j];
                    v[j] = temporaria;
                }
            }
    }
    *maior = v[n-1];
    for(i = 0; i < n; i++)
    {
        if(v[i] == *maior)
        {
            *ocorre += 1;
        }

    }

}
