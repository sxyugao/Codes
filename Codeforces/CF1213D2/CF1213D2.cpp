#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
inline char _gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
#define gc c = _gc()
int read() {
  int x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 2e5 + 5;
int a[N], cnt[N], num[N];
int main() {
  int n = read(), k = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1);
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    int step = 0;
    do {
      cnt[a[i]] += step;
      num[a[i]]++;
      if (num[a[i]] >= k && cnt[a[i]] < ans) ans = cnt[a[i]];
      a[i] >>= 1;
      step++;
    } while (a[i]);
    cnt[0] += step;
  }
  printf("%d", min(ans, cnt[0]));
}
