#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alocar_palavara()
{
    char *p;
    p = (char*)malloc(100); //alocando dinamicamente char com 100 bytes
    return p;
}

void numero_vogais(char *p)
{
    int controle = 1; //controle para a palavra fim

    while(controle != 0)
    {
        printf("Digite uma palavra de ate 100 caracteres, sem acento: ");
        gets(p);
        controle = strcmp(p,"fim"); //Se p for igual a 'fim', controle = 0,executa o programa para a palavra fim e termina execucao
        int a = 0,e = 0,i = 0,o = 0,u = 0,x = 0; //A cada ciclo de palavra devemos zerar os contadores
        while(p[x] != '\0')// Enquantos nao chegamos ao caractere nulo, continua
        {
            if(p[x] == 'a')
            {
                a++;
            }
            else if(p[x] == 'e')
            {
                e++;
            }
            else if(p[x] == 'i')
            {
                i++;
            }
            else if(p[x] == 'o')
            {
                o++;
            }
            else if(p[x] == 'u')
            {
                u++;
            }
            x++;

      }
      printf("\nA palavra tem %i A(s)\n",a);
      printf("A palavra tem %i E(s)\n",e);
      printf("A palavra tem %i I(s)\n",i);
      printf("A palavra tem %i O(s)\n",o);
      printf("A palavra tem %i U(s)\n\n",u);

    }
}

int main()
{
    char *p;
    p = alocar_palavara();

    numero_vogais(p);

    free(p);
    return 0;
}
