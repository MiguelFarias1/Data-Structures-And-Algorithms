#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int element;
    struct Node *next;
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
    if (list == NULL)
    {
        list = CreateList();

        list->start = CreateNode(element);
        list->end = list->start;
        list->size++;
    }
    else
    {
        list->end->next = CreateNode(element);
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

int main()
{
    LinkedList *list = NULL;

    for (int i = 0; i < 100; i++)
    {
        list = InsertElement(list, i);
    }

    printf("\nThe quantity of elements inserted in the list [%d]\n", list->size);

    ClearList(list);

    return 0;
}
