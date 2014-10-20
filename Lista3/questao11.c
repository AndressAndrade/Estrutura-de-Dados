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

    for(i = 0; i < linhas; i++)  //LOCALIZA TRES MAIORES
    {
        for(j = 0; j < colunas; j++)
        {
            if(matriz[i][j] >= pri)
            {
                var1 = a;
                var2 = b;
                a = i;
                b = j;
                c = var1;
                d = var2;
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

    printf("\nOs tres maiores elementos da matriz sao: \n%i na posicao[%d][%d]\n%i na posicao[%d][%d]\n%i na posicao[%d][%d]\n",pri,a+1,b+1,seg,c+1,d+1,ter,e+1,f+1);



    free(matriz);

}
