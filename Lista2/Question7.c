#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palavra1[20] = "Andressa";
    char palavra2[20];
    strcpy(palavra2, palavra1);
    printf("strcpy(palavra1, palavra2) :  %s\n", palavra2 );
    return 0;

}
