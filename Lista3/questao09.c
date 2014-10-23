#include <stdio.h>
#include <stdlib.h>

float **alocar_matriz(int linhas, int colunas)// ALOCA MATRIZ
{
    float **matriz;

    int i;

    matriz = malloc(linhas*sizeof(float*));

    for(i = 0 ; i < linhas; i++)
    {
        matriz[i] = malloc(colunas*sizeof(float));
    }

    return matriz;

}

void preencher_matriz(float**matriz, int linhas, int colunas)//PREENCHE MATRIZ
{
    int i,j;

        for(i = 0; i < linhas; i++)
        {
            for(j = 0; j < colunas; j++)
            {
                  printf("Digite a matriz[%i][%i]: ",i+1,j+1);
                  scanf("%f", &matriz[i][j]);
            }
        }
    printf("\n");
}

void matriz_org(float **matriz, int linhas, int colunas)//DEVOLVE MATRIZ NO LAYOUT APROPRIADO
{
    int i,j;

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            printf("%.2f ",matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    float **matriz;
    int linhas,colunas;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%i",&linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%i",&colunas);
    printf("\n");

    matriz = alocar_matriz(linhas,colunas);
    preencher_matriz(matriz,linhas,colunas);


    printf("\nMatriz Organizada:\n\n");

    matriz_org(matriz,linhas,colunas);

    free(matriz);
    return 0;
}
