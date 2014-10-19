#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
     int i,k,x,c = 1;
     srand(time(NULL));
     printf("Qual numero de elementos deseja no vetor: ");
     scanf("%i",&k);
     int v[k];
     printf("Qual valor deseja procurar multiplo: ");
     scanf("%i",&x);
     printf("\n\nGerando %i valores aleatorios:\n\n",k);

     for (i = 0; i < k; i++)
     {
           v[i] = rand() % 100;
           printf("%i ", v[i]);
     }

     printf("\n\nProcurando multiplos...\n\n");
     for (i = 0; i < k; i++)
     {
           if(v[i] % x == 0)
           {
               printf("Temos o multiplo %i: %i\n",c,v[i]);
               c++;
           }
    }
    return 0;
}
