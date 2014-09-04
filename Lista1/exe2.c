#include <stdio.h>

int main()
{
   int a,b;
   printf("Digite um valor:\n");
   scanf("%i",&a);
   printf("Digite um valor:\n");
   scanf("%i",&b);

   if(a > b)
        printf("O maior valor e menor valor,respectivamente,são:%i e %i",a,b);
   else
        printf("O maior valor e menor valor,respectivamente,são:%i e %i",b,a);
  return 0;

}
