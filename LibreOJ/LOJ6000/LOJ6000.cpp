#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int S = 101, T = 102;
int nedge = 1, head[N], cur[N];
struct Edge {
  int to, nxt, w;
} edge[2 * N * N];
void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
  edge[++nedge].to = x;
  edge[nedge].w = 0;
  edge[nedge].nxt = head[y];
  head[y] = nedge;
}
int n, m, x, y, d[N];
bool bfs() {
  memset(d, 0, sizeof(d));
  queue<int> q;
  d[S] = 1;
  q.push(S);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = edge[i].nxt) {
      int y = edge[i].to;
      if (edge[i].w && !d[y]) {
        d[y] = d[x] + 1;
        q.push(y);
      }
    }
  }
  return d[T];
}
int dfs(int x, int flow) {
  if (x == T) return flow;
  int ret = 0;
  for (int i = cur[x]; i; i = edge[i].nxt) {
    cur[x] = i;
    int y = edge[i].to;
    if (edge[i].w && d[x] + 1 == d[y]) {
      int f = dfs(y, min(flow - ret, edge[i].w));
      if (f) {
        edge[i].w -= f;
        edge[i ^ 1].w += f;
        ret += f;
      } else {
        d[y] = -1;
      }
    }
  }
  return ret;
}
int dinic() {
  int ans = 0;
  while (bfs()) {
    memcpy(cur, head, sizeof(head));
    ans += dfs(S, 1e9);
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) add(S, i, 1);
  for (int i = m + 1; i <= n; i++) add(i, T, 1);
  while (~scanf("%d%d", &x, &y)) add(x, y, 1e9);
  printf("%d", dinic());
}