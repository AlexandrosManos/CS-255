/*Struct for symbol Table*/
typedef struct SymTable *SymTable_T;

SymTable_T SymTable_new(void);

/* Frees the memory used by the symbol table */
void SymTable_free(SymTable_T oSymTable);

/* Returns the number of the bindings */
unsigned int SymTable_getLength(SymTable_T oSymTable);

/* Adds a new bind to the symbol table */
int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue);

/* Removes a binding from the symbol table */
int SymTable_remove(SymTable_T oSymTable, const char *pcKey);

/* Checks if the symbol table contains a binding*/
int SymTable_contains(SymTable_T oSymTable, const char *pcKey);

/* Returns the value corresponding to pckey */
void *SymTable_get(SymTable_T oSymTable, const char *pcKey);

/* Applies a function to each binding in the symbol table */
void SymTable_map(SymTable_T oSymTable, void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra), const void *pvExtra);