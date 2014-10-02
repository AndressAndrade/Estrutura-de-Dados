#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verificar(char *a, char *b)
{
    int x = 0;
    int y = 0;
    for(x ; x < 8; x++)
    {
        for(y ; y < 19; y++)
        {
            if(*b != *a)
                y += 1;


        }
        x += 1;
    }
    
    if(x == 7)
        printf("A string 1 ocorre em 2\n");
    else
        printf("A string 1 nao ocorre em 2\n");

}

int main()
{
    char v1[] = "Andressa";
    char v2[] = "Bem-Vinda, Andressa";
    char *x = v1;
    char *y = v2;
    verificar(*x,*y);
    return 0;

}
