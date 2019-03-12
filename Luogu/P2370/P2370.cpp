#include <cstdio>
#include <cstring>
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
const int N = 1e3 + 5;
const int INF = 0x7fffffff;
struct Data {
  int v, w;
  void input() { v = read(), w = read(); }
} a[N];
int n, m, p, f[N];
bool check(int x) {
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    if (a[i].v > x) continue;
    for (int j = m; j >= a[i].v; j--) f[j] = max(f[j - a[i].v] + a[i].w, f[j]);
  }
  return f[m] >= p;
}
int main() {
  n = read(), p = read(), m = read();
  for (int i = 1; i <= n; i++) a[i].input();
  int l = 1, r = 1e9, ans = INF;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid, r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if (ans == INF) {
    puts("No Solution!");
  } else {
    printf("%d", ans);
  }
}