#include <stdio.h>
int main() {
  int T, n, c, x;
  scanf("%d", &T);
  while (T--) {
    int cnt0 = 0, cnt1 = 0;
    scanf("%d%d", &n, &c);
    long long ans = 1LL * c * (c + 1) / 2 + c + 1;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      if (x & 1)
        ++cnt1;
      else
        ++cnt0;
      ans -= (x + 1 + 1) / 2;
      ans -= c - x + 1;
    }
    ans += 1LL * (cnt0 - 1) * cnt0 / 2;
    ans += 1LL * (cnt1 - 1) * cnt1 / 2;
    printf("%lld\n", ans + n);
  }
}