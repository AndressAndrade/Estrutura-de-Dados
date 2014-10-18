#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *FILIAL;
    int QTDEFUNC;
    float FATURTOT;
    float PERCAPITA;
}registro;

int main()
{
    registro *r;
    r =(registro*)malloc(3*sizeof(registro));

    float aux1;
    char *aux2;
    int i,j;

    r->FILIAL = "SP1";
    printf("Qual a quantidade de funcionarios de SP: ");
    scanf("%i",&r->QTDEFUNC);
    printf("Qual o faturamento total de SP:");
    scanf("%f",&r->FATURTOT);
    r->PERCAPITA = r->FATURTOT/r->QTDEFUNC;
    r++;
    printf("\n");

    r->FILIAL = "RJ1";
    printf("Qual a quantidade de funcionarios de RJ: ");
    scanf("%i",&r->QTDEFUNC);
    printf("Qual o faturamento total de RJ: ");
    scanf("%f",&r->FATURTOT);
    r->PERCAPITA = r->FATURTOT/r->QTDEFUNC;
    r++;
    printf("\n");

    r->FILIAL = "BH1";
    printf("Qual a quantidade de funcionarios de BH: ");
    scanf("%i",&r->QTDEFUNC);
    printf("Qual o faturamento total de BH: ");
    scanf("%f",&r->FATURTOT);
    r->PERCAPITA = r->FATURTOT/r->QTDEFUNC;
    r++;
    printf("\n");

    r -= 3;


    for(i = 0; i < 3; i++)
    {
        for(j = i+ 1; j < 3;j++)
        {
            if(r[i].PERCAPITA > r[j].PERCAPITA)
            {
                aux1 = r[i].PERCAPITA;
                r[i].PERCAPITA = r[j].PERCAPITA;
                r[j].PERCAPITA = aux1;
                aux2 = r[i].FILIAL;
                r[i].FILIAL = r[j].FILIAL;
                r[j].FILIAL = aux2;
            }
        }

    }

    for(i = 0; i < 3; i++)
    {
        printf("A renda percapita de %s eh: %.2f\n",r[i].FILIAL,r[i].PERCAPITA);
    }


    free(r);
    return 0;

}
