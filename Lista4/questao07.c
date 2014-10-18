#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *FILIAL;
    int QTDEFUNC;
    float FATURTOT;
}registro;

int main()
{
    registro *r;
    r =(registro*)malloc(3*sizeof(registro));

    float aux1,percapita[3];
    char *aux2;

    int i,j;

    r->FILIAL = "SP1";
    printf("Qual a quantidade de funcionarios de SP,entre 0 e 20: ");
    scanf("%i",&r->QTDEFUNC);
    printf("Qual o faturamento total de SP:");
    scanf("%f",&r->FATURTOT);
    percapita[0] = r->FATURTOT/r->QTDEFUNC;
    r++;
    printf("\n");

    r->FILIAL = "RJ1";
    printf("Qual a quantidade de funcionarios de RJ,entre 0 e 20: ");
    scanf("%i",&r->QTDEFUNC);
    printf("Qual o faturamento total de RJ: ");
    scanf("%f",&r->FATURTOT);
    percapita[1] = r->FATURTOT/r->QTDEFUNC;
    r++;
    printf("\n");

    r->FILIAL = "BH1";
    printf("Qual a quantidade de funcionarios de BH, entre 0 e 20: ");
    scanf("%i",&r->QTDEFUNC);
    printf("Qual o faturamento total de BH: ");
    scanf("%f",&r->FATURTOT);
    percapita[2] = r->FATURTOT/r->QTDEFUNC;
    r++;
    printf("\n");

    r -= 3;


    for(i = 0; i < 3; i++)
    {
        for(j = i+ 1; j < 3;j++)
        {
            if(percapita[i] > percapita[j])
            {
                aux1 = percapita[i];
                percapita[i] = percapita[j];
                percapita[j] = aux1;
                aux2 = r[i].FILIAL;
                r[i].FILIAL = r[j].FILIAL;
                r[j].FILIAL = aux2;
            }
        }

    }

    for(i = 0; i < 3; i++)
    {
        printf("A renda per capita de %s eh: %.2f\n",r[i].FILIAL,percapita[i]);
    }


    free(r);
    return 0;

}
