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

void local_pos(int **matriz, int linhas, int colunas)
{
    int pri=0,seg=0,ter=0,tem1 = 0,tem2 = 0,var1 = 0,var2 = 0,var3 = 0,var4 = 0;
    int a,b,c,d,e,f;
    int i,j;

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            if(matriz[i][j] >= pri)
            {
                var1 = a;
                var2 = b;
                var3 = c;
                var4 = d;
                a = i;
                b = j;
                c = var1;
                d = var2;
                e = var3;
                f = var4;
                tem1 = pri;
                tem2 = seg;
                pri = matriz[i][j];
                seg = tem1;
                ter = tem2;

            }
            else if(matriz[i][j] >= seg)
            {
                var3 = c;
                var4 = d;
                c = i;
                d = j;
                e = var3;
                f = var4;
                tem1 = seg;
                seg = matriz[i][j];
                ter = tem1;
            }
            else if(matriz[i][j] >= ter)
            {
                e = i;
                f = j;
                ter = matriz[i][j];
            }
        }
    }

    printf("\nOs tres maiores elementos da matriz sao: \n\n%i na posicao[%d][%d]\n%i na posicao[%d][%d]\n%i na posicao[%d][%d]\n",pri,a+1,b+1,seg,c+1,d+1,ter,e+1,f+1);
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

    local_pos(matrix,linhas,colunas);//LOCALIZA 3 MAIORES E SUAS POSICOES

    free(matrix);
}

