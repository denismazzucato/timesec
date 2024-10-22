/*
 * Program from Fig.1 of
 * 2013CAV - Brockschmidt,Cook,Fuhs - Better termination proving through cooperation
 *
 * Date: 12.12.2013
 * Author: heizmann@informatik.uni-freiburg.de
 *
 */

typedef enum {false, true} bool;

extern int __VERIFIER_nondet_int(void);

int main() {
    int i, j, n;
    i = __VERIFIER_nondet_int();
    j = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();
    while (i < n) {
        j = 0;
        while (j <= i) {
            j = j + 1;
        }
        i = i + 1;
    }
    // return 0;
}
