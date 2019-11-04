#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
char buf[1 << 14], *p1 = buf, *p2 = buf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
const int N = 1e4 + 5;
const int M = 1e5 + 5;
const int K = 10;
int nedge, head[N];
struct Edge {
  int to, nxt, w;
} edge[M << 1];
void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int n, m, k, S, T, a[N], d[N][K << 1];
bool vis[N][K << 1];
inline void init() {
  nedge = 0;
  memset(d, 0x3f, sizeof(d));
  memset(vis, 0, sizeof(vis));
  memset(head, 0, sizeof(head));
}
struct Data {
  int x, y, z;
  bool operator<(const Data &b) const {
    return z > b.z;
  }
};
priority_queue<Data> q;
inline int Dijkstra(int S, int T) {
  int ans = 2e9;
  d[S][k + a[S]] = 0;
  q.push({S, k + a[S], 0});
  while (!q.empty()) {
    Data now = q.top();
    q.pop();
    if (now.x == T) ans = min(ans, now.z);
    if (vis[now.x][now.y]) continue;
    vis[now.x][now.y] = 1;
    for (int i = head[now.x]; i; i = edge[i].nxt) {
      int y = edge[i].to;
      int t = now.y + a[y];
      if (t < 0 || t > k * 2) continue;
      if (d[now.x][now.y] + edge[i].w < d[y][t]) {
        d[y][t] = d[now.x][now.y] + edge[i].w;
        q.push({y, t, d[y][t]});
      }
    }
  }
  if (ans == 2e9) ans = -1;
  return ans;
}
inline void solve() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++) a[i] = read() == 1 ? 1 : -1;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), z = read();
    add(x, y, z), add(y, x, z);
  }
  S = read(), T = read();
  printf("%d\n", Dijkstra(S, T));
}
int main() {
  for (int T = read(); T; T--) init(), solve();
}
