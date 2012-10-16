typedef struct record_s {

    char *key;
    char *value;

} record;

void* initialise();

int put(void*, record*);
int del(void*, char*);

record* get(void*, char*);

void printList(void*);

