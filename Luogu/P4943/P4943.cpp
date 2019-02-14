#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
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
const int MAXN = 50005;
const int MAXM = 100005;
bool a[MAXN];
struct Edge {
  int to, nxt, w;
};
struct Graph {
  int nedge, head[MAXN];
  Edge edge[MAXM << 1];
  void add(int x, int y, int z) {
    edge[++nedge].to = y;
    edge[nedge].w = z;
    edge[nedge].nxt = head[x];
    head[x] = nedge;
  }
};
Graph g1, g2;
int n, m, k, d1[MAXN], d2[MAXN];
struct Data {
  int d, x;
  bool operator<(const Data &b) const { return d > b.d; }
};
bool vis[MAXN];
priority_queue<Data> q;
void Dijkstra(const Graph &g, int *d, int S) {
  memset(d, 0x3f, sizeof(int) * (n + 1));
  memset(vis, 0, sizeof(vis));
  while (!q.empty()) q.pop();
  d[S] = 0;
  q.push(Data{0, S});
  while (!q.empty()) {
    int x = q.top().x;
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (int i = g.head[x]; i; i = g.edge[i].nxt) {
      int y = g.edge[i].to;
      if (d[x] + g.edge[i].w < d[y]) {
        d[y] = d[x] + g.edge[i].w;
        if (!vis[y]) q.push(Data{d[y], y});
      }
    }
  }
}
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= k; i++) a[read()] = 1;
  while (m--) {
    int x = read(), y = read(), z = read();
    g1.add(x, y, z), g1.add(y, x, z);
    if (!(a[x] || a[y])) {
      g2.add(x, y, z), g2.add(y, x, z);
    }
  }
  int x = read(), y = read();
  Dijkstra(g1, d1, 1);
  Dijkstra(g2, d2, 1);
  int ans = min(max(d1[x], d2[y]), max(d1[y], d2[x]));
  Dijkstra(g1, d2, x);
  ans = min(ans, d1[x] + d2[y]);
  ans = min(ans, d1[y] + d2[y]);
  printf("%d", ans);
}