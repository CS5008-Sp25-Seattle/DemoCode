#include <stdio.h>

int main() {
    int x;
    int* y_p;

    x = 500;
    y_p = &x; 

    printf("Value of x: %d\n", x);
    printf("Size of x: %lu\n", sizeof(x));
    printf("Address of x: %p\n\n", (int*)&x);

    if (y_p != NULL) {
        printf("Value of y_p: %p\n", y_p);
        printf("Size of y_p: %lu\n", sizeof(y_p));
	printf("Address of y_p: %p\n\n", (void*)&y_p);
    }

    return 0;
}


