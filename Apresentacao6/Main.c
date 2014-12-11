#include "tree.c"

int main(void) {
    tree* tr = treeAlloc();
    addPerson(tr, "Guilherme", 1);
    addPerson(tr, "Marivaldo", 1);
    addPerson(tr, "Esmeraldina", 2);
    addMarriage(tr, "Marivaldo", "Esmeraldina");
    addSon(tr, "Jose", 1, "Marivaldo");
    addSon(tr, "Hulk", 1, "Marivaldo");
    addSon(tr, "Mulher Maravilha", 2, "Marivaldo");
    addPerson(tr, "Maria", 2);
    addMarriage(tr, "Jose", "Maria");
    addPerson(tr, "Bruno", 1);
    addSon(tr, "Rodrigo Araujo", 1, "Jose");
    addSon(tr, "Brito Junior", 1, "Jose");
    addSon(tr, "Hichard", 1, "Jose");

    puts("# Pessoas adicionadas com sucesso:");
    queue* qu = tr->qu;
    queue_each(qu, print_person);
    puts("\n");

    addMarriage(tr, "Rodrigo Araujo", "Bruno");

    person* pai = getFather(tr, "Rodrigo Araujo");
    person* mae = getMother(tr, "Rodrigo Araujo");
    if (pai != NULL && mae != NULL) {
        printf("# Pai do Rodrigo: %s / Mae do Rodrigo: %s\n", pai->name, mae->name);
        puts("\n");
    }

    queue* childen = getChildren(tr, "Jose");
    if (childen != NULL) {
        puts("# Filhos de Jose:");
        queue_each(childen, print_person);
        puts("\n");
    }

    queue* siblings = getSiblings(tr, "Rodrigo Araujo");
    if (siblings != NULL) {
        puts("# Irmaos de Rodrigo:");
        queue_each(siblings, print_person);
        puts("\n");
    }

    queue* uncles = getUncles(tr, "Rodrigo Araujo");
    if (uncles != NULL) {
        puts("# Tios de Rodrigo:");
        queue_each(uncles, print_person);
        puts("\n");
    }
}
