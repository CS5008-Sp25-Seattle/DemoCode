#include <stdio.h>

int main() {

    // declare an array of 5 sequential
    // locations in memory, each to hold
    // an integer
    int my_numbers[5] = {1, 17, 999, 0xFF, 1025067};
    int i;

    // print out pairs of numbers as decimal
    for (i=0; i<5; ++i) {
	printf("%d> %d\n", i, my_numbers[i]);
    }
    printf("\n");

    // print out pairs of numbers as hexadecimal
    for (i=0; i<5; ++i) {
	printf("%x> %x\n", i, my_numbers[i]);
    }
    printf("\n");

    return 0;
}


