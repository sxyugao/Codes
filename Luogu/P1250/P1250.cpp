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
const int N = 3e4 + 5;
struct Data {
  int l, r, x;
  bool operator<(const Data &b) const {
    if (r != b.r) return r < b.r;
    return l < b.l;
  }
  void input() { l = read(), r = read(), x = read(); }
} a[N];
bool vis[N];
int main() {
  int m = read(), n = read(), ans = 0;
  for (int i = 1; i <= n; i++) a[i].input();
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = a[i].l; j <= a[i].r && a[i].x; j++)
      if (vis[j]) a[i].x--;
    if (!a[i].x) continue;
    for (int j = a[i].r; j >= a[i].l && a[i].x; j--)
      if (!vis[j]) {
        a[i].x--;
        vis[j] = 1;
        ans++;
      }
  }
  printf("%d", ans);
}