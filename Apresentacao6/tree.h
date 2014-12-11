#pragma once
#include "queue.h"

typedef struct treeManager tree;
typedef struct personInformation personInformation;

typedef struct person {
    char* name;
    personInformation* information;
} person;

typedef struct personInformation {
    char* name;
    unsigned gender;
    person* father;
    person* partner;
    person* brother;
    person* son;
};

tree* treeAlloc(void);

void addPerson(tree* tree, char* name, unsigned gender);

void addSon(tree* tree, char* name, unsigned gender, char* father);

void addMarriage(tree* tree, char* person, char* partner); 

person* getPartner(tree* tree, person* person);

person* getParents(tree* tree, person* person);

queue* getChildren(tree* tree, person* person);

queue* getSiblings(tree* tree, person* person);

queue* getUncles(tree* tree, person* person);