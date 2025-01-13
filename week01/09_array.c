#include <stdio.h>

int main() {

    // declare an array of 5 sequential
    // locations in memory, each to hold
    // an integer
    int my_numbers[5];
    int i;

    // assign values by index
    my_numbers[0] = 1;
    my_numbers[1] = 17;
    my_numbers[2] = 999;
    my_numbers[3] = 0xFF; // a hex constant
    my_numbers[4] = 1025067;

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


