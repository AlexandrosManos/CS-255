#include "SymTable.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#define HASH_MULTIPLIER 65599
#define LOWER_BOUND 509
#define UPPER_BOUND 65521

typedef struct hashNode
{
    char *key;
    void *value;
    struct hashNode *next;
} *hash_t;

/*
Hash Table struct
size_t size is the number of buckets
hash_t *buckets, an array of pointers
*/
struct SymTable
{
    size_t size;
    hash_t *buckets;
};
/*Creates New node for the hash table*/
hash_t New_node(void)
{
    hash_t ptr = malloc(sizeof(hash_t));
    if (ptr == NULL)
    {
        printf("error-out of memory\n");
        exit(-1);
    }
    ptr->key = NULL;
    ptr->next = NULL;
    ptr->value = NULL;
    return ptr;
}
/*A Static function that increases the number of buckets*/
static int Resize(SymTable_T oSymTable);

/*A Static function, returns a hash code for pcKey. */
static unsigned int SymTable_hash(const char *pcKey);

SymTable_T SymTable_new(void)
{
    int index;
    SymTable_T HashTable = malloc(sizeof(struct SymTable));
    if (HashTable == NULL)
    {
        printf("error-out of memory\n");
        exit(-1);
    }
    HashTable->size = LOWER_BOUND;
    HashTable->buckets = malloc((HashTable->size) * sizeof(hash_t));
    if (HashTable->buckets == NULL)
    {
        printf("error-out of memory\n");
        exit(-1);
    }
    for (index = 0; index < HashTable->size; index++)
    {
        HashTable->buckets[index] = NULL;
    }
    return HashTable;
}

/* Frees the memory used by the symbol table */
void SymTable_free(SymTable_T oSymTable)
{
    size_t count, index;
    hash_t access, next;
    if (oSymTable == NULL)
        return;

    count = oSymTable->size;
    for (index = 0; index < count; index++)
    {
        access = oSymTable->buckets[index];
        while (access)
        {
            next = access->next;
            free(access->key);
            free(access);
            access = next;
        }
    }
    return;
}

/* Return a hash code for pcKey. */

