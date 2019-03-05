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
int a[10005];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) a[i] = read();
  sort(a + 1, a + m + 1);
  int ans = max(a[1], n - a[m]);
  for (int i = 1; i <= m; i++) ans = max(ans, (a[i + 1] - a[i]) / 2);
  printf("%d", ans);
}