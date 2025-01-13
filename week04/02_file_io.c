#include <stdio.h>

int main() {
    char s1[80] = "";
    char s2[80] = "";
    int i3      = 0;
    FILE* fp;

    fp = fopen("example.txt", "r");
    if (fp != NULL) {
	if (feof(fp) == 0) {
	    fscanf(fp, "%s %s %i", s1, s2, &i3);
	    printf("The beginning of the input was: |%s %s %i|\n", s1, s2, i3);
	    fclose(fp);
	}
    } else {
	printf("File not found\n");
    }
}
