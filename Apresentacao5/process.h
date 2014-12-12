#pragma once

typedef struct process_manager processes;

typedef struct process_element {
    int processId;
    unsigned value; // centavos
    int supermarketId;
    
    char name[100];
    unsigned age;
    char address[300];
    unsigned long long phone;
    char date[100];
} process;

processes* processAlloc(void);

// Insere elemento na pilha de processos
void processInsert(processes* prcs, process el);

// Remove elemento da pilha de processos
void processRemoveByID(processes* prcs, int id);

// Desempilha uma unidade de processos e retorna ela
process processPop(processes* prcs);

// Retorna o processo do topo, porém sem desempilhar
process processTop(processes* prcs);

// Retorna o processo da base
process processBottom(processes* prcs);

// Retorna processo a partir do ID
process processGetByID(processes* prcs, int id);

// Prioriza um supermercado através do ID
void processPrioritizeSupermarket(processes* prcs, int supermarketId);

// Prioriza por valor
void processPrioritizeValue(processes* prcs);

// Quantidade de processos
unsigned processAmount(processes* prcs);

// Itera sobre os processos
void processEach(processes* prcs, void(*callback)(process el));
