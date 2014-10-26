#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    char sobrenome[30];
    int matricula;
    int anonasc;

}alunos;

void preenche_registro(alunos *p,int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("\nNome do Aluno %d: ", i+1);
        gets(p->nome);

        printf("Sobrenome: ");
        gets(p->sobrenome);

        printf("Numero de Matricula: ");
        scanf("%i", &p->matricula);

        printf("Ano de Nascimento: ");
        scanf("%i", &p->anonasc);

        p=p+1;

    }
    p = p - n;
}

void exibe_registro(alunos *p,int n)
{
    int i;

    printf("\nExibindo Cadastros:\n");

    for(i = 0 ; i < n; i++)
    {
        printf("\nAluno %d\n", i+1);
        printf("Nome: %s\n",(p[i]).nome);
        printf("Sobrenome: %s\n", (p[i]).sobrenome);
        printf("Matricula: %i\n", (p[i]).matricula);
        printf("Ano de Nascimento: %i\n", (p[i]).anonasc);

    }
}

int main()
{
    int i,n;

    printf("Informe a quantidade de alunos:\n");
    scanf("%i",&n);

    alunos *p;
    p = (alunos*)malloc(n*sizeof(alunos));

    preenche_registro(p,n);
    exibe_registro(p,n);

    free(p);
    return 0;
}
