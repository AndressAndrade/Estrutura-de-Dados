#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p,i,j,k;
    int *m;
    int matriz[2][2];
    p = malloc(5*sizeof(int));

    for(k = 0; k < 5; k++)
    {
        int soma = 0;
        printf("Preencha a matriz de inteiros %i:\n",k+1);
        for(i = 0; i < 2;i++)
        {
            for(j = 0;j < 2;j++)
            {
                 printf("Matriz[%i][%i]: ",i+1,j+1);
                 scanf("%i",m);
                 soma += *m;

            }
        }
        *p = soma;
        p++;

        printf("\n");

    }
    p -= 5;


    for(i = 0;i < 5;i++)// teste
    {
        printf("%i ",*p);
        p++;
    }


    free(p);
    return 0;
}
