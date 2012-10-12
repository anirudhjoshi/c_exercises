#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sorting.h"

#define MAX 1000

int main(){

    int i;
    int *data = malloc(sizeof(int) * MAX);

    srand(time(NULL));

    for (i = 0; i < MAX; i++) {

        int num = rand() % (1000 - 1);
        data[i] = i;

    }

    create(data, MAX);

    return 0;

}