static unsigned int SymTable_hash(const char *pcKey)
{
    size_t ui;

    unsigned int uiHash = 0U;

    for (ui = 0U; pcKey[ui] != '\0'; ui++)

        uiHash = uiHash * HASH_MULTIPLIER + pcKey[ui];

    return uiHash;
}
/* Returns the number of the nodes */
unsigned int SymTable_getLength(SymTable_T oSymTable)
{
    unsigned int counter = 0;
    size_t count, index;
    hash_t access;
    assert(oSymTable);
    count = oSymTable->size;
    for (index = 0; index < count; index++)
    {
        access = oSymTable->buckets[index];
        while (access)
        {
            counter++;
            access = access->next;
        }
    }
    return counter;
}
/* Adds a new node to the hash table */
int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue)
{
    size_t index;
    hash_t access, previous;
    assert(pcKey);
    assert(oSymTable);
    /*Reminder to change this for bonus + check for upper bound*/
    if (SymTable_getLength(oSymTable) == oSymTable->size)
    {
        if (Resize(oSymTable) == 0)
        {
            /*if the resize failed*/
            return 0;
        }
    }
    index = SymTable_hash(pcKey) % (oSymTable->size);
    access = oSymTable->buckets[index];
    previous = access;
    if (access != NULL)
    {
        do
        {
            if (strcmp(access->key, pcKey) == 0)
            {
                return 0;
            }
            previous = access;
            access = access->next;
        } while (access != NULL);
    }
    access = New_node();
    /*+1 for \0, the end of string*/
    access->key = malloc((strlen(pcKey) + 1) * sizeof(char));
    strcpy(access->key, pcKey);
    access->value = pvValue;
    /*first Node*/
    if (previous == NULL)
    {
        oSymTable->buckets[index] = access;
    }
    else
        previous->next = access;
    return 1;
}
/* Removes binding from the symbol table */
int SymTable_remove(SymTable_T oSymTable, const char *pcKey)
{
    size_t index;
    hash_t previous, access;
    assert(oSymTable);
    assert(pcKey);
    index = SymTable_hash(pcKey) % (oSymTable->size);
    access = oSymTable->buckets[index];
    previous = NULL;
    while (access != NULL)
    {
        if (!strcmp(access->key, pcKey))
        {
            if (previous != NULL)
            {
                previous->next = access->next;
            }
            else
            {
                oSymTable->buckets[index] = access->next;
            }
            free(access->key);
            free(access);
            return 1;
        }
        access = previous;
        access = access->next;
    }
    return 0;
}
/* Checks if the symbol table contains a binding*/
int SymTable_contains(SymTable_T oSymTable, const char *pcKey)
{
    size_t index;
    hash_t access;
    assert(oSymTable);
    assert(pcKey);
    index = SymTable_hash(pcKey) % (oSymTable->size);
    access = oSymTable->buckets[index];
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
/* Returns the value corresponding to pckey */
void *SymTable_get(SymTable_T oSymTable, const char *pcKey)
{
    size_t index;
    hash_t access;
    assert(oSymTable);
    assert(pcKey);
    index = SymTable_hash(pcKey) % (oSymTable->size);
    access = oSymTable->buckets[index];
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
    size_t index;
    hash_t access;
    assert(pfApply);
    assert(oSymTable);
    for (index = 0; index < oSymTable->size; index++)
    {
        access = oSymTable->buckets[index];
        while (access != NULL)
        {
            pfApply(access->key, access->value, pvExtra);
            access = access->next;
        }
    }
    return;
}
/*----------------BONUS----------------------------------*/

/*A Static function that increases the number of buckets*/
/*Returns 0 if the resize failed*/
static int Resize(SymTable_T oSymTable)
{
    /* 509, 1021, 2053, 4093, 8191, 16381, 32771, and 65521. */
    size_t newSize, index, buckIndex;
    hash_t *Buckets, acceess, *last;
    if (oSymTable == NULL)
    {
        return 0;
    }
    newSize = oSymTable->size;
    if (newSize == 509)
    {
        newSize = 1021;
    }
    else if (newSize == 1021)
    {
        newSize = 2053;
    }
    else if (newSize == 2053)
    {
        newSize = 4093;
    }
    else if (newSize == 4093)
    {
        newSize = 8191;
    }
    else if (newSize == 8191)
    {
        newSize = 16381;
    }
    else if (newSize == 16381)
    {
        newSize = 32771;
    }
    else if (newSize == 32771)
    {
        newSize = 65521;
    }
    else if (newSize == 65521)
    {
        /*Max size, size cannot be increased*/
        return 0;
    }
    Buckets = malloc((newSize) * sizeof(hash_t));
    last = malloc((newSize) * sizeof(hash_t));
    if (Buckets == NULL || last == NULL)
    {
        printf("error-out of memory\n");
        return 0;
    }
    for (index = 0; index < newSize; index++)
    {
        Buckets[index] = NULL;
        last[index] = NULL;
    }
    for (index = 0; index < oSymTable->size; index++)
    {
        acceess = oSymTable->buckets[index];
        /*redistribution of the buckets*/
        while (acceess)
        {
            buckIndex = SymTable_hash(acceess->key) % newSize;
            if (last[buckIndex] == NULL)
            {
                Buckets[buckIndex] = acceess;
                last[buckIndex] = Buckets[buckIndex];
            }
            else
            {
                last[buckIndex]->next = acceess;
                last[buckIndex] = last[buckIndex]->next;
            }
            acceess = acceess->next;
            last[buckIndex]->next = NULL;
        }
    }
    free(oSymTable->buckets);
    free(last);
    oSymTable->buckets = Buckets;
    oSymTable->size = newSize;
    return 1;
}
