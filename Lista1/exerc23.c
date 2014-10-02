#include <stdio.h>
int main()
{
    int v[5] = {5,6,7,8,32};
    int *ptr;
    imprimir(v, &ptr);
    return 0;

}

int imprimir(int vetor[], int *ptr)
{
       for(ptr = vetor; ptr < vetor + 5; ptr++)
    {
        printf("%i ",*ptr);
    }
}
