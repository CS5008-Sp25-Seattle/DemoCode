#include <stdio.h>

int sum(int k) {
    if (k <= 1) {
        // base case, with error protection for <=0
	return 1; 
    } else {
	// recursive case
	return (k + sum(k-1));
    }
}

int main() {
    printf("\nSum to 5 = %d\n\n", sum(5));
    return 0;
}
