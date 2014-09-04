#include <stdio.h>

int main()
{
    float nota1;
    float nota2;
    float media;
    float media_ponderada;

    printf("Digite a nota 1:\n");
    scanf("%f", &nota1);
    printf("Digite a nota 2:\n");
    scanf("%f", &nota2);

    printf("As notas digitadas foram %.2f e %.2f\n", nota1, nota2);

    media = (nota1 + nota2) / 2;
    media_ponderada = (nota1 + (2*nota2))/3;

    printf("As medias simples e ponderada, respectivamente, são:%.2f e %.2f", media,  media_ponderada);

}
