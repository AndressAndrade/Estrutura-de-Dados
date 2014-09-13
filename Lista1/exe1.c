#include <stdio.h>
int main()
{
int a,b;
int troca(int *x, int *y);
printf("Digite dois valores, separados por linha:\n");
scanf("%i", &a);
scanf("%i", &b);
printf("Antes 'a' eh:%i e 'b' eh:%i\n",a,b);
troca(&a,&b);
printf("Agora 'a' eh:%i e 'b' eh:%i\n",a,b);
return 0;
}

int troca(int *x, int *y)
{
int temporaria = *x;
*x = *y;
*y = temporaria;
}
