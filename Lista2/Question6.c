//6) Escreva uma função chamada troca que troca os valores dos parâmetros
//recebidos. Sua assinatura deve ser:
//void troca(float *a, float *b);

#include <stdio.h>

void troca(float *a, float *b)
{

    float temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
