
void example(int x, int y) {
  i = 0;
  while (i < 2) {
    i = i + __VERIFIER_nondet_int(1, 2);
  }
}

void faulty() {
  x = __VERIFIER_nondet_int();
  y = __VERIFIER_nondet_int();
  i = 0;
  while (i < 2 * x + y) {
    i = i + __VERIFIER_nondet_int(1, 2);
  }
}
