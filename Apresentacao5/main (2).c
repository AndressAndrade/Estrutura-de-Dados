#include <stdio.h>
#include "process.c"


void showMenuInsert(processes* prcs) {
    int submenuOption;
    printf("\nDigite 1 para inserir outro processo, 2 para voltar para o menu principal ou 0 para fechar o programa!");
    scanf("%i", &submenuOption);
    switch(submenuOption) {
        case 1:
            insertProcess(prcs);
        break;
        case 2:
            showMenu(prcs);
        break;
        case 0:
            exit(1);
        break;
        default:
            printf("\nOpcao invalida!");
            showMenuInsert(prcs);
        break;
    }
}

void insertProcess(processes* prcs) {
    process p;
    int processID, submenuOption;

    printf("Ok, você escolheu: inserir processo! Preciso que voce me informe o seguinte:\n");
    printf("Digite o nome: \n");
    //gets(p.name);
    scanf("%s", &p.name);
    printf("\nDigite a idade: ");
    scanf("%i", &p.age);
    //fflush(stdin);
    printf("\nDigite o endereco: ");
    //gets(p.address);
    scanf("%s", &p.address);
    printf("\nDigite o telefone: ");
    scanf("%ld",&p.phone);
    //fflush(stdin);
    printf("\nDigite a data: ");
    scanf("%s", &p.date);
    //gets(p.date);
    printf("\nDigite o valor: ");
    scanf("%i", &p.value);
    printf("\nDigite o ID do Supermercado: ");
    scanf("%i", &p.supermarketId);

    processID = processInsert(prcs, p);
    printf("\nO processo foi adicionado com o ID %i", processID);

    showMenuInsert(prcs);
}

void loadTestProcess(processes* prcs) {
    process addingProcess1, addingProcess2, addingProcess3, addingProcess4;

    // Elemento de teste 1
    strcpy(addingProcess1.name, "Bruce Wayne");
    addingProcess1.age = 38;
    strcpy(addingProcess1.address, "Batcaverna");
    addingProcess1.phone = 93456969;
    addingProcess1.value = 17890;
    strcpy(addingProcess1.date, "17/08/2014");
    addingProcess1.supermarketId = 1;
    processInsert(prcs, addingProcess1);

    // Elemento de teste 2
    strcpy(addingProcess2.name, "Guilherme Sehn");
    addingProcess2.age = 25;
    strcpy(addingProcess2.address, "Santa Cruz do Sul, RS");
    addingProcess2.phone = 93456760;
    addingProcess2.value = 7000;
    strcpy(addingProcess2.date, "15/11/1997");
    addingProcess2.supermarketId = 1;
    processInsert(prcs, addingProcess2);

    // Elemento de teste 3
    strcpy(addingProcess3.name, "Ravena Titã");
    addingProcess3.age = 18;
    strcpy(addingProcess3.address, "Templo de Azarath");
    addingProcess3.phone = 93334576;
    addingProcess3.value = 1000;
    strcpy(addingProcess3.date, "13/02/2000");
    addingProcess3.supermarketId = 1;
    processInsert(prcs, addingProcess3);

    // Elemento de teste 4
    strcpy(addingProcess4.name, "Cersei Lannister");
    addingProcess4.age = 31;
    strcpy(addingProcess4.address, "Rochedo Casterly");
    addingProcess4.phone = 93499789;
    addingProcess4.value = 5000;
    strcpy(addingProcess4.date, "21/03/1984");
    addingProcess4.supermarketId = 2;
    processInsert(prcs, addingProcess4);
}

void printElement(process el) {
    printf("\n############# PROCESSO %i #############\n", el.processId);
    printf("O nome: %s\n", el.name);
    printf("A idade: %i\n", el.age);
    printf("O endereco: %s\n", el.address);
    printf("O telefone: %ld\n", el.phone);
    printf("A data: %s\n", el.date);
    printf("O valor: %i\n",el.value);
    printf("O ID do Supermercado: %i\n", el.supermarketId);
}

void showElements(processes* prcs) {
    processEach(prcs, printElement);
}

void showMenu(processes* prcs) {
    int option, auxID;
    printf("Escolha uma opcao no menu abaixo:\n\n"
                "1 - Inserir novo processo\n"
                "2 - Remover processo atraves do ID\n"
                "3 - Priorizar mercado\n"
                "4 - Listar processo\n"
                "5 - Carregas processos de teste\n"
                "0 - Fechar o programa\n");

    scanf("%d", &option);

    switch(option) {
        case 1:
            insertProcess(prcs);
        break;
        case 2:
            printf("\nQual o ID do processo que voce quer remover?");
            scanf("%i", &auxID);
            processRemoveByID(prcs, auxID);
            showMenu(prcs);
        break;
        case 3:
            printf("\nQual ID do mercado que voce quer priorizar?");
            scanf("%i", &auxID);
            processPrioritizeSupermarket(prcs, auxID);
            showMenu(prcs);
        break;
        case 4:
            showElements(prcs);
            showMenu(prcs);
        break;
        case 5:
            loadTestProcess(prcs);
            printf("\nProcessos de exemplo carregados!\n\n");
            showMenu(prcs);
        break;
        case 0:
            exit(2);
        break;
    }
}

int main() {
    // Aloco memória para a pilha de processos
    processes* prcs = processAlloc();

    showMenu(prcs);
}

