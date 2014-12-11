#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "tree.h"
#include "queue.c"


struct treeManager {
    queue* qu;
};

tree* treeAlloc(void) {
    tree* tree = malloc(sizeof(*tree));
    tree->qu = queue_alloc();
    return tree;
}

static const char* targetname;

static int test(void*a) {
    return strcmp(((person*)a)->name, targetname) == 0;
}

person* searchByName(tree* tree, char* name) {
    queue* qu = tree->qu;
    targetname = name;
    unsigned i = queue_find(qu, test);
    if (i == -1) {
        return NULL;
    }
    return queue_nth(qu, i);
}

person* createPerson(tree* tr, char* name, unsigned gender, char* father, unsigned mode) {
    person* p = malloc(sizeof(person));
    personInformation* pi = malloc(sizeof(personInformation));
    p->name = name;
    pi->gender = gender;
    p->information = pi;

    if (mode == 2) {
        // Checando se o pai existe!
        if (father != NULL) {
            person* fatherEl = searchByName(tr, father);
            if (fatherEl == NULL || fatherEl->information->partner == NULL) {
                return NULL;
            }

            pi->father = fatherEl;

            // Se esse for o primeiro filho associado então tudo Ok, se não temos que gerenciar os irmãos
            if (fatherEl->information->son == NULL) {
                fatherEl->information->son = p;
            } else {
                unsigned running = 1;
                person* son = fatherEl->information->son;
                while(running == 1) {
                    if (son->information->brother == NULL) {
                        son->information->brother = p;
                        running = 0;
                    } else {
                        son = son->information->brother;
                    }
                }
            }
        }
    }

    return p;
}

void addPerson(tree* tr, char* name, unsigned gender) {
    queue* qu = tr->qu;
    person* newPerson = createPerson(tr, name, gender, NULL, 1);
    if (newPerson == NULL) {
        return NULL;
    }
    queue_push(qu, newPerson);
}

void addSon(tree* tr, char* name, unsigned gender, char* father) {
    queue* qu = tr->qu;
    person* newPerson = createPerson(tr, name, gender, father, 2);
    if (newPerson == NULL) {
        return NULL;
    }
    queue_push(qu, newPerson);
}

void addMarriage(tree* tr, char* personName, char* partner) {
    person* personEl = searchByName(tr, personName);

    if (personEl == NULL) {
        return NULL;
    }

    person* partnerEl = searchByName(tr, partner);
    if (partnerEl == NULL) {
        return NULL;
    }

    personEl->information->partner = partnerEl;
    partnerEl->information->partner = personEl;
}

person* getPartner(tree* tr, person* personName) {
    person* personEl = searchByName(tr, personName);
    if (personEl == NULL) {
        return NULL;
    }
    return personEl->information->partner;
}

person* getFather(tree* tr, person* personName) {
    person* personEl = searchByName(tr, personName);
    if (personEl == NULL) {
        return NULL;
    }
    return personEl->information->father;
}

person* getMother(tree* tr, person* personName) {
    person* personEl = searchByName(tr, personName);
    if (personEl == NULL) {
        return NULL;
    }
    return personEl->information->father->information->partner;
}

queue* getChildren(tree* tr, person* personName) {
    person* personEl = searchByName(tr, personName);
    if (personEl == NULL) {
        return NULL;
    }

    queue* qu = queue_alloc();
    unsigned running = 1;
    person* son = personEl->information->son;

    if (son == NULL) {
        return qu;
    }

    while (running == 1) {
        if (son == NULL) {
            running = 0;
        } else {
            queue_push(qu, son);
            son = son->information->brother;
        }
    }

    return qu;
}

queue* getSiblings(tree* tr, person* personName) {
    person* personEl = searchByName(tr, personName);
    if (personEl == NULL) {
        return NULL;
    }

    queue* qu = queue_alloc();
    unsigned running = 1;
    person* son = personEl->information->father->information->son;

    if (son == NULL) {
        return qu;
    }

    while (running == 1) {
        if (son == NULL) {
            running = 0;
        } else {
            if (son->name != personName) {
                queue_push(qu, son);
            }
            son = son->information->brother;
        }
    }

    return qu;
}

queue* getUncles(tree* tr, person* personName) {
    person* personEl = searchByName(tr, personName);
    if (personEl == NULL) {
        return NULL;
    }

    queue* qu = queue_alloc();
    unsigned running = 1;
    unsigned motherCheck = 0;
    person* mfather = personEl->information->father;
    person* mother = mfather->information->partner;

    if (mfather == NULL && mother == NULL) {
        return NULL;
    }

    person* uncle = mfather->information->father->information->son;

    if (mfather->information->father == NULL || uncle  == NULL) {
        return qu;
    }

    while (running == 1) {
        if (uncle == NULL) {
            if (motherCheck == 0) {
                if (mother->information->father == NULL || mother->information->father->information->son == NULL) {
                    return qu;
                }
                uncle = mother->information->father->information->son;
                motherCheck = 1;
            } else {
                running = 0;
            }
        } else {
            if (uncle->name != mfather->name && uncle->information->gender == 1) {
                queue_push(qu, uncle);
            }
            uncle = uncle->information->brother;
        }
    }

    return qu;
}

void print_person(void* vp) {
    struct person* p = (person*)vp;
    printf("\"%s\" \n", p->name);
}


