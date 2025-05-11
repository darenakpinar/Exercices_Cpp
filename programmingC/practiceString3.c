#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
   decoder(s) implements these rules:
    • when you see 'x', drop it and also skip the next character entirely.
    • when you see '+', drop the '+', then copy the next character *twice*.
    • otherwise copy the character once.
*/
char *decoder(const char *s) {
    // 1) First pass: figure out how big the output will be
    size_t out_len = 0;
    for (size_t i = 0; s[i]; ) {
        if (s[i] == 'x') {
            // skip 'x' and the next character (if any)
            i += 2;
        }
        else if (s[i] == '+') {
            // skip '+', but duplicate next character once (so two copies)
            if (s[i+1]) {
                out_len += 2;
                i += 2;
            } else {
                // '+' at end—nothing to duplicate, just skip it
                i += 1;
            }
        }
        else {
            // normal character
            out_len += 1;
            i += 1;
        }
    }

    // 2) allocate result
    char *out = malloc(out_len + 1);
    if (!out) {
        perror("malloc");
        exit(1);
    }

    // 3) Second pass: fill it
    char *q = out;
    for (size_t i = 0; s[i]; ) {
        if (s[i] == 'x') {
            // drop 'x' and the next char
            i += 2;
        }
        else if (s[i] == '+') {
            // drop '+', but duplicate next char
            if (s[i+1]) {
                *q++ = s[i+1];
                *q++ = s[i+1];
                i += 2;
            } else {
                // '+' at end: nothing to do
                i += 1;
            }
        }
        else {
            *q++ = s[i++];
        }
    }
    *q = '\0';  // terminate

    return out;
}

int main(void) {
    char encoded[] = "gxcxaxnxexxa+to";
    char *decoded = decoder(encoded);
    printf("%s\n", decoded);   // prints “gatto”
    free(decoded);
    return 0;
}
