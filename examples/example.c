
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

#define N 5
#define M 10
void overview() {
  x = __VERIFIER_nondet_int();
  _Static_assert(x <= N && x >= 0);
  while (x > 0) {
    x--;
    y = M;
    while (y > 0) {
      y--;
    }
    symbolic_counter--;
  }
}

void f(int r){
  while (r < 100) {
    r = r * r;
  }
}
