#include <stdlib.h>
#include <alloca.h>

extern int __VERIFIER_nondet_int(void);

int main() {
    int* x1 = alloca(sizeof(int));
    int* x2 = alloca(sizeof(int));
    *x1 = __VERIFIER_nondet_int();
    *x2 = __VERIFIER_nondet_int();
    while (*x1 <= 10) {
        *x2 = 10;
        while (*x2 > 1) {
            *x2 = *x2 - 1;
        }
        *x1 = *x1 + 1;
    }
}
