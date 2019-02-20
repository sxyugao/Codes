#include <stdio.h>
const int P = 200907;
int pw(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = 1LL * ans * a % P;
    a = 1LL * a * a % P;
    n >>= 1;
  }
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c, k;
    scanf("%d%d%d%d", &a, &b, &c, &k);
    if (c - b == b - a)
      printf("%d\n", (int)((a + 1LL * (b - a) * (k - 1) % P) % P));
    else
      printf("%d\n", (int)(1LL * a * pw(b / a, k - 1) % P));
  }
}