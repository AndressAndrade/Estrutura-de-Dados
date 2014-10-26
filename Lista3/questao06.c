#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alocar_palavra(palavra)
{
    palavra = (char*)malloc(sizeof(char));

    return palavra;
}

int remove_vogal(char *palavra)
{
    int i;
    int count = 0;
    int z = 0;

    while(palavra[z] != '\0')
    {
    if(palavra[z] == 'a')
    {
      palavra[z] = ' ';
      count++;
      z++;
    }
    else if(palavra[z] == 'e')
    {
        palavra[z] = ' ';
        count++;
        z++;
    }
    else if(palavra[z] == 'i')
    {
        palavra[z] = ' ';
        count++;
        z++;
    }
    else if(palavra[z] == 'o')
    {
        palavra[z] = ' ';
        count++;
        z++;
    }
    else if(palavra[z] == 'u')
    {
        palavra[z] = ' ';
        count++;
        z++;
    }
    else
    {
        count++;
        z++;
    }
  }
  return count;
}

void imprime_semvogal(char *palavra)
{
    int i,k;
    k = remove_vogal(palavra);
    for(i = 0; i < k; i++)
    {
      printf("%c",palavra[i]);
    }
    printf("\n");
}


int main()
{

  char *palavra;
  palavra = alocar_palavra(palavra);

  fflush(stdin);
  printf("Digite uma palavra, em minusculo: ");
  gets(palavra);

  imprime_semvogal(palavra);

  free(palavra);
  return 0;
}
