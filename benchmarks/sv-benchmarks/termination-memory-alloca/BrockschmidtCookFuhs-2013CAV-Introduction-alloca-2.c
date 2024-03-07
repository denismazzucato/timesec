#include <stdlib.h>
#include <alloca.h>

extern int __VERIFIER_nondet_int(void);

int main() {
    int* x = alloca(sizeof(int));
    int* y = alloca(sizeof(int));
    *x = __VERIFIER_nondet_int();
    *y = 1;
    while (*x > 0) {
        *x = *x - *y;
        *y = *y + 1;
    }
    return 0;
}
