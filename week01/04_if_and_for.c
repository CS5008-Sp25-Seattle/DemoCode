#include <stdio.h>

int main() {

    // loop from 0 to 9
    for (int x=0; x < 10; x = x+1) {
        if (x % 2 == 0) {
            printf("x is even\n");
	} else {
	    printf("x is odd\n");
	}
    }

    return 0;
}



