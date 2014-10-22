#include <stdio.h>
#include <stdlib.h>

float **alocar_matriz(int cidades)
{
    float **matriz_distancias;

    int i;

    matriz_distancias = malloc(cidades*sizeof(float*));

    for(i = 0 ; i < cidades; i++)
    {
        matriz_distancias[i] = malloc(cidades*sizeof(float));
    }

    return matriz_distancias;

}

void preencher_matriz_distancias(float **matriz_distancias, int cidades) //DEFINE DISTANCIAS
{
    int i,j;

        for(i = 0; i < cidades; i++)
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
}

void exibe_matriz_distancias(float **matriz_distancias, int cidades)//EXIBE MATRIZ DISTANCIA
{
    int i,j;
    for(i = 0; i < cidades; i++)
   {
       for(j = 0; j < cidades; j++)
       {
            printf("%.2f ", matriz_distancias[i][j]);
       }
       printf("\n");
   }
}

void distancia_entreduas(float **matriz_distancias, int x, int y)//DISTANCIA ENTRE DUAS
{
    printf("\nA distancia entre as cidades %i e %i eh: %.2f\n",x,y,matriz_distancias[x-1][y-1]);
}

int main()
{
   int cidades,a,b;
   float **matriz_distancias;
   printf("Digite o numero de cidades: ");
   scanf("%i",&cidades);
   matriz_distancias = alocar_matriz(cidades);

   printf("\nPreencha a matriz:\n\n");
   preencher_matriz_distancias(matriz_distancias,cidades);

   printf("\nMatriz de distancias: \n\n");
   exibe_matriz_distancias(matriz_distancias,cidades);


   printf("\nDigite o numero de duas cidades, separando por espaco: ");
   scanf("%i %i",&a,&b);
   distancia_entreduas(matriz_distancias,a,b);

   free(matriz_distancias);
   return 0;
}
