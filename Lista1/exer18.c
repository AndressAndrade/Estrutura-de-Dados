#include <stdio.h>

int main()
{
    float mtrx[3][3] = {{1.5,2.5,3.5},{1.6,2.6,3.6},{1.7,2.7,3.7}};
    int i,j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("O endereco da matriz[%i][%i] eh: %i \n",i+1,j+1,&mtrx[i][j]);
            //foi adicionado 1 ao valor de i e j por questao de conceito, pois consideramos o primeiro
            //elemento da matriz como 11 e nao como 00.
        }
    }
}
