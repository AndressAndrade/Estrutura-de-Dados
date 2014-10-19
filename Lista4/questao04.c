#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p,i,j,k;
    int matriz[2][4];
    p = malloc(40*sizeof(int));

    for(k = 0; k < 5; k++)
    {
        printf("Preencha a matriz de inteiros %i:\n",k+1);
        for(i = 0; i < 2;i++)
        {
            for(j = 0;j < 4;j++)
            {
                 printf("Matriz[%i][%i]: ",i+1,j+1);
                 scanf("%i",&matriz[i][j]);
                 *p = matriz[i][j];
                 p++;
            }
        }
        printf("\n");

    }
    p -= 40;


    for(i = 0;i < 40;i++)// teste
    {
        printf("%i ",*p);
        p++;
    }


    free(p);
    return 0;
}
