#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_RANGE 95

char rand_char() {
    // 0 -> 0x20 -> ' '
    // 1 -> 0x21 -> '!'
    // ...
    // 94 -> 0x7E -> '~'
    // see https://ascii.cl
    return ((char)((rand() % RAND_RANGE)+0x20));
}

int main() {
    srand(time(NULL));
    printf("Random character: %c\n", rand_char());
    return 0;
}

