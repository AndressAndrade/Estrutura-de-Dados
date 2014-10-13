#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int n = 1;
    int i = 0;
    int c = 0;
    int *vetor;

    while(n > 0)
    {
        printf("Digite um valor:\n");
        scanf("%i",&n);
        vetor[i] = n;
        i++;
        c++;
    }
    printf("\nO vetor lido foi:\n\n");
    for(i = 0; i < c; i++)
    {
        printf("%i ",vetor[i]);
    }
    return 0;

    
}
