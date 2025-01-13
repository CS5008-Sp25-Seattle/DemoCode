#include <stdio.h>

int main() {
    int i;
    char c;

    printf("c's address: %p, and size: %lu bytes\n", (char*)&c, sizeof(c));
    printf("i's address: %p, and size: %lu bytes\n", (int*)&i, sizeof(i));
}


