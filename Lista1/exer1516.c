#include <stdio.h>

int main(void)
{
    int a,b;
    printf("Digite duas variaveis,separadas por linha:\n");
    scanf("%i\n%i",&a,&b);
    if(&a > &b)
    {
        printf("O endereco do maior elemento eh:%p",&a);
    }
    else
    {
        printf("O endereco do maior elemento eh:%p",&b);
    }
    return 0;
}
