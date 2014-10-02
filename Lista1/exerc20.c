#include <stdio.h>
int main()
{
    int N,i;
    printf("Digite o numero de elementos de seu vetor de inteiros:\n");
    scanf("%i",&N);
    int v[N];
    printf("Digite o valor de cada elemento, separando por espaco:\n");
    for(i = 0; i < N; i++)
    {
        scanf(" %i",&v[i]);
    }
    int x;
    int *ptr = v;
    for(x=0; x<5; x++)
    {
        int n = ptr++;
        if (!(n % 2))
        printf("%i\n", n);
    }
}
