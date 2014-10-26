#include <stdio.h>
#include <stdlib.h>

float *alocar_espaco()
{
    float *p;

    p = malloc(36*sizeof(float));

    return p;
}

void preenche_exibe(float *p)
{
    float matriz[6][6];
    float somalinha = 0;
    int i,j;
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

    for(i = 0; i < 6;i++)//EXIBE SOMA DE CADA LINHA
    {
        for(j = 0;j < 6;j++)
        {
            somalinha += matriz[i][j];
        }
        printf("Soma linha %i: %.2f\n",i+1,somalinha);
        somalinha = 0;
    }
}

int main()
{
    float *p;
    p = alocar_espaco();

    preenche_exibe(p);

    free(p);
    return 0;
}
