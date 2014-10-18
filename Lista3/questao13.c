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
    p = (registro*)malloc(sizeof(registro));//alocar registro

    free(p);

    //alocar texto
    int linhas;
    printf("Quantas linhas de 1 a 100: "); //até 100 linhas
    scanf("%i",&linhas);
    texto = (char**)malloc(linhas*sizeof(char));
    for(i=0;i<linhas;i++){
        texto[i]=(char*)malloc(80*sizeof(char));//até 80 caracteres
 
    free(texto);

    return 0;
}
