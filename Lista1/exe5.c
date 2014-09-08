#include <stdio.h>

int a,b;

int main(void)
{
   void soma(int a, int b);
   printf("Digite dois valores:\n");
   scanf("%i", &a);
   scanf("%i", &b);
   printf("Os dois numeros digitados foram: %i e %i\n",a,b);
   soma(a,b);
   return 0;

}

void soma(int a, int b)
{
    int soma;
    soma = a + b;
    a = soma;
    printf("Agora a variavel A tem o valor da soma de A e B: %i e %i\n",a,b);
}
