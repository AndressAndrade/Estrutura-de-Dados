#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int RGM;
    char CURSO[30];
    int SEMESTRE;
    int ANOINICIO;
}ADM,ENG,MED;

int main()
{
    ADM *a;
    ENG *e;
    MED *m;
    int i,n;

    a = (ADM*)malloc(40*sizeof(ADM));
    e = (ENG*)malloc(40*sizeof(ENG));
    m = (MED*)malloc(40*sizeof(MED));

    printf("Digite a quantidade de dados de Administracao:\n");
    scanf("%i", &n);
    printf("\n");
    for(i = 0; i < n; i++)
    {
        printf("Aluno Administracao %d:\n",i+1);
        printf("Digite o RGM: ");
        scanf("%i",&a->RGM);
        fflush(stdin);
        printf("Digite o curso: ");
        gets(a->CURSO);
        printf("Digite o semestre: ");
        scanf("%i",&a->SEMESTRE);
        printf("Digite o ano de inicio: ");
        scanf("%i",&a->ANOINICIO);
        a++;
        printf("\n");
    }

    printf("\nDigite a quantidade de dados de Engenharia:\n");
    scanf("%i", &n);
    printf("\n");
    for(i = 0; i < n; i++)
    {
        printf("Aluno Engenharia %d:\n",i+1);
        printf("Digite o RGM: ");
        scanf("%i",&e->RGM);
        fflush(stdin);
        printf("Digite o curso: ");
        gets(e->CURSO);
        printf("Digite o semestre: ");
        scanf("%i",&e->SEMESTRE);
        printf("Digite o ano de inicio: ");
        scanf("%i",&e->ANOINICIO);
        e++;
        printf("\n");
    }

    printf("\nDigite a quantidade de dados de Medicina:\n");
    scanf("%i", &n);
    printf("\n");
    for(i = 0; i < n; i++)
    {
        printf("Aluno Medicina %d:\n",i+1);
        printf("Digite o RGM: ");
        scanf("%i",&m->RGM);
        fflush(stdin);
        printf("Digite o curso: ");
        gets(m->CURSO);
        printf("Digite o semestre: ");
        scanf("%i",&m->SEMESTRE);
        printf("Digite o ano de inicio: ");
        scanf("%i",&m->ANOINICIO);
        m++;
        printf("\n");
    }

    free(a);
    free(e);
    free(m);
    return 0;
}
