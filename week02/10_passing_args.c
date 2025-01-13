#include <stdio.h> 


void double_int(int i) {
    // attempt to double the input parameter
    i = i * 2;
    return;
}

void double_ptr_to_int(int* i_p) {
    // attempt to double the value the parameter points to
    if (i_p != NULL) {
        *i_p = *i_p * 2;
    }
    return;
}

void double_array(int* a, int sizeofa) {
    // attempt to double the elements of an integer array
    for (int i=0; i<sizeofa; ++i) {
        a[i] = 2 * a[i];
    }
}

int main() {
    int my_int = 5;
    printf("Attempting to double %d with pass-by-value\n",
           my_int);
    double_int(my_int);

    printf("Result of doubling by pass-by-value: %d\n\n",
           my_int);

    printf("Attempting to double %d with pass-by-reference\n", 
           my_int);
    double_ptr_to_int(&my_int);

    printf("Results of doubling by pass-by-reference: %d\n\n", 
           my_int);

    int my_int_array[5] = {1,2,3,4,5};
    int my_int_array_size = 5;

    printf("Attempting to double int array contents: ");
    for (int i=0; i<my_int_array_size; ++i) {
	printf("%d ", my_int_array[i]);
    }
    printf("\n");

    double_array(my_int_array, my_int_array_size);

    printf("Result of doubling array contents: ");
    for (int i=0; i<my_int_array_size; ++i) {
	printf("%d ", my_int_array[i]);
    }
    printf("\n");
}



