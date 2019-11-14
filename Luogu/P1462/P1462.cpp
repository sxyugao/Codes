#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
char buf[1 << 14], *p1 = buf, *p2 = buf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x;
}
const int N = 1e4 + 5;
const int M = 5e4 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt, w;
} edge[M << 1];
inline void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int n, m, hp, a[N];
long long d[N];
bool vis[N];
queue<int> q;
inline long long SPFA(int c) {
  for (int i = 2; i <= n; i++) d[i] = 1e18;
  q.push(1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    vis[x] = 0;
    for (int i = head[x]; i; i = edge[i].nxt) {
      int y = edge[i].to;
      if (a[y] > c) continue;
      if (d[x] + edge[i].w < d[y]) {
        d[y] = d[x] + edge[i].w;
        if (!vis[y]) q.push(y), vis[y] = 1;
      }
    }
  }
  return d[n];
}
int main() {
  n = read(), m = read(), hp = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  while (m--) {
    int x = read(), y = read(), z = read();
    add(x, y, z), add(y, x, z);
  }
  int l = max(a[1], a[n]), r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (SPFA(mid) <= hp) {
      r = mid - 1, ans = mid;
    } else {
      l = mid + 1;
    }
  }
  if (ans < 0) return puts("AFK"), 0;
  printf("%d", ans);
}
