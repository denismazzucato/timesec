/*
 * Program used in the experimental evaluation of the following paper.
 * 2010SAS - Alias,Darte,Feautrier,Gonnord, Multi-dimensional Rankings, Program Termination, and Complexity Bounds of Flowchart Programs
 *
 * Date: 2014
 * Author: Caterina Urban
 */

typedef enum {false, true} bool;

extern int __VERIFIER_nondet_int(void);

int main() {
    int i, j, k, tmp;
	i = __VERIFIER_nondet_int();
	j = __VERIFIER_nondet_int();
	k = __VERIFIER_nondet_int();
	tmp = __VERIFIER_nondet_int();
	while (i <= 100 && j <= k) {
		tmp = i;
		i = j;
		j = tmp + 1;
		k = k - 1;
	}
	// return 0;
}
