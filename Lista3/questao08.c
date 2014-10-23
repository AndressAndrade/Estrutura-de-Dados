#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **alocar_matriz(int linhas, int colunas)// ALOCA MATRIZ
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

void preencher_matriz(int**matriz, int linhas, int colunas)//PREENCHE E EXIBE MATRIZ
{
    int i,j;
    srand(time(NULL));

        for(i = 0; i < linhas; i++)
        {
            for(j = 0; j < colunas; j++)
            {
                matriz[i][j] = rand() % 100;
                printf("%i ",matriz[i][j]);

            }
            printf("\n");
        }
    printf("\n");
}


int encontra_valor(int **matriz, int linhas,int colunas, int x)
{
    int i,j,teste = 0;

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            if(matriz[i][j] == x)
            {
                teste = 1;
                break;
            }
        }
    }
    if(teste == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}


int main()
{
    int **matriz,x,y,linhas,colunas;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%i",&linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%i",&colunas);
    printf("\n");

    matriz =  alocar_matriz(linhas,colunas);
    preencher_matriz(matriz,linhas,colunas);

    printf("\nDigite um valor: ");
    scanf("%i",&x);

    y = encontra_valor(matriz, linhas, colunas, x);

    return y;

    free(matriz);
}
