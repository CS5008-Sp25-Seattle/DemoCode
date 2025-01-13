#include <stdio.h>

int main() {
    // declare a string as an array of 10 char
    char my_string[10] = "CS 5008";
    int i;

    // indexes 7, 8, and 9 still not initialized

    printf("Our string is: \"%s\"\n", my_string);

    // print the address of each char in the string
    
    for (i=0; i<10; ++i) {
        printf("Address of %c: %p\n", my_string[i], (char*)&my_string[i]);
    }

    return 0;
}
