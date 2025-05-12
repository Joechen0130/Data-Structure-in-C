// test.c
#include <stdio.h>
#include "Queue_array.h"

int main() {
    Queue q;
    initQueue(&q);

    for(int i = 0; i < 20; i++){
        enQueue(&q, i);
        Print(&q);
    }

    for(int i = 0; i < 20; i++){
        printf("data: %d\n", deQueue(&q));
        Print(&q);
    }

    return 0;
}
