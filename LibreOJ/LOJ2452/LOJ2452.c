#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define chk(a, b) (((a) == '&' && (b) == '&') || ((a) == '1' && (b) == '0') || ((a) == '0' && (b) == '1'))
#define N 1000005
char s[N];
int n, f[3 * N], a[3 * N];
int main() {
  scanf("%d\n", &n), gets(s);
  a[1] = '&';
  for (int i = 1; i <= n; i++) a[i << 1] = s[i - 1], a[i << 1 | 1] = '&';
  n = n << 1 | 1;
  int mx = 0, p = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (mx > i) f[i] = min(mx - i, f[2 * p - i]);
    while (chk(a[i - f[i]], a[i + f[i]])) f[i]++;
    if (i + f[i] > mx) mx = i + f[i], p = i;
    ans += f[i] / 2;
  }
  printf("%lld", ans);
}
