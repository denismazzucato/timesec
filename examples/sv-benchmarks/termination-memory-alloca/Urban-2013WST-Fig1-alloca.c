#include <stdlib.h>
#include <alloca.h>

extern int __VERIFIER_nondet_int(void);

int main() {
    int* x = alloca(sizeof(int));
    *x = __VERIFIER_nondet_int();
    while (*x <= 10) {
        if (*x > 6) {
            *x = *x + 2;
        }
    }
}
