/*
 * Date: 2014-02-16
 * Author: heizmann@informatik.uni-freiburg.de
 *
 */

typedef enum {false, true} bool;

extern int __VERIFIER_nondet_int(void);

int main()
{
	int x = __VERIFIER_nondet_int();
	while (x >= 0) {
		x = x - 1;
	}
	// return 0;
}
