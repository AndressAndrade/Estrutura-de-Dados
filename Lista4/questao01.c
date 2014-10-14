#include <stdio.h>
#include <stdlib.h>

typedef struct //estrutura de registro
{
    char NOME[40];
    float QTHORAS;
    float SALH;
    float SALTOTAL;
    char DEPTO[3];
    int MATRIC;


}funcionarios;

int main()
{
    int i,n,x;
    float maiorsal = 0;
    float soma = 0;
    printf("Digite o numero de registros entre 0 e 50:\n");
    scanf("%i", &n);
    printf("\n");

    funcionarios *p;
    p = (funcionarios*)malloc(50*sizeof(funcionarios)); //alocacao de memoria

    printf("Recebendo os dados do funcionario:\n\n");

    for(i = 0; i < n; i++) //recebe dados
    {
        fflush(stdin);
        printf("Digite o nome do funcionario: ");
        gets(p->NOME);
        printf("Digite a quantidade de horas: ");
        scanf("%f",&p->QTHORAS);
        printf("Digite o salario: ");
        scanf("%f",&p->SALH);
        if(p->SALH > maiorsal)
        {
            maiorsal = p->SALH;
            x = i;
        }
        fflush(stdin);
        printf("Digite o departamento: ");
        gets(p->DEPTO);
        printf("Digite oa matricula: ");
        scanf("%i",&p->MATRIC);
        if(p->MATRIC == 0) //será o fim do armazenamento, sai do loop
        {
            i = n;
        }
        else
        {
            soma += p->SALH;
            p++;
            printf("\n");

        }
    }

    p -= n;
    p->SALTOTAL = soma;

    printf("\nExibindo os dados de todos os funcionarios:\n\n");

    for(i = 0; i < n; i++)
    {
        printf("O nome do funcionario e: %s\n",p[i].NOME);
        printf("A quantidade de horas que trabalha e: %f\n",p[i].QTHORAS);
        printf("Seu salario e: %f\n",p[i].SALH);
        printf("Seu departamento e: %s\n",p[i].DEPTO);
        printf("Sua matricula e: %i\n\n",p[i].MATRIC);
    }

    printf("\nExibindo os dados do funcionario com maior salario e salario total:\n\n");

    printf("O nome do funcionario e: %s\n",p[x].NOME);
    printf("A quantidade de horas que trabalha e: %f\n",p[x].QTHORAS);
    printf("Seu salario e: %f\n",p[x].SALH);
    printf("Seu departamento e: %s\n",p[x].DEPTO);
    printf("Sua matricula e: %i\n",p[x].MATRIC);
    printf("O salario total e: %f\n\n",p->SALTOTAL);
    
    
    free(p);
    return 0;
}
