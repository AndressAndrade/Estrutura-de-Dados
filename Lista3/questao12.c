#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int i,j,linhas,colunas;
    int pri=0,seg=0,ter=0,tem1 = 0,tem2 = 0,var1 = 0,var2 = 0,var3 = 0,var4 = 0;
    int a,b,c,d,e,f;
    srand(time(NULL));

    printf("Digite o numero de linhas da matriz: ");
    scanf("%i",&linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%i",&colunas);
    printf("\n");

    int **matriz = (int**)malloc(linhas*sizeof(int*)); //ALOCA MATRIZ

    for (i = 0; i < linhas; i++)
    {
       matriz[i] = (int*) malloc(colunas*sizeof(int));
       for (j = 0; j < colunas; j++)
       {
            matriz[i][j] = 0;
       }
    }

    for(i = 0; i < linhas; i++)  //PREENCHE MATRIZ
    {
        for(j = 0; j < colunas; j++)
        {
            matriz[i][j] = rand() % 100;
        }
    }

    printf("\nMatriz:\n\n");

    for(i = 0; i < linhas; i++)  //LE MATRIZ
    {
        for(j = 0; j < colunas; j++)
        {
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz Transposta:\n\n");

    for(j = 0; j < colunas; j++)  //LE MATRIZ TRANSPOSTA
    {
        for(i = 0; i < linhas; i++)
        {
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }


    free(matriz);

}
