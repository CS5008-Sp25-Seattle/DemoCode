#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int main() {
    // declare x and y as integers and 
    // initialize to 5 and 7
    int x = 5;
    int y = 7;
  
    printf("%d + %d = %d\n", x, y, add(x, y));

    return 0;
}



