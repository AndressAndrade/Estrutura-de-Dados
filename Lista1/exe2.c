#include <stdio.h>

int main(void)
{
    int a,b;
    int maior(int x, int y);
    printf("Digite dois valores:\n");
    scanf("%i", &a);
    scanf("%i", &b);
    maior(a,b);
    return 0;
}

int maior(int x, int y)
{
    if(x >= y)
    {
        printf("O maior valor eh:%i e o menor valor eh:%i",x,y);
    }
    else
    {
        printf("O maior valor eh:%i e o menor valor eh:%i",y,x);
    }

}
