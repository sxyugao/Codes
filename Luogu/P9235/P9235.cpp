#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
struct Edge {
  int x, y, w;
  bool operator<(const Edge &b) const { return w > b.w; }
};
int n, m, q;
vector<Edge> edge;
vector<Edge> g[N];
int f[N];
int find(int x) {
  if (f[x] == x) return x;
  return f[x] = find(f[x]);
}
int d[N], fa[20][N], mn[20][N];
void dfs(int x, int f) {
  d[x] = d[f] + 1;
  fa[0][x] = f;
  for (int i = 1; (1 << i) <= d[x]; ++i) {
    fa[i][x] = fa[i - 1][fa[i - 1][x]];
    mn[i][x] = min(mn[i - 1][x], mn[i - 1][fa[i - 1][x]]);
  }
  for (auto e : g[x]) {
    if (e.y == f) continue;
    mn[0][e.y] = e.w;
    dfs(e.y, x);
  }
}
int solve(int x, int y) {
  if (x == y) return 0;
  if (d[x] > d[y]) swap(x, y);
  int ans = 1e6;
  for (int i = 19; ~i; --i)
    if (d[fa[i][y]] >= d[x]) {
      ans = min(ans, mn[i][y]);
      y = fa[i][y];
    }
  if (x == y) return ans;
  for (int i = 19; ~i; --i) {
    if (fa[i][x] != fa[i][y]) {
      ans = min(ans, min(mn[i][x], mn[i][y]));
      x = fa[i][x];
      y = fa[i][y];
    }
  }
  return min(ans, min(mn[0][x], mn[0][y]));
}
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edge.push_back({u, v, w});
  }
  for (int i = 1; i <= n; ++i) f[i] = i;
  sort(edge.begin(), edge.end());
  for (auto e : edge) {
    int x = find(e.x), y = find(e.y);
    if (x != y) {
      f[x] = y;
      g[e.x].push_back({0, e.y, e.w});
      g[e.y].push_back({0, e.x, e.w});
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!d[i]) dfs(i, 0);
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (find(x) != find(y)) {
      cout << -1 << endl;
      continue;
    }
    cout << solve(x, y) << endl;
  }
}