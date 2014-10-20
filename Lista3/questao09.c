#include <stdio.h>
#include <stdlib.h>


int main()
{
    float **matriz;
    int i,j,linhas,colunas;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%i",&linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%i",&colunas);
    printf("\n");

    matriz = malloc(colunas*sizeof(float*)); //ALOCA MATRIZ

    for(i = 0; i < linhas; i++)
    {
        matriz[i] = malloc(linhas*sizeof(float));
    }

    for(i = 0; i < linhas; i++)  //PREENCHE MATRIZ
    {
        for(j = 0; j < colunas; j++)
        {
            printf("Digite a matriz[%i][%i]: ",i+1,j+1);
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("\nMatriz Organizada:\n\n");

    for(i = 0; i < linhas; i++)  //DEVOLVE MATRIZ COM LAYOUT APROPRIADO
    {
        for(j = 0; j < colunas; j++)
        {
            printf("%.2f ",matriz[i][j]);
        }
        printf("\n");
    }


    free(matriz);
    return 0;

}
