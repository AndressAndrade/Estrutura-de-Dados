#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int i;
  int count = 0;
  int z = 0;

  char *palavra;
  palavra = (char*)malloc(sizeof(char));

  fflush(stdin);
  printf("Digite uma palavra, em minusculo: ");
  gets(palavra);

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

  for(i = 0; i < count; i++)
  {
      printf("%c",palavra[i]);
  }
  printf("\n");
  free(palavra);
  return 0;
}
