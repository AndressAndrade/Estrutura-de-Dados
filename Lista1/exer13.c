#include <stdio.h>

int main(void)
{
    int x;
    float y;
    char z;
    x = 5;
    y = 3.14;
    z = 'A';
    int *pX = &x;
    float *pY = &y;
    char *pZ = &z;
    printf("Antes das modificacoes:%i,%.2f,%c\n",x,y,z);
    *pX = 7;
    *pY = 2.41;
    *pZ = 'Z';
    printf("Depois das modificacoes:%i,%.2f,%c\n",x,y,z);
    return 0;
}
