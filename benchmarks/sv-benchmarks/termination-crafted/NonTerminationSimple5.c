/*
 * Date: 2014-06-26
 * Author: leike@informatik.uni-freiburg.de
 */

typedef enum {false, true} bool;

extern int __VERIFIER_nondet_int(void);

int main()
{
	int x;
    x = __VERIFIER_nondet_int();
	while (x >= 0) {
		if (__VERIFIER_nondet_int() != 0) {
			x = x - 1;
		} else {
			x = x + 1;
		}
	}
	// return 0;
}
