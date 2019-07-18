#include <bits/stdc++.h>
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
const int N = 1e5 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt, w;
} edge[N];
struct E {
  int x, y, z;
  void input() {
    x = read(), y = read(), z = read();
  };
} e[N];
int n, m;
int tot, dfn[N];
bool vis[N], used[N];
bool dfs(int x, int lim) {
  vis[x] = used[x] = 1;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (edge[i].w <= lim) continue;
    if (vis[y] || !dfs(y, lim)) return 0;
  }
  vis[x] = 0;
  return 1;
}
bool check(int x) {
  memset(vis, 0, sizeof(vis));
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= n; i++)
    if (!used[i] && !dfs(i, x)) return 0;
  return 1;
}
vector<int> v;
queue<int> q;
int in[N];
void solve(int k) {
  for (int i = 1; i <= m; i++)
    if (e[i].z > k) in[e[i].y]++;
  for (int i = 1; i <= n; i++)
    if (!in[i]) q.push(i);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    dfn[x] = ++tot;
    for (int i = head[x]; i; i = edge[i].nxt) {
      if (edge[i].w <= k) continue;
      int y = edge[i].to;
      in[y]--;
      if (!in[y]) q.push(y);
    }
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) dfn[i] = ++tot;
  for (int i = 1; i <= m; i++)
    if (e[i].z <= k && dfn[e[i].x] > dfn[e[i].y]) v.push_back(i);
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    e[i].input();
    edge[i].to = e[i].y;
    edge[i].w = e[i].z;
    edge[i].nxt = head[e[i].x];
    head[e[i].x] = i;
  }
  int l = 0, r = 1e9, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  solve(ans);
  printf("%d %d\n", ans, (int)v.size());
  for (int x : v) printf("%d ", x);
}
