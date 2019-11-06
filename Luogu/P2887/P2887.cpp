#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define gc c = getchar()
int read() {
  int x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 2505;
struct Seg {
  int l, r;
  void input() { l = read(), r = read(); }
  bool operator<(const Seg &b) const {
    if (r ^ b.r) return r < b.r;
    return l < b.l;
  }
} a[N];
struct Data {
  int p, n;
  void input() { p = read(), n = read(); }
  bool operator<(const Data &b) const {
    return p < b.p;
  }
} b[N];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i].input();
  for (int i = 1; i <= m; i++) b[i].input();
  sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i].l <= b[j].p && b[j].p <= a[i].r && b[j].n) {
        b[j].n--;
        ans++;
        break;
      }
  printf("%d", ans);
}
