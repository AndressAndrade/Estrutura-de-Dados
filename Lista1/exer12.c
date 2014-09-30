#include <stdio.h>
int main()
{
    int N,i,maior,menor;
    void maiormenor(int *v, int N, int *maior, int *menor);
    printf("Digite o numero de elementos de seu vetor de inteiros:\n");
    scanf("%i",&N);
    int v[N];
    printf("Digite o valor de cada elemento, separando por espaco:\n");
    for(i = 0; i < N; i++)
        {
            scanf(" %i",&v[i]);
        }
    maiormenor(v, N, &maior, &menor);
    printf("\nO menor elemento do vetor eh: %i\n", menor);
    printf("O maior elemento do vetor eh: %i\n", maior);
    return 0;
}
void maiormenor(int *v, int N, int *maior, int *menor)
{
    int x;
    if (N > 0)
    {
        *maior = v[0];
        *menor = v[0];
        for(x = 1; x < N; x++ )
        {
            if(v[x] > v[0])
            {
                *maior = v[x];
            }
            if(v[x] < v[0])
            {
                *menor = v[x];
            }
        }
    }
}
