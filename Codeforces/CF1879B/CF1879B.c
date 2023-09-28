#include <stdio.h>
int T, n, x, mina, minb;
long long suma, sumb, ans1, ans2;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    mina = minb = 2e9;
    suma = sumb = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      if (x < mina) mina = x;
      suma += x;
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      if (x < minb) minb = x;
      sumb += x;
    }
    ans1 = 1LL * mina * n + sumb;
    ans2 = 1LL * minb * n + suma;
    printf("%lld\n", ans1 < ans2 ? ans1 : ans2);
  }
}