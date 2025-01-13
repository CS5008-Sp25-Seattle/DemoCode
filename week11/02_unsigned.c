#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


int main() {
    unsigned long long bigval;

    bigval = 0;
    printf("unsigned long long of 0 = %llu\n", bigval);

    bigval = 10;
    printf("unsigned long long of 10 = %llu\n", bigval);

    bigval = 100;
    printf("unsigned long long of 100 = %llu\n", bigval);

    bigval = -1;
    printf("unsigned long long of -1 = %llu\n", bigval);

    bigval = -2;
    printf("unsigned long long of -2 = %llu\n", bigval);

    return 0;
}

