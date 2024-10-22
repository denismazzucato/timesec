/*
 * Date: 2013-07-13
 * Author: leike@informatik.uni-freiburg.de
 *
 * Simple test case for the lexicographic template.
 * Has the lexicographic ranking function
 * f(x, y) = <x, y>
 *
 */

typedef enum {false, true} bool;

extern int __VERIFIER_nondet_int(void);

int main() {
	int x, y;
  x = __VERIFIER_nondet_int();
  y = __VERIFIER_nondet_int();
	while (x >= 0 && y >= 0) {
		y = y - 1;
		if (y < 0) {
			x = x - 1;
			y = __VERIFIER_nondet_int();
		}
	}
    // return 0;
}
