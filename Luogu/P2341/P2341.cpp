#include <cstdio>
#include <iostream>
using namespace std;
int n, m, ans, head[10005], x[50005], y[50005];
int cnt, num[10005], siz[10005], p[10005];
int top, stack[10005];
int tot, low[10005], dfn[10005];
bool f, vis[10005];
struct Edge {
  int p, nxt;
} e[50005];
void Tarjan(int k) {
  dfn[k] = low[k] = ++tot;
  stack[++top] = k;
  vis[k] = 1;
  int v;
  for (int i = head[k]; i; i = e[i].nxt) {
    v = e[i].p;
    if (!dfn[v]) {
      Tarjan(v);
      low[k] = min(low[k], low[v]);
    } else if (vis[v]) {
      low[k] = min(low[k], dfn[v]);
    }
  }
  if (dfn[k] == low[k]) {
    cnt++;
    do {
      v = stack[top--];
      vis[v] = 0;
      num[v] = cnt;
      siz[cnt]++;
    } while (k != v);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", x + i, y + i);
    e[i].p = y[i];
    e[i].nxt = head[x[i]];
    head[x[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) Tarjan(i);
  for (int i = 1; i <= m; i++)
    if (num[x[i]] != num[y[i]]) p[num[x[i]]]++;
  for (int i = 1; i <= cnt; i++)
    if (!p[i]) {
      if (f) return puts("0"), 0;
      ans = siz[i], f = 1;
    }
  printf("%d", ans);
}