#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sorting.h"

#define MAX 10

int main(){

    int i;
    int *data = malloc(sizeof(int) * MAX);

    srand(time(NULL));

    void *list = initialise();

    for (i = 0; i < MAX; i++) {

        int num = rand() % (1000 - 1);
        insert(list, num);

    }

    printList(list);

    printf("Key: %i, Value: %i\n", 50, get(list, 50));

    return 0;

}

