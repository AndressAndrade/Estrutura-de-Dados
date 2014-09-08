#include <stdio.h>

float a,b;
float media_simples, media_ponderada;

int main(void)
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
    return a, b;
}

void calc_media(float a, float b)
{
    media_simples = (a + b) / 2;
    media_ponderada = (a + b*2) / 3;
    return media_simples, media_ponderada;
}

void exibe_dados(float a, float b)
{
    void le_notas(float a, float b);
    void calc_media(float a, float b);
    calc_media(a,b);
    le_notas(a,b);
    printf("\nAs notas sao: %.2f e %.2f\n",a,b);
    printf("As medias simples e ponderada, respectivamente, sao: %.2f e %.2f",media_simples, media_ponderada);
}
