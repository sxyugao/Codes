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
const int N = 305;
inline int sqr(int x) { return x * x; }
int a[N];
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1);
  long long ans = sqr(a[n]);
  int l = 1, r = n;
  bool f = 1;
  while (l < r) {
    ans += sqr(a[l] - a[r]);
    if (f) r--;
    if (!f) l++;
    f ^= 1;
  }
  printf("%lld", ans);
}