#include <stdio.h>
int main()
{
    int N,i,maior;
    void omaior(int *v, int N, int *maior);
    printf("Digite o numero de elementos de seu vetor de inteiros:\n");
    scanf("%i",&N);
    int v[N];
    printf("Digite o valor de cada elemento, separando por espaco:\n");
    for(i = 0; i < N; i++)
        {
            scanf(" %i",&v[i]);
        }
    omaior(v, N, &maior);
    printf("O elemento maior do vetor eh: %i\n", maior);
    return 0;
}

void omaior(int *v, int N, int *maior)
{
    int i, j,temporaria;
    for(i=0; i < N; ++i)
        {
            for(j= i + 1; j < N; ++j)
                {
                    if(v[i] > v[j])
                        {
                            temporaria = v[i];
                            v[i] = v[j];
                            v[j] = temporaria;
                        }
                }
        }
    *maior = v[N-1];
}
