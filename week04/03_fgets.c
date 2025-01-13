#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// maximum length of string in this program
#define STRLENGTH 80

int main() {
    // temporary variable to read each line from the console
    char inputLine[STRLENGTH];

    bool done = false;

    printf("==============START============\n");

    while (!done) {
	printf("Input (QUIT to quit)> ");
	if (fgets(inputLine, STRLENGTH, stdin) == NULL) {
	    printf("End of file encountered.\nProgram terminated\n");
	    return -1;
	}
	printf(">>%s", inputLine);
	if (0 == strcmp(inputLine, "QUIT\n")) {
	    done = true;
	}
    }
    printf("===============END=============\n");

}
