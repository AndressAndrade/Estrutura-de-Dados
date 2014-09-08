#include <stdio.h>

int main()
{
    int a,b;
    int troca(int a, int b);
    printf("Digite dois valores:\n");
    scanf("%i", &a);
    scanf("%i", &b);
    printf("Antes 'a' eh:%i e 'b' eh:%i\n",a,b);
    troca(a,b);
    return 0;

}

int troca(int x, int y)
{
    int temporaria;
    temporaria = x;
    x = y;
    y = temporaria;
    printf("Agora 'a' eh:%i e 'b' eh:%i\n",x,y);

}
