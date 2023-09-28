#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 155;
int n, m, a, b;
bool mp[N][N];
int tot, dfn[N], low[N];
int cnt;
struct Edge {
  int a, b;
  bool operator<(const Edge &other) const {
    if (a == other.a) return b < other.b;
    return a < other.a;
  }
} e[N * N];
int min(int x, int y) { return x < y ? x : y; }
void dfs(int x, int fa) {
  dfn[x] = low[x] = ++tot;
  for (int y = 1; y <= n; ++y) {
    if (!mp[x][y]) continue;
    if (dfn[y] && y != fa) low[x] = min(low[x], dfn[y]);
    if (!dfn[y]) {
      dfs(y, x);
      low[x] = min(low[x], low[y]);
      if (low[y] > dfn[x]) {
        if (x > y) {
          int t = x;
          x = y;
          y = t;
        }
        e[cnt].a = x;
        e[cnt].b = y;
        ++cnt;
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    mp[a][b] = mp[b][a] = 1;
  }
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) dfs(i, 0);
  sort(e, e + cnt);
  for (int i = 0; i < cnt; ++i) printf("%d %d\n", e[i].a, e[i].b);
}