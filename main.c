#include <stdio.h>

void _(FILE* input) {
    static char c;
    while ((c = getc(input)) != EOF) {
        putchar(c);
    }
}

int main (int argc, char* argv[]) {
    if (argc == 1) {
        _(stdin);
    } else {
        FILE* fin;
        for (unsigned int i = 1; i < argc; i++) {
            if (argv[i][0] == '-' && argv[i][1] == '\0') {
                _(stdin);
            } else {
                fin = fopen(argv[i], "r");
                if (fin == NULL) {
                    fprintf(stderr, "ERROR: file \"%s\" can not be opened.\n", argv[i]);
                    return 1;
                } else {
                    _(fin);
                }
            }
        }
    }
    return 0;
}
