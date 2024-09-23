#include "SymTable.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

/*List of bindings*/
struct SymTable
{
    char *key;
    void *value;
    SymTable_T next;
};
/*Creates New node for the list*/
SymTable_T SymTable_new(void)
{
    SymTable_T ptr = malloc(sizeof(struct SymTable));
    if (ptr == NULL)
    {
        printf("error-out of memory\n");
        exit(-1);
    }
    /*No bindings*/
    ptr->key = NULL;
    ptr->value = NULL;
    ptr->next = NULL;
    return ptr;
}
/* Frees the memory used by the symbol table */
void SymTable_free(SymTable_T oSymTable)
{
    SymTable_T access;
    if (oSymTable == NULL)
        return;
    while (oSymTable)
    {
        access = oSymTable;
        if (access->key != NULL)
            free(access->key);
        oSymTable = access->next;
        free(access);
    }
    return;
}
/* Return the number of bindings.*/
unsigned int SymTable_getLength(SymTable_T oSymTable)
{
    unsigned int count = 0;
    assert(oSymTable);
    while (oSymTable->next != NULL)
    {
        count++;
        oSymTable = oSymTable->next;
    }
    return count;
}
/* Adds a new node to the list*/
int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue)
{
    SymTable_T to_add, access;
    assert(pcKey);
    assert(oSymTable);
    access = oSymTable;
    while (access->next != NULL)
    {
        if (access->key != NULL && strcmp(access->key, pcKey) == 0)
        {
            /*Key already exists*/
            return 0;
        }
        access = access->next;
    }
    if (access->key != NULL && strcmp(access->key, pcKey) == 0)
    {
        return 0;
    }
    to_add = SymTable_new();
    to_add->value = pvValue;
    /*+1 for \0, end of string*/
    to_add->key = malloc((strlen(pcKey) + 1) * sizeof(char));
    strcpy(to_add->key, pcKey);
    access->next = to_add;

    return 1;
}
/* Removes binding from the symbol table */
int SymTable_remove(SymTable_T oSymTable, const char *pcKey)
{
    SymTable_T previous, access;
    assert(oSymTable);
    assert(pcKey);
    previous = NULL;
    access = oSymTable->next;
    while (access != NULL)
    {
        if (strcmp(access->key, pcKey) == 0)
        {
            if (previous != NULL)
            {
                previous->next = access->next;
            }
            else
            {
                oSymTable->next = access->next;
            }
            free(access->key);
            free(access);
            return 1;
        }
        previous = access;
        access = access->next;
    }
    return 0;
}
/* Checks if the symbol table contains a binding*/
int SymTable_contains(SymTable_T oSymTable, const char *pcKey)
{
    SymTable_T access;
    assert(oSymTable);
    assert(pcKey);
    access = oSymTable->next;
    while (access != NULL)
    {
        if (!strcmp(access->key, pcKey))
        {
            return 1;
        }
        access = access->next;
    }
    return 0;
}
/* Return the value corresponding to pckey */
void *SymTable_get(SymTable_T oSymTable, const char *pcKey)
{
    SymTable_T access;
    assert(oSymTable);
    assert(pcKey);
    access = oSymTable->next;
    while (access != NULL)
    {
        if (!strcmp(access->key, pcKey))
            return access->value;
        access = access->next;
    }
    return NULL;
}
/* Applies a function to each binding in the symbol table */
void SymTable_map(SymTable_T oSymTable,
                  void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra), const void *pvExtra)
{
    SymTable_T access;
    assert(pfApply);
    assert(oSymTable);
    access = oSymTable->next;
    while (access != NULL)
    {
        pfApply(access->key, access->value, pvExtra);
        access = access->next;
    }
    return;
}
