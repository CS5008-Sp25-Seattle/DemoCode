#include <stdio.h>

int main() {
    // first create an integer
    int x = 5;

    // then create a pointer to the integer
    int* y_p = &x;

    // show that the value of x and the 
    // value y_p points to are the same
    printf("Value of x: %d\n", x);
    printf("Value of variable y_p points to: %d\n", *y_p);
    printf("\n");

    // change x via y_p
    *y_p = 100;

    // show that the value of x and value y_p
    // points to are the same
    printf("Value of x: %d\n", x);
    printf("Value of variable y_p points to: %d\n", *y_p);
  
    return 0;
}


