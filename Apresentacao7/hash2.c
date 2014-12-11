#include <stdio.h>
#include <stdlib.h>

int allocvetor(int n)
{
    int *vetor,i;
    vetor = malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
    {
        vetor[i] = 0;//inicializo vetor em 0
    }
    return vetor;
}

void ihash1(int n, int *vetor)
{
    int key = n % 10;
    if(vetor[key] == 0)
    {
        vetor[key] = n;
    }
    else
    {
        printf("\nHouve colisao, usar hash2\n");
        ihash2(n, vetor);
    }
}

void ihash2(int n, int *vetor)
{
    int a = 1;
    int key = (n % 10 ) + a;
    while(vetor[key] != 0)
    {
        a++;
        key = (n % 10 ) + a;
    }
    vetor[key] = n;
}

int bhash1(int n, int *vetor)
{
    int key = n % 10;
    return vetor[key];
}

int bhash2(int n, int *vetor)
{
    int a;
    int key = (n % 10 ) + a;
    if(vetor[key] == n)
    {
        return vetor[key];
    }
    else
    {
        while (key < 50)
        {
            key++;
            if(vetor[key] == n)
            {
                return vetor[key];
            }
        }
        return -1;
    }
}


int main()
{
    int x,i,y,z;
    int *k = allocvetor(11);
    for(i = 0; i < 5; i++)
    {
        printf("Digite um valor a ser inserido: ");
        scanf("%i",&x);
        ihash1(x,k);
    }
    printf("\nDigite um valor para ser buscado:\n");
    scanf("%i",&x);
    y = bhash1(x,k);
    if (y == x)
    {
        printf("\nO elemento esta no vetor.\n");
    }
    else{
        z = bhash2(x,k);
        if(z > 0)
        {
            printf("\nO elemento esta no vetor.\n");
        }
        else
        {
            printf("\nO elemento nao esta no vetor.\n");
        }
    }

    printf("\n####Imprimir vetor inteiro####\n\n");
    for(i = 0; i < 20; i++)
    {
        printf("%i ",k[i]);
    }
    printf("\n");
    free(k);
    return 0;
}
