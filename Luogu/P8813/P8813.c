#include <stdio.h>
int pw(long long a, int b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    if (ans > 1e9 || a > 1e9) return -1;
    a *= a;
    b >>= 1;
  }
  return ans;
}
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d", pw(a, b));
}
