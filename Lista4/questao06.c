#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *p,matriz[6][6];
    int i,j;
    p = malloc(36*sizeof(float));
    float somalinha = 0;

    printf("Preencha a matriz de 6x6:\n");
    for(i = 0; i < 6;i++)
    {
        for(j = 0;j < 6;j++)
        {
            printf("Matriz[%i][%i]: ",i+1,j+1);
            scanf("%f",p);
            matriz[i][j] = *p;
            p++;
        }
    }
    printf("\n");

    p = p - 36;

    for(i = 0; i < 6;i++)
    {
        for(j = 0;j < 6;j++)
        {
            somalinha += matriz[i][j];
        }
        printf("Soma linha %i: %.2f\n",i+1,somalinha);
        somalinha = 0;
    }

    free(p);
    return 0;
}
