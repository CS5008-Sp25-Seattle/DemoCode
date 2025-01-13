#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define STRMAX 40

int main() {
    char s0[STRMAX] = "123456789012345678901234567890";
    char s1[STRMAX] = "abcdefghijklmno";
    char s2[STRMAX] = "ABCDE";

    printf("Using: %%10s\n");
    printf(">%s<\n", s0);
    printf(">%10s<\n", s1);
    printf(">%10s<\n", s2);
    printf("\n");

    printf("Using: %%-10s\n");
    printf(">%s<\n", s0);
    printf(">%-10s<\n", s1);
    printf(">%-10s<\n", s2);
    printf("\n");

    printf("Using: %%.10s\n");
    printf(">%s<\n", s0);
    printf(">%.10s<\n", s1);
    printf(">%.10s<\n", s2);
    printf("\n");

    printf("Using: %%15.10s\n");
    printf(">%s<\n", s0);
    printf(">%-15.10s<\n", s1);
    printf(">%-15.10s<\n", s2);
    printf("\n");

    printf("Using: %%-15.10s\n");
    printf(">%s<\n", s0);
    printf(">%-15.10s<\n", s1);
    printf(">%-15.10s<\n", s2);
    printf("\n");
}
