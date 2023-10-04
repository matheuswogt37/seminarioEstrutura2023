#include <stdio.h>
#include "arrayDB.c"

Node *middle(Node *start, Node *last)
{

    if (start == NULL)
        return NULL;

    Node *slow = start;
    Node *fast = start;

    while (fast != last)
    {
        fast = fast->next;
        if (fast != last)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

Node *binarySearch(List *list, int searchVal)
{
    Node *nodo;
    Node *middleNodo;
    int start, end, middleVal;
    Node *nStart, *nEnd, *nAuxEnd;

    nStart = list->head;
    nEnd = list->tail;

    start = 0;
    end = list->size;
    middleVal = (start + end) / 2;
    middleNodo = middle(nStart, NULL);

    while (start <= end)
    {
        if (searchVal == middleNodo->info)
        {
            printf("Valor %i encontrado\tretornando nodo\n", searchVal);
            return middle;
        }
        if (searchVal < middleNodo->info)
        {
            end = middleVal - 1;
            nEnd = middleNodo->prev;
        }
        else
        {
            start = middleVal + 1;
            nStart = middleNodo->next;
        }
        middleVal = (start + end) / 2;
        middleNodo = middle(nStart, nEnd);
    }

    printf("Valor %i nao encontrado!\n", searchVal);
    return NULL;
}

int main()
{
    List *queue;
    queue = allocLinearList();

    int test[] = {1, 3, 5, 7, 2, 4, 6, 9, 14};

    for (int i = 0; i < arrayLength(test); i++)
    {
        binarySearch(queue, test[i]);
    }

    freeList(queue);
    return 0;
}