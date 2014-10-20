#include <stdio.h>
#include <stdlib.h>

int main()
{
   int cidades,i,j;
   printf("Digite o numero de cidades: ");
   scanf("%i",&cidades);
   float matriz_distancias[cidades][cidades];

   for(i = 0; i < cidades; i++) //DEFINE DISTANCIAS
   {
       for(j = 0; j < cidades; j++)
       {
           if(i == j)
           {
               matriz_distancias[i][j] = 0;
           }
           else if(i > j)
           {
               matriz_distancias[i][j] = matriz_distancias[j][i];
           }
           else
           {
               printf("Distacia entre cidade %i e %i, em km: ",i+1,j+1);
               scanf("%f",&matriz_distancias[i][j]);
           }
       }
   }

   printf("\nMatriz de distancias: \n\n");

   for(i = 0; i < cidades; i++) //DEFINE DISTANCIAS
   {
       for(j = 0; j < cidades; j++)
       {
            printf("%.2f ", matriz_distancias[i][j]);
       }
       printf("\n");
   }

   printf("\nDigite o numero de duas cidades, separando por espaco: ");
   scanf("%i %i",&i,&j);
   printf("\nA distancia entre as cidades %i e %i eh: %.2f\n",i,j,matriz_distancias[i][j]);


   return 0;
}
