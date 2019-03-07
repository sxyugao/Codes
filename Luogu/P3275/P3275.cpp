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
const int N = 1e5 + 5;
const int M = 1e5 + 5;
int num;
struct E {
  int opt, x, y;
} e[M];
struct Graph {
  int nedge, head[N];
  int in[N];
  struct Edge {
    int to, nxt, w;
  } edge[M << 1];
  void add(int x, int y, int z = 0) {
    edge[++nedge].to = y;
    edge[nedge].nxt = head[x];
    edge[nedge].w = z;
    head[x] = nedge;
    in[y]++;
  }
} g1, g2;
int tot, dfn[N], low[N];
int top, stk[N];
bool vis[N];
int scc, col[N];
void dfs(int x) {
  dfn[x] = low[x] = ++tot;
  vis[x] = 1;
  stk[++top] = x;
  for (int i = g1.head[x]; i; i = g1.edge[i].nxt) {
    int y = g1.edge[i].to;
    if (!dfn[y]) {
      dfs(y);
      low[x] = min(low[x], low[y]);
    } else {
      if (vis[y]) low[x] = min(low[x], dfn[y]);
    }
  }
  if (low[x] == dfn[x]) {
    scc++;
    int k;
    do {
      k = stk[top--];
      col[k] = scc;
      vis[k] = 0;
    } while (x != k);
  }
}
int f[N];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int opt = read(), a = read(), b = read();
    e[i] = {opt, a, b};
    switch (opt) {
      case 1:
        g1.add(a, b), g1.add(b, a);
        break;
      case 3:
        g1.add(b, a);
        break;
      case 5:
        g1.add(a, b);
        break;
      default:
        break;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) dfs(i);
  for (int x = 1; x <= n; x++)
    for (int j = g1.head[x]; j; j = g1.edge[j].nxt) {
      int y = g1.edge[j].to;
      if (col[x] != col[y]) g2.add(col[x], col[y], 0);
    }
  for (int i = 1; i <= m; i++) {
    if (e[i].opt & 1) continue;
    if (col[e[i].x] == col[e[i].y]) return puts("-1"), 0;
    if (e[i].opt == 2) g2.add(col[e[i].x], col[e[i].y], 1);
    if (e[i].opt == 4) g2.add(col[e[i].y], col[e[i].x], 1);
  }
  queue<int> q;
  for (int i = 1; i <= scc; i++)
    if (!g2.in[i]) {
      q.push(i);
      f[i] = 1;
    }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = g2.head[x]; i; i = g2.edge[i].nxt) {
      int y = g2.edge[i].to;
      f[y] = max(f[y], f[x] + g2.edge[i].w);
      g2.in[y]--;
      if (!g2.in[y]) q.push(y);
    }
  }
  for (int i = 1; i <= scc; i++)
    if (g2.in[i]) return puts("-1"), 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += f[col[i]];
  printf("%lld", ans);
}