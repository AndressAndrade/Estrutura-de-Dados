#include <stdio.h>

int main()
{
    int intfrac(float num, int *inteiro, float *frac);
    float num,frac;
    int inteiro;
    printf("Digite um numero real:\n");
    scanf("%f",&num);
    intfrac(num,&inteiro,&frac);
    printf("\nA parte inteira eh:%i\n",inteiro);
    printf("A parte fracionada eh:%.2f",frac);
    return 0;
}

int intfrac(float num, int *inteiro, float *frac)
{
    *inteiro = (int)num;
    *frac = num - *inteiro;
}
