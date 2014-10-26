#include <stdio.h>
#include <stdlib.h>

void vetor_positivo(int *vetor)
{
    int i = 1,c;
    int n = 1;

    while(n > 0)
    {
        printf("Digite um valor:\n");
        scanf("%i",&n);
        vetor = (int*) realloc(vetor, i * sizeof(int));
        vetor[i-1] = n;
        i++;
    }

    printf("\nO vetor lido foi:\n\n");
    for (c = 0; c < i - 2; c++)
    {
        printf("%i ",vetor[c]);
    }
}


int main()
{
    int *vector = NULL;
    vetor_positivo(vector);

    return 0;
}
