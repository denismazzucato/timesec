#include <stdlib.h>
#include <alloca.h>

extern int __VERIFIER_nondet_int(void);

int main() {
    int* i = alloca(sizeof(int));
    int* j = alloca(sizeof(int));
    int* n = alloca(sizeof(int));
    *i = __VERIFIER_nondet_int();
    *j = __VERIFIER_nondet_int();
    *n = __VERIFIER_nondet_int();
    while (*i < *n) {
        *j = 0;
        while (*j <= *i) {
            *j = *j + 1;
        }
        *i = *i + 1;
    }
    return 0;
}
