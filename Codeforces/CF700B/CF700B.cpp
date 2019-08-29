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
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int n, k, a[N];
long long ans;
void dfs(int x, int fa) {
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa) continue;
    dfs(y, x);
    a[x] += a[y];
    ans += min(a[y], k - a[y]);
  }
}
int main() {
  n = read(), k = read() << 1;
  for (int i = 1; i <= k; i++) a[read()] = 1;
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs(1, 0);
  printf("%lld", ans);
}
