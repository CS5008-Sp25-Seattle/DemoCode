#include <stdio.h>

int main() {
    // declare a string as an array of 10 char
    char my_string[10];

    my_string[0] = 'C';
    my_string[1] = 'S';
    my_string[2] = ' ';
    my_string[3] = '5';
    my_string[4] = '0';
    my_string[5] = '0';
    my_string[6] = '8';
    my_string[7] = '\0'; // string terminal (NUL) character
    // indexes 7, 8, and 9 are not initialized.

    printf("Welcome to %s!\n", my_string);

    return 0;
}
