#include <stdio.h>
#include <time.h>
#include "arrayDB.c"

void bubbleSort(List *list)
{

    int tamArray = list->size;
    Node *node;
    Node *auxNode;
    Node *nextNode;
    int countAssignments = 0;
    int countRepets = 0;
    int i, j;

    time_t start, end;
    double execution_time;

    time(&start);
    for (j = 0; j < tamArray; j++)
    {
        node = list->head;
        for (i = 0; i < (tamArray - 1); i++)
        {
            nextNode = node->next;
            countRepets++;
            if (node->info > node->next->info)
            {
                auxNode = node->next;

                if (node == list->head)
                {
                    list->head = auxNode;
                }
                else
                {
                    node->prev->next = auxNode;
                }
                auxNode->prev = node->prev;
                node->prev = auxNode;
                node->next = auxNode->next;
                if (auxNode == list->tail)
                {
                    list->tail = node;
                }
                else
                {
                    auxNode->next->prev = node;
                }
                auxNode->next = node;

                nextNode = node;
            }
            node = nextNode;
        }
    }
    time(&end);
    execution_time = ((double)(end - start));
}

void bubbleSort1Version(List *list)
{

    int tamArray = list->size;
    Node *node;
    Node *auxNode;
    Node *nextNode;
    int countAssignments = 0;
    int countRepets = 0;
    int i, j;

    time_t start, end;
    double execution_time;

    time(&start);

    for (j = 1; j <= (tamArray - 1); j++)
    {
        node = list->tail;
        for (i = (tamArray - 1); i >= j; i--)
        {
            auxNode = node->prev;
            nextNode = auxNode;
            if (auxNode->info > node->info)
            {

                countRepets++;
                auxNode = node->prev;
                if (node == list->tail)
                {
                    list->tail = auxNode;
                }
                else
                {
                    node->next->prev = auxNode;
                }
                auxNode->next = node->next;
                node->next = auxNode;
                node->prev = auxNode->prev;
                if (auxNode == list->head)
                {
                    list->head = node;
                }
                else
                {
                    auxNode->prev->next = node;
                }
                auxNode->prev = node;

                nextNode = node;
            }
            node = nextNode;
        }
    }

    time(&end);
    execution_time = ((double)(end - start));
}

void bubbleSort2Version(List *list)
{

    int tamArray = list->size;
    Node *node;
    Node *auxNode;
    Node *nextNode;
    int countAssignments = 0;
    int countRepets = 0;
    int i, j, trade;

    time_t start, end;
    double execution_time;

    time(&start);
    trade = 1;
    j = 0;
    while ((j < tamArray) && (trade == 1))
    {
        trade = 0;
        node = list->head;
        for (i = 0; i < (tamArray - 1); i++)
        {
            nextNode = node->next;
            countRepets++;
            if (node->info > node->next->info)
            {
                trade = 1;
                auxNode = node->next;

                if (node == list->head)
                {
                    list->head = auxNode;
                }
                else
                {
                    node->prev->next = auxNode;
                }
                auxNode->prev = node->prev;
                node->prev = auxNode;
                node->next = auxNode->next;
                if (auxNode == list->tail)
                {
                    list->tail = node;
                }
                else
                {
                    auxNode->next->prev = node;
                }
                auxNode->next = node;

                nextNode = node;
            }
            node = nextNode;
        }
        j++;
    }
    time(&end);
    execution_time = ((double)(end - start));
}

int main()
{

    List *queue;

    queue = allocMiddle03List();

    // bubbleSort(queue);
    bubbleSort(queue);

    printf("list->size %i\nlist->head %i\nlist->tail %i\n", queue->size, queue->head->info, queue->tail->info);

    freeList(queue);
    return 1;
}