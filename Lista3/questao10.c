#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *alocar_vetor(int x)
{
    int *vetor;

    vetor = malloc(x*sizeof(int)) ;

    return vetor;

}

void preenchexibe_vetor(int *vetor, int x)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < x; i++)
    {
        vetor[i] = rand() % 100;
        printf("%i ", vetor[i]);
    }
    printf("\n");
}

void multiplo_elemento(int *vetor, int a,int b)
{
    int i,c = 1;
    printf("\n\nProcurando multiplos...\n\n");
    for(i = 0; i < a; i++)
    {
           if(vetor[i] % b == 0)
           {
               printf("Temos o multiplo %i: %i\n",c,vetor[i]);
               c++;
           }
    }

}


int main()
{
     int k,x;
     int *vector;

     printf("Qual numero de elementos deseja no vetor: ");
     scanf("%i",&k);
     vector = alocar_vetor(k);

     printf("\nGerando %i valores aleatorios:\n\n",k);
     preenchexibe_vetor(vector, k);


     printf("\nQual valor deseja procurar multiplo: ");
     scanf("%i",&x);
     multiplo_elemento(vector, k,x);

    free(vector);
    return 0;
}
