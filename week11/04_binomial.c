#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAXN 21

// compute (n choose k = (n-1 choose k-1) + (n-1 choose k))
long binomial_coefficient(int n, int k) {
    long bc[MAXN][MAXN]; // table of coefficients
    int i, j;

    if ((n < 0) || (MAXN <= n) || (k < 0) || (n < k)) {
        // error
	return -1;
    }

    // initialize table with boundary values
    for (i=0; i<=n; ++i) {
    	bc[i][0] = 1;
	bc[i][i] = 1;
    }

    // fill in the rest of the table
    for (i=1; i<=n; ++i) {
        for (j=1; j<i; ++j) {
	    bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
	}
    }
    return bc[n][k];
}

int main() {
    for (int i=0; i<MAXN; ++i) {
        printf("%.2d: ", i);
        for (int j=0; j<=i; ++j) {
	    printf("%.6ld ", binomial_coefficient(i, j));
	}
	printf("\n");;
    }

    return 0;
}
