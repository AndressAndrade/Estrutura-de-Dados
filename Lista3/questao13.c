#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *vetor;
    vetor = malloc(1024); //alocando vetor de 1024kb

    free(vetor);

    int i;
    int **matriz;

    matriz = malloc(10*sizeof(int*));// 10 linhas
    for (i = 0; i < 10; i++)
    {
        matriz[i] = malloc(10*sizeof(int));//10 colunas, alocando matriz 10x10
    }
    free(matriz);

    typedef struct
    {
        char nomeproduto[30];
        int codigoproduto;
        float preco;
    }registro;

    registro *p;
    p = (registro*)malloc(50*sizeof(registro));//alocar registro

    free(p);

    //alocar texto

    
    char *texto = malloc(100 * 80 * sizeof(char));//alocar texto de ate 100 linhas e 80 caracteres
 
    free(texto);

    return 0;
}
