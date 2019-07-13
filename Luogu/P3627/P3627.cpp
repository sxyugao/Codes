#include <cstdio>
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
const int N = 5e5 + 5;
int nedge, head[N], h[N];
struct Edge {
  int to, nxt;
} edge[N], e[N];
void add(int x, int y) {
  e[++nedge].to = y;
  e[nedge].nxt = h[x];
  h[x] = nedge;
}
int a[N];
int tot, dfn[N], low[N];
bool vis[N];
int top, stk[N];
int scc, val[N], col[N];
void dfs(int x) {
  dfn[x] = low[x] = ++tot;
  vis[x] = 1;
  stk[++top] = x;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (!dfn[y]) {
      dfs(y);
      low[x] = min(low[x], low[y]);
    } else {
      if (vis[y]) low[x] = min(low[x], dfn[y]);
    }
  }
  if (low[x] == dfn[x]) {
    int y;
    scc++;
    do {
      y = stk[top--];
      col[y] = scc;
      vis[y] = 0;
      val[scc] += a[y];
    } while (x != y);
  }
}
int f[N], in[N];
queue<int> q;
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    edge[i].to = y;
    edge[i].nxt = head[x];
    head[x] = i;
  }
  for (int i = 1; i <= n; i++) a[i] = read();
  int S = read();
  dfs(S);
  for (int x = 1; x <= n; x++) {
    if (!col[x]) continue;
    for (int i = head[x]; i; i = edge[i].nxt) {
      int y = edge[i].to;
      if (col[x] != col[y]) {
        add(col[x], col[y]);
        in[col[y]]++;
      }
    }
  }
  f[col[S]] = val[col[S]];
  q.push(col[S]);
  vis[col[S]] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = h[x]; i; i = e[i].nxt) {
      int y = e[i].to;
      f[y] = max(f[x] + val[y], f[y]);
      in[y]--;
      if (!in[y]) q.push(y);
    }
  }
  int ans = 0;
  for (int num = read(); num; num--) ans = max(ans, f[col[read()]]);
  printf("%d", ans);
}
