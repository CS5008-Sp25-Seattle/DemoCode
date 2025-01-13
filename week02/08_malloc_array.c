#include <stdio.h>
#include <stdlib.h>


int main() {
    // declare ptr to array of 4 int and allocate memory
    int* new_array_p = (int*)malloc(4*sizeof(int));
    int i;

    // assign values to elements
    new_array_p[0] = 5;
    new_array_p[1] = 10;
    new_array_p[2] = 15;
    new_array_p[3] = 20;

    for (i=0; i<4; ++i) {
        printf("new_array_p[%d] has value %d\n",
			i, new_array_p[i]);
    }

    free(new_array_p); // releases memory

    return 0;
}
