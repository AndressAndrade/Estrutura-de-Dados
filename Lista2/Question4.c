#include <stdio.h>
int main()
{
    int N,i,max,min;
    void mm(int *v, int N, int *max, int *min);
    printf("Digite o numero de elementos de seu vetor de inteiros:\n");
    scanf("%i",&N);
    int v[N];
    printf("Digite o valor de cada elemento, separando por espaco:\n");
    for(i = 0; i < N; i++)
    {
        scanf(" %i",&v[i]);
    }
    mm(v, N, &max, &min);
    printf("\nO elemento minimo do vetor eh: %i\n", min);
    printf("O elemento maximo do vetor eh: %i\n", max);
    return 0;
}
void mm(int *v, int N, int *max, int *min)
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
    *max = v[N-1];
    *min = v[0];

}
