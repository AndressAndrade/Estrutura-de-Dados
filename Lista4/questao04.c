#include <stdio.h>
#include <stdlib.h>

int *alocar_espaco()
{
    int *p;

    p = malloc(40*sizeof(int));

    return;
}

void preenche_matriz(int *p)
{
    int k,i,j;
    int matriz[2][4];
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
}

void test(int *p)
{
    int i;
    for(i = 0;i < 40;i++)// teste
    {
        printf("%i ",*p);
        p++;
    }

}
int main()
{
    int *p;
    p = alocar_espaco();

    preenche_matriz(p);

    test(p);

    free(p);
    return 0;
}
