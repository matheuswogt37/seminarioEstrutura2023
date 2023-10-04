#include <stdio.h>
#include "arrayDB.c"

void errorTreatmentList(int error) {
    if (error == -1) {
        printf("Valor nao encontrado!\n");
    }
}

int linearSearch(List *list, int searchVal) {
    Node *nodo;
    nodo = list->head;
    for (int i = 0; i < list->size; i++) {
        if (nodo->info == searchVal) {
            printf("Valor %i encontrado na posicao %i\n", searchVal, ++i);
            return 1;
        }
        nodo = nodo->next;
    }
    return -1;
}

void main() {

    List* queue;
    queue = allocMiddle01List();

    errorTreatmentList(linearSearch(queue, 4620));


    freeList(queue);
    return 0;
}