#include <stdio.h>
#include <stdlib.h>

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
    int **matriz,i,j,x,linhas,colunas;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%i",&linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%i",&colunas);
    printf("\n");

    matriz = malloc(colunas*sizeof(int*));

    for(i = 0; i < linhas; i++)
    {
        matriz[i] = malloc(linhas*sizeof(int));
    }

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            printf("Digite a matriz[%i][%i]: ",i+1,j+1);
            scanf("%i", &matriz[i][j]);
        }
    }
    printf("\nDigite um valor: ");
    scanf("%i",&x);

    encontra_valor(matriz, linhas, colunas, x);

    free(matriz);

}
