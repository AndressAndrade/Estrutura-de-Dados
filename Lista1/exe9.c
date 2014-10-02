#include <stdio.h>

int main()
{
        int N,M,x,*resultado;
        int somadevetores(int N, int M, int v1[], int v2[], int *v3);
        printf("Digite o numero de elementos de seu primeiro vetor:\n");
        scanf("%i",&N);
        int v1[N];
        printf("Digite os elementos separando por espaco:\n");
        for(x = 0; x < N; x++)
        {
            scanf("%i",&v1[x]);
        }
        printf("Digite o numero de elementos de seu segundo vetor: \n");
        scanf("%i",&M);
        int v2[M];
        printf("Digite os elementos separando por espaco:\n");
        for(x = 0; x < M; x++)
        {
            scanf("%i",&v2[x]);
        }
        int v3[N];
        printf("A soma dos dois vetores eh:\n");
        somadevetores(N, M, v1, v2, &v3);
        for(x = 0; x < N; x++)
        {
            printf("%i ",v3[x]);
        }

}

int somadevetores(int N, int M, int *v1, int *v2, int *v3)
{
    int i;
    if(M == N)
    {
        for(i=0; i < N; i++)
        {
            v3[i] = v1[i] + v2[i];
        }
        return 0;
    }
    else
    {
        return 1;
    }
}
