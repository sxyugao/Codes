#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
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
const int N = 3e5 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int tot, dfn[N], low[N];
int scc, col[N];
int top, stk[N];
bool vis[N];
void tarjan(int x, int fa) {
  dfn[x] = low[x] = ++tot;
  stk[++top] = x;
  vis[x] = 1;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa) continue;
    if (!dfn[y]) {
      tarjan(y, x);
      low[x] = min(low[x], low[y]);
    } else {
      if (vis[y]) low[x] = min(low[x], dfn[y]);
    }
  }
  if (dfn[x] == low[x]) {
    int v = -1;
    scc++;
    while (x ^ v) {
      v = stk[top--];
      vis[v] = 0;
      col[v] = scc;
    }
  }
}
vector<int> v[N];
int d[N];
void dfs(int x, int fa) {
  d[x] = d[fa] + 1;
  for (int y : v[x])
    if (y != fa) dfs(y, x);
}
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i, 0);
  for (int x = 1; x <= n; x++) {
    for (int i = head[x]; i; i = edge[i].nxt) {
      int y = edge[i].to;
      if (col[x] ^ col[y]) v[col[x]].emplace_back(col[y]);
    }
  }
  dfs(1, 0);
  int p = 0;
  for (int i = 1; i <= scc; i++)
    if (d[i] > d[p]) p = i;
  dfs(p, 0);
  p = 0;
  for (int i = 1; i <= scc; i++)
    if (d[i] > d[p]) p = i;
  printf("%d", d[p] - 1);
}
