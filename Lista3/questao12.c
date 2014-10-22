#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **alocar_matriz(int linhas, int colunas)
{
    int **matriz;

    int i;

    matriz = malloc(linhas*sizeof(int*));

    for(i = 0 ; i < linhas; i++)
    {
        matriz[i] = malloc(colunas*sizeof(int));
    }

    return matriz;

}

void preencher_matriz(int **matriz, int linhas, int colunas)
{
    int i,j;
    srand(time(NULL));

        for(i = 0; i < linhas; i++)
        {
            for(j = 0; j < colunas; j++)
            {
                 matriz[i][j] = rand() % 100;
            }
        }
    printf("\n");
}

void ler_matriz(int **matriz, int linhas, int colunas)
{
    int i,j;

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }


}

void transposta(int **matriz, int linhas, int colunas)
{
        int i,j;
        for(j = 0; j < colunas; j++)
        {
            for(i = 0; i < linhas; i++)
            {
                printf("%i ",matriz[i][j]);
            }
            printf("\n");
        }
}


int main()
{
    int linhas,colunas;
    int **matrix;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%i",&linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%i",&colunas);
    printf("\n");

    matrix = alocar_matriz(linhas,colunas);//ALOCA MATRIZ

    printf("\nMatriz:\n\n");
    preencher_matriz(matrix,linhas,colunas);//PREENCHE MATRIZ
    ler_matriz(matrix,linhas,colunas);//LE MATRIZ

    printf("\nMatriz Transposta:\n\n");
    transposta(matrix,linhas,colunas);//MATRIZ TRANSPOSTA

    free(matrix);
}
