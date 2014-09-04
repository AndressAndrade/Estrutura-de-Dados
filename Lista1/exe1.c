#include <stdio.h>

int main()
{
    int a, b;
    printf("Digite o valor a:\n");
    scanf("%i", &a);
    printf("DIgite o valor b:\n");
    scanf("%i", &b);
    printf("Os valores de a e b são: %i e %i \n",a,b);
    int x,y;
    x = a;
    y = b;
    a = y;
    b = x;
    printf("Os valores de a e b, atualizados, são: %i e %i ",a,b);

    return 0;

}
