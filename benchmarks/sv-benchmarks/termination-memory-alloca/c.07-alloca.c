#include <stdlib.h>
#include <alloca.h>

extern int __VERIFIER_nondet_int(void);

int test_fun(int i, int j, int k, int tmp)
{
    int* i_ref = alloca(sizeof(int));
    int* j_ref = alloca(sizeof(int));
    int* k_ref = alloca(sizeof(int));
    int* tmp_ref = alloca(sizeof(int));
    int* c = alloca(sizeof(int));
    *i_ref = i;
    *j_ref = j;
    *k_ref = k;
    *tmp_ref = tmp;
    *c = 0;
    while ((*i_ref <= 100) && (*j_ref <= k) && (*k_ref > -2147483648)) {
        *tmp_ref = *i_ref;
        *i_ref = *j_ref;
        *j_ref = *tmp_ref + 1;
        *k_ref = *k_ref - 1;
    }
    return *c;
}

int main() {
  return test_fun(__VERIFIER_nondet_int(),__VERIFIER_nondet_int(),__VERIFIER_nondet_int(),__VERIFIER_nondet_int());
}
