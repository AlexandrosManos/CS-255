#include "symtable.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define count 10

void increase(const char *pcKey, void *pvValue, void *pvExtra);

int main()
{
    int values[count], i;
    SymTable_T testTable = SymTable_new();
    char *testMap = "Key 2";
    char keys[100][count] = {
        "Key 1",
        "Key 2",
        "Key 3",
        "Key 4",
        "Key 5",
        "Key 6",
        "Key 7",
        "Key 8",
        "Key 9",
        "Key 10",
    };
    for (i = 0; i < count; i++)
    {
        /*Random function*/
        values[i] = i + 1000 * i % 2;
    }
    /*SymTable_put Test--------------------------------------*/
    assert(SymTable_put(testTable, keys[0], values[1]) == 1);
    assert(SymTable_put(testTable, keys[0], values[0]) == 0);
    assert(SymTable_put(testTable, keys[1], values[1]) == 1);
    /*SymTable_getLength Test---------------------------------*/
    assert(SymTable_getLength(testTable) == 2);
    /*SymTable_remove Test------------------------------------*/
    assert(SymTable_remove(testTable, keys[4]) == 0);
    assert(SymTable_getLength(testTable) == 2);
    assert(SymTable_remove(testTable, keys[0]) == 1);
    assert(SymTable_getLength(testTable) == 1);
    assert(SymTable_remove(testTable, keys[1]) == 1);
    assert(SymTable_getLength(testTable) == 0);

    /*SymTable_contains-----Test---------------------------*/
    for (i = 0; i < 4; i++)
    {
        assert(SymTable_put(testTable, keys[i], values[i]) == 1);
    }
    assert(SymTable_getLength(testTable) == 4);
    assert(SymTable_contains(testTable, keys[2]) == 1);
    /*SymTable_get Test-------------------------------------*/
    assert(SymTable_get(testTable, keys[2]) != NULL);
    /*SymTable_map Test -----------------------------------*/
    SymTable_map(testTable, &increase, testMap);

    SymTable_free(testTable);
    printf("\n---END OF TEST----\n");
    return 0;
}

void increase(const char *pcKey, void *pvValue, void *pvExtra)
{
    if (strcmp(pcKey, pvExtra) == 0)
    {
        printf("Key = %s, value increased to = %d \n", pcKey, (pvValue + 5));
    }
}