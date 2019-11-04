#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
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
const int N = 1e5 + 5;
const int M = 2e5 + 5;
const int K = 55;
struct Edge {
  int y, w;
};
vector<Edge> g1[N], g2[N];
int d[N];
bool vis[N];
struct Data {
  int x, y;
  bool operator<(const Data &b) const {
    return y > b.y;
  }
};
priority_queue<Data> q;
void Dijkstra() {
  q.push({1, 0});
  while (!q.empty()) {
    Data now = q.top();
    q.pop();
    if (vis[now.x]) continue;
    vis[now.x] = 1;
    for (Edge e : g1[now.x])
      if (d[now.x] + e.w < d[e.y]) {
        d[e.y] = d[now.x] + e.w;
        q.push({e.y, d[e.y]});
      }
  }
}
int n, m, k, P;
int f[N][K];
bool zero, used[N][K];
inline void init() {
  n = read(), m = read(), k = read(), P = read();
  for (int i = 1; i <= n; i++) g1[i].resize(0), g2[i].resize(0);
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), z = read();
    g1[x].emplace_back((Edge){y, z});
    g2[y].emplace_back((Edge){x, z});
  }
  for (int i = 2; i <= n; i++) d[i] = 1e9;
  for (int i = 1; i <= n; i++) vis[i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k + 1; j++) f[i][j] = -1, used[i][j] = 0;
}
inline void Add(int &x, int y) {
  x = x + y >= P ? x + y - P : x + y;
}
int dfs(int x, int dep) {
  if (used[x][dep]) return zero = 1, 0;
  if (~f[x][dep]) return f[x][dep];
  used[x][dep] = 1;
  int ans = 0;
  for (Edge e : g2[x])
    if (d[x] + dep - d[e.y] - e.w >= 0) {
      Add(ans, dfs(e.y, d[x] + dep - d[e.y] - e.w));
      if (zero) return 0;
    }
  used[x][dep] = 0;
  return f[x][dep] = ans;
}
inline void solve() {
  Dijkstra();
  int ans = 0;
  f[1][0] = 1;
  zero = 0;
  for (int i = 0; i <= k && !zero; i++) Add(ans, dfs(n, i));
  dfs(n, k + 1);
  if (zero) puts("-1");
  if (!zero) printf("%d\n", ans);
}
int main() {
  for (int T = read(); T; T--) init(), solve();
}
