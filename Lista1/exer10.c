#include <stdio.h>

int soma;

int main(void)
{
   void dobro(int *pA, int *pB);
   int a,b;
   printf("Digite dois valores, separados por linha:\n");
   scanf("%i", &a);
   scanf("%i", &b);
   printf("Os dois numeros digitados foram: %i e %i\n",a,b);
   int *pA = &a;
   int *pB = &b;
   dobro(pA,pB);
   printf("Agora as variaveis A e B tem o dobro do valor: %i e %i\n",a,b);
   printf("A soma destes dois valores eh: %i\n",soma);
   return 0;

}

void dobro(int *a, int *b)
{
    *a = *a * 2;
    *b = *b * 2;
    soma = *a + *b;
    return soma;
}
