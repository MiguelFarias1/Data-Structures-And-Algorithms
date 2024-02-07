#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int element;
    struct Node *next;
    struct Node *previous;
};

typedef struct Node Node;

struct LinkedList
{
    struct Node *start;
    struct Node *end;
    int size;
};

typedef struct LinkedList LinkedList;

Node *CreateNode(int element)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = NULL;
    newNode->previous = NULL;

    return newNode;
}

LinkedList *CreateList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));

    list->start = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}

LinkedList *InsertElement(LinkedList *list, int element)
{
    Node * newNode = CreateNode(element);

    if (list == NULL)
    {
        list = CreateList();

        list->start = newNode;
        list->end = newNode;
        list->size++;
    }
    else
    {
        list->end->next = newNode;
        newNode->previous = list->end;
        list->end = list->end->next;

        list->size++;
    }

    return list;
}

void ClearList(LinkedList *list)
{
    list->start = NULL;
    list->end = NULL;
    list->size = 0;

    free(list);

}

void PrintList(LinkedList *list)
{
    Node *aux = list->start;

    for (int i = 0; i < list->size; i++)
    {
        printf("[%d]\n", aux->element);
        aux = aux->next;
    }
}

void PrintReverse(LinkedList * list)
{
    Node *aux = list->end;

    for (int i = 0; i < list->size; i++)
    {
        printf("[%d]\n", aux->element);
        aux = aux->previous;
    }
}

int main()
{
    LinkedList *list = NULL;

    for (int i = 0; i < 100; i++)
    {
        list = InsertElement(list, i);
    }

    PrintReverse(list);

    ClearList(list);

    return 0;
}
