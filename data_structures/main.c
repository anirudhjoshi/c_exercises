#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sorting.h"

#define MAX 10

char* randomString(char *s, int size){

    int i;
    static const char pool[] = "123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (i = 0; i < size; i++){

        s[i] = pool[ rand() % (sizeof pool- 1)];

    }

    s[i] = '\0';

    return s;

}

int main(){

    int i;
    int *data = malloc(sizeof(int) * MAX);
     char* key;
     char* value;

    srand(time(NULL));

    void *list = initialise();

    for (i = 0; i < MAX; i++) {

        record* data = malloc(sizeof(record));

        key = malloc(sizeof(char) * MAX);
        value = malloc(sizeof(char) * MAX);

        randomString(key, MAX);
        randomString(value, MAX);

        data->key = key;
        data->value = value;

        put(list, data);

    }

    printList(list);

    return 0;

    record* r = get(list,key);

    if (r) {

        char* v = r->value;
        printf("Key: %s, Value: %s, GValue: %s\n", key, value, v);

    }

    del(list, key);

    printList(list);
    r = get(list,key);

    if (r) {

        char* v = r->value;
        printf("Key: %s, Value: %s, GValue: %s\n", key, value, v);

    } else {

        printf("Not found.");

    }

    return 0;

}

