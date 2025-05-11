#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * drop(a,b) returns a freshly malloc'd string
 * containing all the characters of 'a' except those
 * that appear anywhere in 'b'.
 */
char *drop(const char *a, const char *b) {
    // 1) build a 256-slot lookup table of forbidden chars
    unsigned char forbidden[256] = { 0 };
    for (const unsigned char *p = (const unsigned char*)b; *p; ++p) {
        forbidden[*p] = 1;
    }

    // 2) count how many chars of 'a' survive
    size_t out_len = 0;
    for (const unsigned char *p = (const unsigned char*)a; *p; ++p) {
        if (!forbidden[*p]) {
            ++out_len;
        }
    }

    // 3) allocate output ( +1 for the '\0' )
    char *out = (char*)malloc(out_len + 1);
    if (!out) {
        perror("malloc");
        exit(1);
    }

    // 4) fill it
    char *q = out;
    for (const unsigned char *p = (const unsigned char*)a; *p; ++p) {
        if (!forbidden[*p]) {
            *q++ = *p;
        }
    }
    *q = '\0';            // terminate

    return out;
}

int main(void) {
    char a[] = "!p###la#!y!in#g!";
    char b[] = "!#";
    char *r = drop(a,b);
    printf("%s\n", r);   // prints "playing"
    free(r);
    return 0;
}

