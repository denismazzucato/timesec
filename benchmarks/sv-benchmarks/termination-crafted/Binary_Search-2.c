/*
 * Date: 07/07/2015
 * Created by: Ton Chanh Le (chanhle@comp.nus.edu.sg)
 */

extern int __VERIFIER_nondet_int();

int binary_search(int i, int j)
{
  if (i>=j) return i;
  int mid = (i+j)/2;
  if (__VERIFIER_nondet_int()) 
    return binary_search(i,mid);
  return binary_search(mid+1,j);
}


int main() {
  int x = __VERIFIER_nondet_int();
  int y = __VERIFIER_nondet_int();
  //prevent overflows
  if(!(-1073741823<=x && x<=1073741823)) return 0;
  if(!(-1073741823<=y && y<=1073741823)) return 0;
  binary_search(x, y);
}
