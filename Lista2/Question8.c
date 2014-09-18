#include <stdio.h>
int main()
{
    int N,i,maximo,minimo;
    void maximoMinimo(int *v, int N, int *maximo, int *minimo);
    printf("Digite o numero de elementos de seu vetor de inteiros:\n");
    scanf("%i",&N);
    int v[N];
    printf("Digite o valor de cada elemento, separando por espaco:\n");
    for(i = 0; i < N; i++)
    {
        scanf(" %i",&v[i]);
    }
    maximoMinimo(v, N, &maximo, &minimo);
    printf("\nO elemento maximo do vetor eh: %i\n", maximo);
    printf("O elemento minimo do vetor eh: %i\n", minimo);
    return 0;
}
void maximoMinimo(int *v, int N, int *maximo, int *minimo)
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
    *maximo = v[N-1];
    *minimo = v[0];

}
