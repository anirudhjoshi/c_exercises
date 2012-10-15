#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sorting.h"

#define MAX 10

char* randomString(char *s, int size){

    int i;
    int randomLength = rand() % (size) + 1;

    static const char pool[] = "123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (i = 0; i < randomLength; i++){

        s[i] = pool[ rand() % (sizeof pool- 1)];

    }

    s[i] = '\0';

    return s;

}

int main(){

    int i;
    int *data = malloc(sizeof(int) * MAX);
    char* s = malloc(sizeof(char) * MAX);

    srand(time(NULL));

    void *list = initialise();

    for (i = 0; i < MAX; i++) {

        int num = rand() % (1000 - 1);

        randomString(s, MAX);

        printf("%s\n", s);
        insert(list, num);

    }

    printList(list);

    printf("Key: %i, Value: %i\n", 50, get(list, 50));

    return 0;

}

