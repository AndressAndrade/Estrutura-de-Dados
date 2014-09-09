#include <stdio.h>

int main(void)
{
   void soma(int *pA, int *pB);
   int a,b;
   printf("Digite dois valores, separados por linha:\n");
   scanf("%i", &a);
   scanf("%i", &b);
   printf("Os dois numeros digitados foram: %i e %i\n",a,b);
   int *pA = &a;
   int *pB = &b;
   soma(pA,pB);
   printf("Agora a variavel A tem o valor da soma de A e B que eh: %i\n",a);
   return 0;

}

void soma(int *a, int *b)
{
    int soma;
    soma = *a + *b;
    *a = soma;
}
