#include <stdio.h>
#include <stdlib.h>

int allocvetor(int n)
{
    int *vetor,i;
    vetor = malloc(n*sizeof(int));
    for(i = 0; i < 10; i++)
    {
        vetor[i] = 0;//inicializo vetor em 0
    }
    return vetor;
}

int ihash1(int n, int *vetor)
{

    vetor[n] += 1;

    return vetor[n];
}

int bhash1(int n, int *vetor)
{
    return vetor[n];
}

int main()
{
    int x,i,y;
    int *k = allocvetor(11);
    for(i = 0; i < 5; i++)
    {
        printf("Digite um valor a ser inserido, entre 0 e 10: ");
        scanf("%i",&x);
        ihash1(x,k);
    }
    printf("\nDigite um valor para ser buscado:\n");
    scanf("%i",&x);
    y = bhash1(x,k);
    if (y == 1)
    {
        printf("\nO elemento esta no vetor.\n");
    }
    else if(y > 1)
    {
        printf("\nForam encontrados %i elementos\n",y);
    }
    else{
        printf("\nO elemento nao esta no vetor.\n");
    }

    free(k);
    return 0;
}
