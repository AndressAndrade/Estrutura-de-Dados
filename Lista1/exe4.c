#include <stdio.h>

float a,b;
float media_simples, media_ponderada;
int c;

int main()
{
   void exibe_dados(float a, float b);
   printf("Digite duas notas:\n");
   scanf("%f", &a);
   scanf("%f", &b);
   exibe_dados(a,b);
   return 0;

}

void le_notas(float a, float b)
{
   if(a < 0 ||  b < 0)
    {
        printf("Digite valores positivo\n");
        c = 0;
    }
    else if(a > 10 || b > 10 )
    {
        printf("Digite valores menores que dez\n");
        c = 0;
    }
    else
    {
        printf("\nAs notas sao: %.2f e %.2f\n",a,b);
        c = 1;
    };
}

void calc_media(float a, float b)
{
    if(c == 1)
    {
        media_simples = (a + b) / 2;
        media_ponderada = (a + b*2) / 3;
        return media_simples, media_ponderada;
    }
    else
    {
        printf("Nao foi possivel calcular as medias\n");
    }
}

void exibe_dados(float a, float b)
{
    void le_notas(float a, float b);
    void calc_media(float a, float b);
    le_notas(a,b);
    calc_media(a,b);
    printf("As medias simples e ponderada, respectivamente, sao: %.2f e %.2f",media_simples, media_ponderada);
}
