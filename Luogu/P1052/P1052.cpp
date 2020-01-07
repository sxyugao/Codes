#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define gc c = getchar()
inline int read() {
  int x = 0;
  char gc;
  while (!isdigit(c)) gc;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x;
}
#undef gc
const int N = 105;
const int Mod = 2520;
int a[N], d[N], f[Mod * N];
bool stone[N * Mod];
int main() {
  int l = read();
  int s = read(), t = read(), n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) d[i] = (a[i] - a[i - 1]) % Mod;
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + d[i];
    stone[a[i]] = 1;
  }
  l = a[n];
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  for (int i = 1; i <= l + t; i++) {
    for (int j = s; j <= t; j++)
      if (i - j >= 0) f[i] = min(f[i], f[i - j]);
    f[i] += stone[i];
  }
  int ans = 1e9;
  for (int i = l; i < l + t; i++) ans = min(ans, f[i]);
  printf("%d", ans);
}