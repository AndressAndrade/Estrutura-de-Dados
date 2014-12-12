#include <stdio.h>
#include "process.c"

int main() {

        processes* prcs = processAlloc();//aloco processos

        process p;

        int i,n,x,y;

        printf("Digite a quantidade de processos:\n");
        scanf("%i", &n);
        printf("\n");
        for(i = 0; i < n; i++)
        {
            printf("Processo %d:\n",i+1);
            p.processId = i+1;
            fflush(stdin);
            printf("Digite o nome: ");
            gets(p.name);
            printf("Digite a idade: ");
            scanf("%i",&p.age);
            fflush(stdin);
            printf("Digite o endereco: ");
            gets(p.address);
            printf("Digite o telefone: ");
            scanf("%ld",&p.phone);
            fflush(stdin);
            printf("Digite a data: ");
            gets(p.date);
            printf("Digite o valor: ");
            scanf("%i",&p.value);
            printf("Digite o ID do Supermercado: ");
            scanf("%i",&p.supermarketId);
            processInsert(prcs, p);
            printf("\n");
        }

        x = processAmount(prcs);
        printf("O tamanho da pilha de processos e: %i",x);

        printf("\n\nExibindo dados do topo:\n");
        process mp = processTop(prcs);
        printf("Processo %d:\n", mp.processId);
        printf("O nome: %s\n",mp.name);
        printf("A idade: %i\n",mp.age);
        printf("O endereco: %s\n",mp.address);
        printf("O telefone: %ld\n",mp.phone);
        printf("A data: %s\n",mp.date);
        printf("O valor: %i\n",mp.value);
        printf("O ID do Supermercado: %i\n\n",mp.supermarketId);


        printf("\n\nExibindo dados do ID = 1:\n");
        process mx = processGetByID(prcs,1);
        printf("Processo %d:\n", mx.processId);
        printf("O nome: %s\n",mx.name);
        printf("A idade: %i\n",mx.age);
        printf("O endereco: %s\n",mx.address);
        printf("O telefone: %ld\n",mx.phone);
        printf("A data: %s\n",mx.date);
        printf("O valor: %i\n",mx.value);
        printf("O ID do Supermercado: %i\n\n",mx.supermarketId);

        printf("\n\nExibindo dados ordenados por valor:\n");
        processPrioritizeValue(prcs);

        int print_processo(process p) {
            printf("Processo %d:\n", p.processId);
            printf("O nome: %s\n",p.name);
            printf("A idade: %i\n",p.age);
            printf("O endereco: %s\n",p.address);
            printf("O telefone: %ld\n",p.phone);
            printf("A data: %s\n",p.date);
            printf("O valor: %i\n",p.value);
            printf("O ID do Supermercado: %i\n\n",p.supermarketId);

            return 1;
        }

        processEach(prcs, print_processo);

    return 0;
}

