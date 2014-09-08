#include <stdio.h>

 int main(void)
 {
    int vetor[3];
    int i;
    void ordem(int v[], int n);
    printf("Digite 3 valores:\n");
    scanf("%i",&vetor[0]);
    scanf("%i",&vetor[1]);
    scanf("%i",&vetor[2]);

    ordem(vetor,3);
    printf("\n");
    for(i = 0; i < 3; i++)
    {
        printf("%i ", vetor[i]);
    }
    return 0;
 }

 void ordem(int v[], int n)
 {
     int i, j, temporaria;
     for(i=0; i < n; ++i)
     {
         for(j= i + 1; j < n; ++j)
         {
           if(v[i] > v[j])
           {
                temporaria = v[i];
                v[i] = v[j];
                v[j] = temporaria;
           }
         }
     }
}
